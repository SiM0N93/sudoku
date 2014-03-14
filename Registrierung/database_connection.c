#include "util.h"
#include "database_connection.h"
#include "register.h"


MYSQL_RES *QueryBuilder( MYSQL* Connection, char cQuery )
{
    if( mysql_query( Connection, cQuery ) )
    {
        output( mysql_error( Connection ), DEBUG );
        return 0;
    }
    return mysql_store_result( Connection );
}

MYSQL* MySQLConnect(void)
{
    MYSQL *Connection = NULL;

    if( !( Connection = mysql_init( NULL ) ) )
    {
            output( mysql_error( Connection ), DEBUG );
            return NULL;
    }

    if( !( mysql_real_connect( Connection, DB_HOST, DB_USER, DB_PASSWORD,
                               DB_DATABASE, DB_PORT, NULL, 0 ) ) )
    {
            output( mysql_error( Connection ), DEBUG );
            return;
    }
    return Connection;
}

void MySQLClose(MYSQL *Connection)
{
    mysql_close(Connection);
    return;
}
