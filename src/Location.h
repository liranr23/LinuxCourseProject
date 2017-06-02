#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <list>
#include "Movie.h"
using namespace std;
class Location
{
private:
	string id ,country, city,address;
	//list<Movie> movies;
public:
	Location(string,string, string, string);
	~Location();
	string ToJson()const;

	//void addMovie(Movie m);
};
#endif