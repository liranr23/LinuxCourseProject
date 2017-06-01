#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <stdlib.h>
#include "Location.h"
#include "Movie.h"

using namespace std; 

class Database{

    private:
    const char* FILENAME = "database.db";
    sqlite3* dbFile;
    char* errMsg = 0;
    int rc;
    const char* data;


    string createKey(string,string);

    public:

    static int counter;
    static int selectCounter;

    Database();
    ~Database();

    static int countCallback(void*,int,char**,char**);


    static int moviesCallback(void*, int , char**, char**);
    static int locationsCallback(void*, int , char**, char**);
    static int keyCallback(void*, int , char**, char**);
    static int ordersCallback(void*, int , char** , char**);
    
    void selectAllMoviesQuery();
    void selectAllLocationsQuery();

    void selectMovieByID(string);
    void selectMovieByTitle(string);

    void selectLocationByCity(string);
    void selectLocationByCountry(string);
    void selectLocationByID(string);

    void selectKey(string,string);
    void createAccount(string,string);

    void selectOrdersByKey(string);
    void createOrder(string,string,string);

};

#endif