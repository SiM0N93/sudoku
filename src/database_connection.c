#include "util.h"
#include "database_connection.h"
#include "register.h"


MYSQL_RES *QueryBuilder( MYSQL* Connection, char* cQuery )
{
    char* Error="";
    if( mysql_query( Connection, cQuery ) )
    {
        strcpy( Error, mysql_error( Connection ) );
        DEBUG_Log( Error );
        return 0;
    }
    return mysql_store_result( Connection );
}

MYSQL* MySQLConnect(void)
{
    char* Error="";
    MYSQL *Connection = NULL;

    if( !( Connection = mysql_init( NULL ) ) )
    {
        strcpy( Error, mysql_error( Connection ) );
        DEBUG_Log( Error );
        return NULL;
    }

    if( !( mysql_real_connect( Connection, DB_HOST, DB_USER, DB_PASSWORD,
                               DB_DATABASE, DB_PORT, NULL, 0 ) ) )
    {
        strcpy( Error, mysql_error( Connection ) );
        DEBUG_Log( Error );
        return Connection;
    }
    return Connection;
}

void MySQLClose(MYSQL *Connection)
{
    mysql_close(Connection);
    return;
}
