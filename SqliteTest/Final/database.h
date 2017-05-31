#include <sqlite3.h>
#include <string>
#include <list>
#include "Movie.h"

using namespace std; 

class Database{

    private:
    const char* FILENAME = "database.db";
    sqlite3* dbFile;
    char* errMsg = 0;
    int rc;
    const char* data;

    public:

    Database();
    ~Database();

    static int countCallback(void*,int,char**,char**);


    static int moviesCallback(void*, int , char**, char**);
    static int locationsCallback(void*, int , char**, char**);

    void selectAllMoviesQuery();
    void selectAllLocationsQuery();

    void selectMovieByID(string);
    void selectMovieByTitle(string);

    void selectLocationByCity(string);
    void selectLocationByCountry(string);
    void selectLocationByID(string);

    static int counter;
    static int selectCounter;
    //static list<Movie> movies;
};