/* ============================================================================
* Autoren:         Michael Schneider
*                  Dario Tilgner
* Klasse:          FA13
* Uebung:          Sudoku - Spieler Registrierung
* Dateiname:       Registrierung.c
* Datum:           13.03.2014
*
* Beschreibung:    Es lassen sich Spieler fuer das Spiel Sudoku registrieren
*
* ============================================================================
*/

#include "util.h"
#include "register.h"
#include "database_connection.h"



/* ============================================================================
* Funktion:        registrierung
* Input:           -
* Output:          -
*
* Beschreibung:    Logik fuer komplette Registrierung eines Users
* ============================================================================
*/
void registrierung(void)
{
    MYSQL_RES *result = NULL;
    char cVorname[25], cNachname[25], cNickname[20], cPasswort[28], cQuery[300];
    MYSQL *Connection = MySQLConnect ();

    /* Ausgabe fuer Registrierungsinfos */
    printf("             R E G I S T R I E R U N G\n");
    printf("            = = = = = = = = = = = = = =\n\n\n");

    /* Leeren des Eingabespeichers */
    fflush(stdin);

    /* Einlesen der verschiedenen Werte */
    printf("\n\nFirst name: ");
    scanf("%s", &cVorname);
    fflush(stdin);
    printf("\nLast name: ");
    scanf("%s", &cNachname);
    fflush(stdin);
    printf("\nUsername: ");
    scanf("%s", &cNickname);
    fflush(stdin);
    printf("\nPassword: ");
    scanf("%s", &cPasswort);
    fflush(stdin);

    /* Query festlegen */
    sprintf(
     cQuery,
     "INSERT INTO accounts VALUES (NULL, '%s', '%s', '%s', MD5('%s'))",
     cVorname,
     cNachname,
     cNickname,
     cPasswort
    );

    /* SQL Anfrage schicken */
    result = QueryBuilder (Connection, cQuery);

    /* Speicher freigeben und Verbindung beenden */
    mysql_free_result(result);

    /* Ausgabe bei Erfolg */
    printf("\n\nThank you for your registration.\n");
    printf("Your account has been created, please press a key to continue.\n\n");
    MySQLClose (Connection);
	 getchar();
    return;
}