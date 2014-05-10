#include "util.h"
#include "database_connection.h"
#include "toplist.h"

void toplist()
{
   int num_fields = 0, i = 1, iStatus = 0;
   char cQuery[300], cAuswahl;
   MYSQL_ROW ROW;
   ACCOUNT user;
   MYSQL_RES *topList = NULL;
   MYSQL *Connection = NULL;
   Connection = MySQLConnect();
   system("cls");
   sprintf(cQuery,
      "SELECT a.username, p.points, p.time FROM accounts a JOIN points p ON (a.id = p.userid) ORDER BY p.points DESC LIMIT 10");
   topList = QueryBuilder(Connection, cQuery);
   if (topList)
   {
      num_fields = mysql_num_fields(topList);

      printf("\n\n\n\t\tPlatzierung\tUsername\tPunkte\t\tZeit");
      while (ROW = mysql_fetch_row(topList))
      {
         printf("\n\t\t%5.i\t\t%s\t\t%s\t\t%s", i, ROW[0], ROW[1], ROW[2]);
         i++;
      }
   }
   mysql_free_result(topList);
   MySQLClose(Connection);

   printf("\n\n\nUm ins Menue zurueckzukommen bitte Enter druecken!");
   do
   {
      cAuswahl = _getch();
      iStatus = control(cAuswahl);
   } while (iStatus != 6);
   
   if (iStatus == 6) 
   {
      main();
   }

}