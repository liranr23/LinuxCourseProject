#include "RequestManager.h"
#include "database.h"
#include <string>



using namespace std;

int main (int argc, char* argv[]){
    // RequestManager::parse("/Movies/");
    // RequestManager::parse("/Movies/ID=2");
    RequestManager::parse("/Movies/title=SPIDERMAN HOMECOMING");
    // RequestManager::parse("/Locations/");
    // RequestManager::parse("/Locations/city=Tel Aviv");
    // RequestManager::parse("/Locations/ID=2");
    // RequestManager::parse("/Locations/country=Israel");
    
    return 0;
}