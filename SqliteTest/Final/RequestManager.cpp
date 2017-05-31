#include "RequestManager.h"
#include <iostream>
#include <string>
#include <string.h>
#include "Movie.h"
#include "User.h"
#include "Location.h"
#include "database.h"

using namespace std;

const int RequestManager::optionsAmount = 9;
const string RequestManager::options[] = {
	"/Register/",
	"/RecoverKey/",
	"/Order/",
	"/Cancel/",
	"/History/",
	"/Movies/",
	"/Movie/",
	"/Locations/",
	"/Location/",
};


bool RequestManager::parseOneParam(string stringToParse, string param, string &var){
	if (stringToParse.find(param + "=") != 0) return false;
	var = stringToParse.substr(param.length() + 1);
	return true;
};

bool  RequestManager::parseTwoParam(string stringToParse, string param1, string param2, string &var1, string &var2){
	if (stringToParse.find(param1 + "=") != 0) return false;

	int delimIndex = stringToParse.find("&");
	if (delimIndex == -1) return false;
	 
	var1 = stringToParse.substr(param1.length() + 1, delimIndex - (param1.length() +1));
	var2 = stringToParse.substr(delimIndex + param2.length() +1);

	return true;
};



void RequestManager::registerAccount(string username, string password){
	//Here user will be registered to the DB if doesn't exist, returns JSON:
	cout <<  "{\"key\":\"3x4mpl3k3y\",\"status\":\"success\"}";
};

string RequestManager::getKey(string username, string password){
	//Gets the key from the database for a user:
	return "3x4mple3k3y";
}

void RequestManager::recoverKey(string username, string password){
	//Here user will be checked and his key will be returned
	string key = getKey(username, password);

	cout << "{\"key\:\"" + key + "\",\"status\":\"success\"}";
}

void RequestManager::getHistory(string key){
	//Here user will be taken from the database using the key, his order history will be returned

	cout << "{\"Orders\":[{\"OrderID\:\"1\"}],\"status\":\"success\"}";
};

void RequestManager::orderTicket(string orderID, string key){

	cout <<  "Ticket Ordered " << orderID + ": " << key;
};

void RequestManager::cancelTicket(string ticketID,string key){

	cout << "Ticket canceled : " << ticketID;
}

void RequestManager::getMoviesList(){
	Database db;
	db.selectAllMoviesQuery();
};

void RequestManager::getLocationsList(){

	Database db;
	db.selectAllLocationsQuery();
	
};

void RequestManager::getMovieInfo(string movieID){

	Database db;
	db.selectMovie(movieID);
};

void RequestManager::getLocationInfo(string cityName){
	Database db;
	db.selectLocation(cityName);
};

void RequestManager::parse(const char* stringToParse){
	string  parsedString(stringToParse), 
	   	user,
		pass,
		key,
		orderID,
		ticketID,
		movieID,
		city,
		country,
		defaultResponse = "{\"status\":\"failure\",\"message\":\"Invalid request\"}"; //Default

	
	int option;
	bool found = false;
	for (int i = 0; i < RequestManager::optionsAmount; i++){
		option = i;
		int index = parsedString.find(options[i]);
		if (index == 0){ parsedString = parsedString.substr(options[i].length());found= true; break; }
	}
	
	if (found)

	switch (option){
	case REGISTER:

		if (parseTwoParam(parsedString, "username","password",user,pass))
			registerAccount(user, pass);
		break;

	case KEY:

		if (parseTwoParam(parsedString, "username", "password",user,pass))
			recoverKey(user, pass);
		break;

	case ORDER:

		if (parseTwoParam(parsedString, "orderID", "key",orderID,key))
			orderTicket(orderID,key);
		break;

	case CANCEL:

		if (parseTwoParam(parsedString, "ticketID", "key", ticketID, key));
			cancelTicket(ticketID,key);
		break;

	case HISTORY:

		if (parseOneParam(parsedString, "key",key))
			getHistory(key);
		break;

	case MOVIES:

		if (parsedString.length() == 0)
			getMoviesList();
		break;

	case MOVIE:

		if (parseOneParam(parsedString, "ID", movieID))
			getMovieInfo(movieID);
		break;

	case LOCATIONS:

		if (parsedString.length() == 0)
			getLocationsList();
		break;

	case LOCATION:
		//TODO
		if (parseOneParam(parsedString,"city",city)){
			getLocationInfo(city);

		}
		break;

	default:
		cout << defaultResponse;
	}
	
}
