#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class RequestManager
{
private:
	static const string options[];
	static const int optionsAmount;

	enum OPT {REGISTER,KEY,ORDER,CANCEL,HISTORY,MOVIES,LOCATIONS };
	enum SUBOPT {BY_ID,BY_TITLE,BY_COUNTRY,BY_CITY};
	//Database Management:
	static string getKey(string , string );

	//Account management
	static void registerAccount(string , string );
	static void recoverKey(string , string );
	static void getHistory(string );

	////Ticket Management
	static void orderTicket(string orderID, string key);
	static void cancelTicket(string ticketID,string key);

	////Information
	static void getMoviesList();
	static void getLocationsList();
	static void getMovieInfo(string , int);
	static void getLocationInfo(string, int);

	//Parser
	static bool  parseOneParam(string , string , string&);
	static bool  parseTwoParam(string , string , string , string&, string&);

public:
	static void parse(const char* stringToParse);
};

