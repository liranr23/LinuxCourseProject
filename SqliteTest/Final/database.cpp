#include "database.h"
#include <stdlib.h>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include "Movie.h"


using namespace std;

Database::Database(){
    errMsg = 0;
    data = "Callback function called";
    
    rc = sqlite3_open(FILENAME,&dbFile);

    if ( rc ){
        cout << "Can't open database: " <<  sqlite3_errmsg(dbFile);
    }

}

Database::~Database(){

    sqlite3_close(dbFile);
    
}