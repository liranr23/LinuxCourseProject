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
    static int moviesCallback(void*, int , char**, char**);
    static int moviesCount(void*,int,char**,char**);
    string selectAllMoviesQuery();
    static int counter;
    static int selectCounter;
    //static list<Movie> movies;
};