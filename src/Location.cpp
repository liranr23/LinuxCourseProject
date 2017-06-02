#include "Location.h"

Location::Location(string _id , string _country, string _city, string _address):
id(_id), country(_country), city(_city), address(_address)
{
}


Location::~Location()
{
}

string Location::ToJson()const {
	// string res = "{\n\t\"country\":\"" + country + "\",\n\t\"city\":\"" + city + "\",\n\t\"Movies\":[\n\t";
	string res = "{\n\t\"country\":\"" +
				country + "\",\n\t\"city\":\"" +
				city + "\",\n\t\"address\":\"" +
				address + "\"\n}";
	//for (list<Movie>::const_iterator it = movies.begin(); it != movies.end(); ++it) {
	//	res += it->ToJson();
	//	if (it != --movies.end())
	//		res += ",\n\t";
	//}
	//res += "\n]}";
	return res;
}
// void Location::addMovie(Movie m) {
// 	movies.push_back(m);
	
// }