#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <list>
#include "Movie.h"
using namespace std;
class Location
{
private:
	string country, city;
	list<Movie> movies;
public:
	Location(string _country, string _city);
	~Location();
	string ToJson()const;
	void addMovie(Movie m);
};
#endif