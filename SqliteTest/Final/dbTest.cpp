#include "database.h"
#include <iostream>
#include <string>
#include "Movie.h"


using namespace std;

int main (int argc, char* argv[]){
    Database db;
    db.selectQuery("SELECT * FROM MOVIES");

    return 0;
}