#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   //Prints the db's values on execution of queries
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}



int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else{
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE MOVIES("\
         "ID		INT 	PRIMARY KEY     NOT NULL,"\
         "TITLE         VARCHAR(50)    		NOT NULL,"\
         "PRODUCER      VARCHAR(50)    		NOT NULL,"\
         "YEAR          INT 			NOT NULL,"\
         "INFO		VARCHAR(200) 		NOT NULL,"\
         "LINK		VARCHAR(50) 		NOT NULL);"\
	 "CREATE TABLE LOCATIONS("\
         "ID		INT	PRIMARY KEY	NOT NULL,"\
         "COUNTRY       VARCHAR(50)		NOT NULL,"\
         "CITY      	VARCHAR(50)    		NOT NULL,"\
	 "ADDRESS	VARCHAR(50) 		NOT NULL);"\
	 "CREATE TABLE USERS("\
	 "KEY		VARCHAR(50) PRIMARY KEY NOT NULL,"\
	 "NAME		VARCHAR(50)		NOT NULL,"\
	 "PASSWORD	VARCHAR(50)		NOT NULL);"\
	 "CREATE TABLE ORDERS("\
	 "ORDERID	INTEGER	PRIMARY KEY	AUTOINCREMENT NOT NULL,"\
	 "MOVIEID	INT			NOT NULL,"\
	 "LOCATIONID	INT			NOT NULL,"\
	 "CANCELED	BIT	DEFAULT 0	NOT NULL,"\
	 "USERKEY	VARCHAR(50)		NOT NULL);";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}
