#include "Parser.h"
#include <iostream>
#include <string>
#include <string.h>

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
	cout << "{\"key\":\"3x4mpl3k3y\",\"status\":\"success\"}" << endl;
	return "";
};

string RequestManager::getKey(string username, string password){
	//Gets the key from the database for a user:
	return "3x4mple3k3y";
}

string RequestManager::recoverKey(string username, string password){
	//Here user will be checked and his key will be returned
	string key = getKey(username, password);
	cout << "{\"key\:\"" << key << "\",\"status\":\"success\"}" << endl ;
	return "";
}

string RequestManager::getHistory(string key){
	//Here user will be taken from the database using the key, his order history will be returned

	cout << "{\"Orders\":[{\"OrderID\:\"1\"}],\"status\":\"success\"}" << endl;
	return "";
};

string RequestManager::orderTicket(string orderID, string key){
	cout << "Ticket Ordered" << orderID << ":" << key << endl;
	return "";
};

string RequestManager::cancelTicket(string ticketID,string key){
	cout << "Ticket canceled : " << ticketID << endl;
	return "";
}

string RequestManager::getMoviesList(){
	cout << "Movies List" << endl;
	return "";
};

string RequestManager::getLocationsList(){
	cout << "Locations List" << endl;
	return "";
};

string RequestManager::getMovieInfo(string movieID){
	cout << "Movie info: " << movieID << endl;;
	return "";
};

string RequestManager::getLocationInfo(string locationName){
	cout << "Location Info: " << locationName << endl;;
	return "";
};

string RequestManager::parse(const char* stringToParse){
	string parsedString(stringToParse);
	string user;
	string pass;
	string key;
	string orderID;
	string ticketID;
	string movieID, locationName;

	int option;
	for (int i = 0; i < RequestManager::optionsAmount; i++){
		option = i;
		int index = parsedString.find(options[i]);
		if (index == 0){ parsedString = parsedString.substr(options[i].length()); break; }
	}

	switch (option){
	case REGISTER:
		//if (parseUserAndPass(parsedString, user, pass))
		if (parseTwoParam(parsedString, "username","password",user,pass))
			return registerAccount(user, pass);
		break;

	case KEY:
		//if (parseUserAndPass(parsedString, user, pass))
		if (parseTwoParam(parsedString, "username", "password",user,pass))
			return recoverKey(user, pass);
		break;

	case ORDER:
		//if (parseOrderAndKey(parsedString, orderID, key))
		if (parseTwoParam(parsedString, "orderID", "key",orderID,key))
			return orderTicket(orderID,key);
		break;

	case CANCEL:
		//if (parseTicketIDAndKey(parsedString,ticketID,key))
		if (parseTwoParam(parsedString, "ticketID", "key", ticketID, key));
			return cancelTicket(ticketID,key);
		break;

	case HISTORY:
		//if (parseKey(parsedString, key))
		if (parseOneParam(parsedString, "key",key))
			return getHistory(key);
		break;

	case MOVIES:
		if (parsedString.length() == 0)
			return getMoviesList();
		break;

	case MOVIE:
		if (parseOneParam(parsedString, "ID", movieID))
			getMovieInfo(movieID);
		break;

	case LOCATIONS:
		if (parsedString.length() == 0)
			return getLocationsList();
		break;

	case LOCATION:
		cout << "Location information" << endl;
		break;

	default:
		cout << "Can't be parsed" << endl;
	}
	
	return "Can't be parsed";
}