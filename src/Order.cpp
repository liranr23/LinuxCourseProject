#include "Order.h"

Order::Order(string _id, string _movieID, string _locationID, bool _canceled, string _userKey)
    : id(_id), movieID(_movieID), locationID(_locationID), canceled(_canceled), userKey(_userKey)
{
}

Order::~Order()
{
}

string Order::ToJson() const
{
    string result = "{\n\t\t\"id\":\"" + id + "\",\n\t\t\"movieID\":\"" + movieID + "\",\n\t\t\"locationID\":\"" + locationID + "\",\n\t\t\"canceled\":\"";
    if (canceled)
        result += "true";
    else
        result += "false";

    result += "\",\n\t\t\"userKey\":\"" + userKey + "\"\n\t}";
    return result;
}
