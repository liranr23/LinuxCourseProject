#include "Movie.h"

Movie::Movie(string _id, string _title, string _producer, string _year, string _info, string _imdb)
	: id(_id), title(_title), producer(_producer), year(_year), info(_info), imdbLink(_imdb) {

}

Movie::~Movie() {
}

string Movie::ToJson()const {
	return "{\n\t\t\"id\":\"" + id + "\",\n\t\t\"title\":\"" + title + "\",\n\t\t\"producer\":\"" + producer + "\",\n\t\t\"year\":\"" + year
		+ "\",\n\t\t\"info\":\"" + info + "\",\n\t\t\"link\":\"" + imdbLink + "\"\n\t}";
}
