#include "RequestManager.h"
#include <iostream>
#include <string>
#include <string.h>
#include "Movie.h"

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



string RequestManager::registerAccount(string username, string password){
	//Here user will be registered to the DB if doesn't exist, returns JSON:
	return "{\"key\":\"3x4mpl3k3y\",\"status\":\"success\"}";
};

string RequestManager::getKey(string username, string password){
	//Gets the key from the database for a user:
	return "3x4mple3k3y";
}

string RequestManager::recoverKey(string username, string password){
	//Here user will be checked and his key will be returned
	string key = getKey(username, password);

	return "{\"key\:\"" + key + "\",\"status\":\"success\"}";
}

string RequestManager::getHistory(string key){
	//Here user will be taken from the database using the key, his order history will be returned

	return "{\"Orders\":[{\"OrderID\:\"1\"}],\"status\":\"success\"}";
};

string RequestManager::orderTicket(string orderID, string key){

	return "Ticket Ordered " + orderID + ": " + key;
};

string RequestManager::cancelTicket(string ticketID,string key){

	return "Ticket canceled : " + ticketID;
}

string RequestManager::getMoviesList(){
	//Movies will be fetched from the db instead: TODO
	Movie m("1", "check", "me", "2017", "just a movie", "http:www.imdb.com/check");
        Movie m2("2", "check2", "meeeee", "2017", "just a movie2", "http:www.imdb.com/check2");
	
	return "{\"status\":\"success\",\"movies\":[" + m.ToJson() +"," + m2.ToJson() + "]}";
};

string RequestManager::getLocationsList(){

	return "Locations List";
};

string RequestManager::getMovieInfo(string movieID){

	return "Movie info: " + movieID;
};

string RequestManager::getLocationInfo(string locationName){
	cout << "Location Info: " << locationName << endl;;
	return "";
};

void RequestManager::parse(const char* stringToParse){
	string  parsedString(stringToParse), 
	   	user,
		pass,
		key,
		orderID,
		ticketID,
		movieID,
		locationName,
		response = "{\"status\":\"failure\",\"message\":\"Invalid request\"}"; //Default

	
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
			response = registerAccount(user, pass);
		break;

	case KEY:

		if (parseTwoParam(parsedString, "username", "password",user,pass))
			response = recoverKey(user, pass);
		break;

	case ORDER:

		if (parseTwoParam(parsedString, "orderID", "key",orderID,key))
			response = orderTicket(orderID,key);
		break;

	case CANCEL:

		if (parseTwoParam(parsedString, "ticketID", "key", ticketID, key));
			response = cancelTicket(ticketID,key);
		break;

	case HISTORY:

		if (parseOneParam(parsedString, "key",key))
			response = getHistory(key);
		break;

	case MOVIES:

		if (parsedString.length() == 0)
			response = getMoviesList();
		break;

	case MOVIE:

		if (parseOneParam(parsedString, "ID", movieID))
			response = getMovieInfo(movieID);
		break;

	case LOCATIONS:

		if (parsedString.length() == 0)
			response = getLocationsList();
		break;

	case LOCATION:

		response = "Location information"; //TODO
		break;

	default:
		cout << "Default" << endl; //TODO
		
	}
	
	cout << response;
}
