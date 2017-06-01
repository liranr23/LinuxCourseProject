#include "RequestManager.h"

using namespace std;

const int RequestManager::optionsAmount = 7;
const string RequestManager::options[] = {
	"/Register/",
	"/RecoverKey/",
	"/Order/",
	"/Cancel/",
	"/History/",
	"/Movies/",
	"/Locations/",
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
	var2 = stringToParse.substr(delimIndex + param2.length() +2);

	return true;
};



void RequestManager::registerAccount(string username, string password){
	//User will be registered to the DB if doesn't exist, outputs JSON:
	Database db;
	db.createAccount(username,password);
};

void RequestManager::recoverKey(string username, string password){
	//User will be checked and his key will be returned
	Database db;
	db.selectKey(username,password);
}

void RequestManager::getHistory(string key){
	//User will be taken from the database using the key, his order history will be returned
	Database db;
	db.selectOrdersByKey(key);
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

void RequestManager::getMovieInfo(string param,int opt){

	Database db;
	switch(opt){
		case BY_ID:
			db.selectMovieByID(param);
			break;
		case BY_TITLE:
			db.selectMovieByTitle(param);
			break;

		default:
			cout << "{\"status\":\"failure\",\"message\":\"Invalid request\"}";
	}
};

void RequestManager::getLocationInfo(string param,int opt){
	Database db;
	switch(opt){
		case BY_CITY:
			db.selectLocationByCity(param);
			break;
		case BY_COUNTRY:
			db.selectLocationByCountry(param);
			break;
		case BY_ID:
			db.selectLocationByID(param);
			break;
		default:
			cout << "{\"status\":\"failure\",\"message\":\"Invalid request\"}";
	}
};

void RequestManager::parse(const char* stringToParse){
	string  parsedString(stringToParse), 
	   	user,
		pass,
		key,
		orderID,
		ticketID,
		movieID,
		movieName,
		locationID,
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
	
	if (!found) {
		cout<< defaultResponse;
		return;
	}

	switch (option){
	case REGISTER:

		if (parseTwoParam(parsedString, "username","password",user,pass))
			registerAccount(user, pass);
		else cout << defaultResponse;
		break;

	case KEY:

		if (parseTwoParam(parsedString, "username", "password",user,pass))
			recoverKey(user, pass);
		else cout << defaultResponse;
		break;

	case ORDER:

		if (parseTwoParam(parsedString, "orderID", "key",orderID,key))
			orderTicket(orderID,key);
		else cout << defaultResponse;
		break;

	case CANCEL:

		if (parseTwoParam(parsedString, "ticketID", "key", ticketID, key))
			cancelTicket(ticketID,key);
		else cout << defaultResponse;

		break;

	case HISTORY:

		if (parseOneParam(parsedString, "key",key))
			getHistory(key);
		else cout << defaultResponse;

		break;


	case MOVIES:

		if (parsedString.length() == 0)
			getMoviesList();
		else if (parseOneParam(parsedString, "ID", movieID))
			getMovieInfo(movieID,BY_ID);
		else if (parseOneParam(parsedString, "title",movieName))
			getMovieInfo(movieName,BY_TITLE);
		else cout << defaultResponse;
		break;


	case LOCATIONS:
		//TODO
		if (parsedString.length() == 0)
			getLocationsList();
		else if (parseOneParam(parsedString,"city",city))
			getLocationInfo(city,BY_CITY);
		else if(parseOneParam(parsedString,"country",country))
			getLocationInfo(country,BY_COUNTRY);
		else if(parseOneParam(parsedString,"ID",locationID))
			getLocationInfo(locationID,BY_ID);
		else cout << defaultResponse;
		break;

	default:
		cout << defaultResponse;
	}
	
	
}
