#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Movie.h" 
using namespace std;
class User
{
private:
	string username, password, key;
	vector<Movie> History;
public:
	User(string un, string ps);
	~User();
};

#endif