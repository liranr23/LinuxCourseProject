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
	 "ID	INTEGER	PRIMARY KEY	AUTOINCREMENT NOT NULL,"\
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
	 "(1,'Cars 3','Disney',2017,'Blindsided by a new generation of blazing-fast racers, the legendary Lightning McQueen (voice of Owen Wilson) is suddenly pushed out of the sport he loves in Cars 3, the third in the Disney/Pixar big screen franchise, and only the second franchise in Disney/Pixar history to get more than two big screen movies (Toy Story being the other)','http://www.wildaboutmovies.com/2017_movies/cars-3/')," \

	 "(2,'SPIDERMAN HOMECOMING','MARVEL',2017,'A young Peter Parker Spider-Man, who made his debut in Captain America: Civil War, begins to navigate his newfound identity as the web-slinging superhero in the rebooted SpiderMan film, SpiderMan Homecoming.Thrilled by his experience with the Avengers, Peter returns home, where he lives with his Aunt May, under the watchful eye of his new mentor Tony Stark, Peter tries to fall back into his normal daily routine – distracted by thoughts of proving himself to be more than just your friendly neighborhood Spider-Man – but when the Vulture emerges as a new villain, everything that Peter holds most important will be threatened.Tom Holland (The Impossible, The Lost City Of Z) steps into the SpiderMan suit that Andrew Garfield last wore, who stepped into the suit that Tobey Maguire wore.Spiderman Homecoming is a Marvel film, one of the only Marvel properties not owned by Disney.','http://www.wildaboutmovies.com/2017_movies/spiderman-homecoming/')," \

			 "(3,'Warcraft','MARVEL',2017,'The movie based on one of the most popular video games of all time, World Of Warcraft, will be released in theaters with the title Warcraft.Sam Raimi, the director of the first three Spiderman movies, was supposed to sit in the director’s chair for this movie but passed on it in order to film Oz, The Great And Powerful instead. The “Warcraft” universe is a rich fantasy setting that revolves around the epic conflict between the opposing forces of the Horde and the Alliance. Since its debut in 1994, the “World Of Warcraft” has developed a loyal following across the globe, with several bestselling, award-winning video games and a range of popular licensed products including novels, action figures, apparel, comic books, board games, and more. “World of Warcraft,” Blizzard Entertainment’s subscription-based massively multiplayer online role-playing game set in the Warcraft universe, is the most popular game of its kind in the world. Its most recent expansion, “Wrath of the Lich King,” is the fastest-selling PC game of all time, with more than 2.8 million copies sold in its first 24 hours of availability and more than 4 million in its first month..','http://www.wildaboutmovies.com/2016_movies/warcraft/')," \


	 "(4,'Godzilla','MARVEL',2014,'The world is beset by the appearance of monstrous creatures, but one of them may be the only one who can save humanity.','http://www.imdb.com/title/tt0831387/')," \

	 "(5,'THOR','DC',2014,'Marvel Thor: The Dark World, now on Blu-ray 3D Combo Pack, Blu-ray, DVD, Digital HD and Digital 3D, continues the big screen adventures of Thor, the Mighty Avenger, as he battles to save Earth and all the Nine Realms from a shadowy enemy that predates the universe itself. In the aftermath of Marvels Thor and Marvels The Avengers, Thor fights to restore order across the cosmos...but an ancient race led by the vengeful Malekith returns to plunge the universe back into darkness. Faced with an enemy that even Odin and Asgard cannot withstand, Thor must embark on his most perilous and personal journey yet, one that will reunite him with Jane Foster and force him to sacrifice everything to save us all.','http://marvel.com/movies/movie/182/thor_the_dark_world'); " \

	 "INSERT INTO LOCATIONS (ID,COUNTRY,CITY,ADDRESS) "  \
         "VALUES " \
	 "(1,'Israel','Tel Aviv','HaMasger 2')," \
	"(2,'Israel','Haifa','Gav yam 2')," \
	"(3,'Israel','Ashdod','Hapalmah 10')," \
	"(4,'USA','New York','50th street,1025')," \
	 "(5,'Israel','Beer Sheva','Mesada 10');"\

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
