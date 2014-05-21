#include "../util.h"
#include "control.h"

/*
*  Funktionsname:	control
*  Input:         -
*  Output:        int iRueckgabe
*
*  Beschreibung:  Prüft ob Eingabe bzw. Taste die gedrückt wurde eine Zahl oder eine Pfeiltaste ist.
*                 Bei Pfeiltasten wird jeweils ein anderer Zahlenwert zurückgegeben. Für eine Zahl nur einer. 
*/
int control(void) {
	int iRueckgabe = 0;
	char cAuswahl = _getch( );
	/* Pfeiltasten abfangen
	*	iRueckgabe gibt zurück je nach Sonderzeichen zurück.
	*	LINKS	   -	1
	*	HOCH	   -	2
	*	RUNTER	-	3
	*	RECHTS	-	4
	*
	*  Zahlen abfangen
	*	iRueckgabe gibt zurück ob Eingabe eine Zahl ist.
	*	ZAHL	-	5
   *
   *  Enter abfangen
   *  iRueckgabe gibt zurückt ob Eingabe Enter ist.
   *  ENTER -  13
	*/
   if (cAuswahl == 77)
   {
      iRueckgabe = 4;
   }
   else if (cAuswahl == 75)
   {
      iRueckgabe = 1;
   }
   else if (cAuswahl == 80)
   {
      iRueckgabe = 3;
   }
   else if (cAuswahl == 72)
   {
      iRueckgabe = 2;
   }
   else if (cAuswahl == 48 || 
				cAuswahl == 49 || 
				cAuswahl == 50 || 
				cAuswahl == 51 || 
				cAuswahl == 52 || 
				cAuswahl == 53 || 
				cAuswahl == 54 || 
				cAuswahl == 55 || 
				cAuswahl == 56 || 
				cAuswahl == 57
			  )
   {
      iRueckgabe = 5;
   }
   else if (cAuswahl == 13)
   {
      iRueckgabe = 6;
   }
	return iRueckgabe;
}

