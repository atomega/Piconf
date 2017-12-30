#include</usr/include/postgresql/libpq-fe.h>
#include <stdio.h>
#include <stdlib.h>
#include "dbcomm.h"


void do_exit(PGconn *conn, PGresult *res) {
    
    fprintf(stderr, "%s\n", PQerrorMessage(conn));    

    PQclear(res);
    PQfinish(conn);    
    
    exit(1);
}



void executeSqlCmd( PGconn *conn, char *CmdString)
{
	PGresult * result;  
	result = PQexec(conn, CmdString);
 
 	if (PQresultStatus(result) != PGRES_COMMAND_OK) 
	{
        do_exit(conn, result); 
   } 
	
    PQclear(result);    
}


void testDb() {
    
PGconn *conn = PQconnectdb(DB);

   if (PQstatus(conn) == CONNECTION_BAD) 
	{     
     	fprintf(stderr, "Connection to database failed: %s\n",
      PQerrorMessage(conn));
		exit(1); 
   }
 
	 executeSqlCmd(conn,"DROP TABLE IF EXISTS Cars"); 
	 executeSqlCmd(conn,"CREATE TABLE Cars(Id INTEGER PRIMARY KEY, Name VARCHAR(20), Price INT)"); 
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(1,'Audi',52642)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(2,'Mercedes',57127)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(3,'Skoda',9000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(4,'Volvo',29000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(5,'Bentley',350000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(6,'Citroen',21000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(7,'Hummer',41400)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(8,'Volkswagen',21600)");
        

    printf("\naccomplisher succesfully\n"); 
}

/*
int main() {
    
PGconn *conn = PQconnectdb(DB);

   if (PQstatus(conn) == CONNECTION_BAD) 
	{     
     	fprintf(stderr, "Connection to database failed: %s\n",
      PQerrorMessage(conn));
		exit(1); 
   }
 
	 executeSqlCmd(conn,"DROP TABLE IF EXISTS Cars"); 
	 executeSqlCmd(conn,"CREATE TABLE Cars(Id INTEGER PRIMARY KEY, Name VARCHAR(20), Price INT)"); 
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(1,'Audi',52642)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(2,'Mercedes',57127)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(3,'Skoda',9000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(4,'Volvo',29000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(5,'Bentley',350000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(6,'Citroen',21000)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(7,'Hummer',41400)");
    executeSqlCmd(conn, "INSERT INTO Cars VALUES(8,'Volkswagen',21600)");
        

    printf("\naccomplisher succesfully\n"); 
	return 0; 
	exit(1); 
}
*/
