#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class RequestManager
{
private:
	static const string options[];
	static const int optionsAmount;

	enum OPT {REGISTER,KEY,ORDER,CANCEL,HISTORY,MOVIES,MOVIE,LOCATIONS,LOCATION };

	//Database Management:
	static string getKey(string username, string password);

	//Account management
	static void registerAccount(string username, string password);
	static void recoverKey(string username, string password);
	static void getHistory(string key);

	////Ticket Management
	static void orderTicket(string orderID, string key);
	static void cancelTicket(string ticketID,string key);

	////Information
	static void getMoviesList();
	static void getLocationsList();
	static void getMovieInfo(string movieID);
	static void getLocationInfo(string locationName);

	//Parser
	static bool  parseOneParam(string stringToParse, string param, string &var);
	static bool  parseTwoParam(string stringToParse, string param1, string param2, string &var1, string &var2);

public:
	static void parse(const char* stringToParse);
};

