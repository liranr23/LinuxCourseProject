#include "database.h"
#include <stdlib.h>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <list>
#include "Movie.h"


using namespace std;

Database::Database(){    
    rc = sqlite3_open(FILENAME,&dbFile);

    if ( rc ){
        cout << "Can't open database: " <<  sqlite3_errmsg(dbFile) << endl;
    }
}
Database::~Database(){

    sqlite3_close(dbFile);
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

    cout << Movie(id,title,producer,year,info,imdb).ToJson();
    return 0;
};

string Database::selectAllMoviesQuery(){
    //cout <<  query.c_str() << endl;
    rc = sqlite3_exec(dbFile, "SELECT * FROM MOVIES", moviesCallback, (void*)data, &errMsg);

    if( rc != SQLITE_OK ) sqlite3_free(errMsg);

    return "" ;

};