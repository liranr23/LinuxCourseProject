#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

using namespace std;

class Movie {
private:
	string id, title, producer, year, info, imdbLink;
public:
	Movie(string _id, string _title, string _producer, string _year, string _info, string _imdb);
	~Movie();
	string ToJson()const;
};
#endif