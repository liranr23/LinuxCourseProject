#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

using namespace std;

class Order {
private:
	string id, movieID, locationID, userKey;
    bool canceled;
public:
	Order(string,string,string,bool,string);
	~Order();
	string ToJson()const;
};
#endif