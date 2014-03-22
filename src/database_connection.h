#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <my_global.h>
#include <mysql.h>

/* Define database connection settings */
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASSWORD ""
#define DB_DATABASE "sudoku"
#define DB_PORT 0

MYSQL_RES *QueryBuilder( MYSQL* Connection, char* cQuery );
MYSQL* MySQLConnect(void);
void MySQLClose(MYSQL* Connection);

#endif // DATABASE_CONNECTION_H