#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class RequestManager
{
private:
	static const string options[];
	static const int optionsAmount;
	static const enum OPT {REGISTER,KEY,ORDER,CANCEL,HISTORY,MOVIES,MOVIE,LOCATIONS,LOCATION };

	//Database Management:
	static string getKey(string username, string password);

	//Account management
	static string registerAccount(string username, string password);
	static string recoverKey(string username, string password);
	static string getHistory(string key);

	////Ticket Management
	static string orderTicket(string orderID, string key);
	static string cancelTicket(string ticketID,string key);

	////Information
	static string getMoviesList();
	static string getLocationsList();
	static string getMovieInfo(string movieID);
	static string getLocationInfo(string locationName);

	//Parser
	static bool  parseOneParam(string stringToParse, string param, string &var);
	static bool  parseTwoParam(string stringToParse, string param1, string param2, string &var1, string &var2);

public:
	static string parse(const char* stringToParse);
};

