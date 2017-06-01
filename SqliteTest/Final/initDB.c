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
   rc = sqlite3_open("database.db", &db);
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
	 "USERKEY	VARCHAR(50)		NOT NULL);"\
	 "INSERT INTO USERS (KEY,NAME,PASSWORD) "  \
         "VALUES " \
	 "('WO1V3RK3YDCBA4321','WO1V3R','1234ABCD')," \
	 "('L1R4NK3Y22992332','LIRANR23','23329922')," \
	 "('15483M387654321','ISABEME','12345678')," \
	 "('4L3X3YGFE9090','ALEXEY','0909EFG'); " \

	 "INSERT INTO MOVIES (ID,TITLE,PRODUCER,YEAR,INFO,LINK) "  \
         "VALUES " \
	 "(1,'THOR','MARVEL',2015,'A MOVIE ABOUT SOMEONE WITH A HAMMER','thor.io')," \
	 "(2,'SPIDERMAN HOMECOMING','MARVEL',2017,'A MOVIE ABOUT SPIDERMAN JUST WITH A NEW ACTOR','SMHC.io')," \
	 "(3,'THE DARK KNIGHT','DC',2014,'A MOVIE ABOUT SOMEONE WITH MONEY AND TIME','BATMAN.io'); " \

	 "INSERT INTO LOCATIONS (ID,COUNTRY,CITY,ADDRESS) "  \
         "VALUES " \
	 "(1,'Israel','Tel Aviv','HaMasger 2')," \
	 "(2,'Israel','Beer Sheva','Mesada 10');"\

	 "INSERT INTO ORDERS (MOVIEID,LOCATIONID,USERKEY) "  \
         "VALUES " \
	 "(1,1,'WO1V3RK3YDCBA4321')," \
	 "(2,2,'WO1V3RK3YDCBA4321');";

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
