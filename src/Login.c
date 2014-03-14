#include "util.h"
#include "database_connection.h"
#include "login.h"

int login(void)
{
    int authentifactionStatus=0, i=0;
    char cNickname[20], cPassword[28];

    do
    {
        /* Ausgabe fuer Login */
        printf("\t\tL O G I N\n");
        printf("\t\t= = = = =\n\n");
        if(authentifactionStatus==0 && i!=0) {
            printf("\t========================================\n");
            printf("\t= Fehler! Dieser User existiert nicht. =\n");
            printf("\t========================================\n\n\n");
        } else if( authentifactionStatus == 1) {
            printf("\t=========================\n");
            printf("\t= Fehler! Falsches Passwort. =\n");
            printf("\t=========================\n\n\n");
        }
        system("cls");
        fflush(stdin);
        printf("\tNickname: ");
        scanf("%s", &cNickname);
        fflush(stdin);
        printf("\tPassword: ");
        scanf("%s", &cPassword);
        fflush(stdin);
        authentifactionStatus = authentificationStatus(cNickname, cPassword);
        i++;
    } while(authentifactionStatus==0 || authentifactionStatus==1 || i<5);
    return authentifactionStatus;
}

int authentificationStatus( char cNickname, char cPassword )
{
    int num_fields=0;
	char cQuery[300];
    MYSQL_RES *username=NULL, *passwordcheck=NULL;
    MYSQL *Connection = MySQLConnect ();

    sprintf(cQuery, "SELECT id FROM useraccounts WHERE nickname = '%s';",
            cNickname );
    username = QueryBuilder (Connection, cQuery);
    if( username ) {
        num_fields = mysql_num_fields(username);
        if(num_fields==0) {
            mysql_free_result(username);
            MySQLClose (Connection);
            return 0;
        }
        mysql_free_result(username);
     }
    sprintf(
     cQuery,
     "SELECT id FROM useraccounts WHERE nickname ='%s' AND password=MD5('%s');",
     cNickname,
     cPassword
    );
    passwordcheck = QueryBuilder(Connection, cQuery);
    if(passwordcheck) {
        num_fields = mysql_num_fields(passwordcheck);
        if(num_fields==0) {
            mysql_free_result(passwordcheck);
            MySQLClose (Connection);
            return 1;
        } else {
            mysql_free_result(passwordcheck);
            MySQLClose (Connection);
            return 2;
        }
    }
    MySQLClose (Connection);
    return 0;
}
