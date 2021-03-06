#include "util.h"
#include "database_connection.h"
#include "login.h"

ACCOUNT login(void)
{
    int iStatus=0, i=0;
    char cNickname[20], cPassword[28]="", c=' ';
    ACCOUNT userAccount;

    do
    {
        system("cls");
        printf("L O G I N\n");
        printf("= = = = =\n\n");
        if(iStatus==0 && i!=0) {
            printf("========================================\n");
            printf("==  Error! The user does not exsist.  ==\n");
            printf("========================================\n\n\n");
				strcpy(cPassword, "");
        } else if( iStatus == 1) {
            printf("=========================\n");
            printf("= Error! Wrong password =\n");
            printf("=========================\n\n\n");
				strcpy(cPassword, "");
        }
        printf("Username: ");
        scanf("%s", &cNickname);
        fflush(stdin);
		  printf("\nPassword: ");
        GetPassword( cPassword );
        iStatus = authentificationStatus(cNickname, cPassword);
        i++;
    } while( iStatus!=2 && i<5);
    if(iStatus==2) {
        userAccount = getUser(cNickname, cPassword);
    }
    return userAccount;
}

int authentificationStatus( char cNickname[], char cPassword[] )
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

ACCOUNT getUser(char cNickname[], char cPassword[])
{
    int num_fields=0,i=0, arraysize=0, width=0, height=0;
    char cQuery[300];
    MYSQL_ROW ROW;
    ACCOUNT user;
    MYSQL_RES *userEntity=NULL;
    MYSQL *Connection = NULL;
    Connection = MySQLConnect ();
    sprintf(cQuery,
            "SELECT first_name, last_name, username, window_width, window_height FROM accounts WHERE username ='%s' AND password=MD5('%s');",
            cNickname,
            cPassword
           );
    userEntity = QueryBuilder (Connection, cQuery);
    if(userEntity )
    {
        ROW = mysql_fetch_row( userEntity );
        if( ROW )
        {
            arraysize = sizeof(ROW) / sizeof(char);
            if( arraysize == 4 )
            {
                strcpy(user.FirstName, ROW[0]);
                strcpy(user.LastName, ROW[1]);
                strcpy(user.UserName, ROW[2]);
					 user.WindowWidth = atoi( ROW[3] );
					 user.WindowHeight = atoi( ROW[4] );
            } else {
                DEBUG_Log("Database didnt select [5] rows.");
            }
        }
    }
    mysql_free_result(userEntity);
    MySQLClose (Connection);
    return user;
}
