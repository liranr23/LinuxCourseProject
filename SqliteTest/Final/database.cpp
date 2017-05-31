#include "database.h"
#include <stdlib.h>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <list>
#include "Movie.h"


using namespace std;


int Database::counter = 0;
int Database::selectCounter = 0;

Database::Database(){    
    rc = sqlite3_open(FILENAME,&dbFile);

    if ( rc ){
        cout << "Can't open database: " <<  sqlite3_errmsg(dbFile) << endl;
    }
}
Database::~Database(){

    sqlite3_close(dbFile);
}


int Database::moviesCount(void *data , int argc, char** argv , char** movieCols){
    counter++;
    return 0;
}

int Database::moviesCallback(void *data, int argc, char **argv, char **movieCols){
    //for (int i = 0 ; i < argc ; i++) cout << argv[i];
    //cout << endl;
    string
        id = argv[0],
        title = argv[1],
        producer = argv[2],
        year = argv[3],
        info = argv[4],
        imdb = argv[5];
    Movie movie(id,title,producer,year,info,imdb);
    cout << movie.ToJson();
    
    if (++selectCounter != counter) cout << ",";
    //Database::movies.push_back(movie);
    return 0;
};

string Database::selectAllMoviesQuery(){
    
    counter = selectCounter = 0;
    rc = sqlite3_exec(dbFile, "SELECT * FROM MOVIES", moviesCount, (void*)data, &errMsg);
    cout << "{\"status\":\"success\",\"movies\":[";
    rc = sqlite3_exec(dbFile, "SELECT * FROM MOVIES", moviesCallback, (void*)data, &errMsg);
    cout << "]}";
    if( rc != SQLITE_OK ) sqlite3_free(errMsg);

    return "" ;

};