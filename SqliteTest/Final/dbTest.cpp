#include "RequestManager.h"

using namespace std;

int main (int argc, char* argv[]){
    RequestManager::parse("/Movies/");
    // RequestManager::parse("/Movies/ID=2");
    // RequestManager::parse("/Locations/");
    // RequestManager::parse("/Locations/city=Tel Aviv");
    // RequestManager::parse("/Locations/ID=2");
    // RequestManager::parse("/Locations/country=Israel");
    
    return 0;
}