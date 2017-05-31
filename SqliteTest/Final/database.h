#include <sqlite3.h>
#include <string>

#include "Movie.h"

using namespace std; 

class Database{

    private:
    const char* FILENAME = "database.db";
    sqlite3* dbFile;
    char* errMsg;
    int rc;
    char* query;
    const char* data;

    public:

    Database();
    ~Database();

};