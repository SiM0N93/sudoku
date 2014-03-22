#include "util.h"
#include "database_connection.h"
#include "login.h"

int login(void)
{
    int iStatus=0, i=0;
    char cNickname[20], cPassword[28];

    do
    {
        system("cls");
        printf("\tL O G I N\n");
        printf("\t= = = = =\n\n");
        if(iStatus==0 && i!=0) {
            printf("\t========================================\n");
            printf("\t==  Error! The user does not exsist.  ==\n");
            printf("\t========================================\n\n\n");
        } else if( iStatus == 1) {
            printf("\t=========================\n");
            printf("\t= Error! Wrong password =\n");
            printf("\t=========================\n\n\n");
        }
        printf("\tUsername: ");
        scanf("%s", &cNickname);
        fflush(stdin);
        printf("\tPassword: ");
        scanf("%s", &cPassword);
        fflush(stdin);
        iStatus = authentificationStatus(cNickname, cPassword);
        i++;
    } while( iStatus==0 || iStatus==1 || i<5);
    return iStatus;
}

int authentificationStatus( char cNickname[20], char cPassword[28] )
{
    int num_fields=0,i=0;
	 char cQuery[300];
    MYSQL_RES *username=NULL, *passwordcheck=NULL;
    MYSQL *Connection = NULL;
	 MYSQL_ROW ROW = NULL; 
	 Connection = MySQLConnect ();
    sprintf(cQuery, "SELECT id FROM accounts WHERE username = '%s';",
            cNickname );
    username = QueryBuilder (Connection, cQuery);

    if( username ) {
		 num_fields = mysql_num_rows(username);
		 if(num_fields == 0) {
			 printf("1");
			 getchar();
            mysql_free_result(username);
            MySQLClose (Connection);
            return 0;
        }
		  num_fields = mysql_num_fields(username); 

		 sprintf(
		  cQuery,
		  "SELECT id FROM accounts WHERE username ='%s' AND password=MD5('%s');",
		  cNickname,
		  cPassword
		 );
		 num_fields = 0;
		 passwordcheck = QueryBuilder(Connection, cQuery);
		 if( passwordcheck ) {
			  num_fields = mysql_num_rows(passwordcheck);
			  if(num_fields == 0) {
					mysql_free_result(passwordcheck);
					MySQLClose (Connection);
					return 1;
			  } else {
					mysql_free_result(passwordcheck);
					MySQLClose (Connection);
					return 2;
			  }
		 }
	 }
    MySQLClose (Connection);
    return 0;
}
