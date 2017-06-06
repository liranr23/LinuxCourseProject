# API:

##### For all Requests, there's a "status" value (success\failure) , when request fails a "message" value includes the reason

Using HTTP Requests:

#### Registers a new user with the username and password passed if possible
```browser
localhost/Register/username=<USERNAME>&password=<PASSWORD>
```
Response:
```json
{"key":"3X4MPL3K3Y" , "status": "success"}
```

#### Returns user's key
```browser
localhost/RecoverKey/username=<USERNAME>&password=<PASSWORD>
```

Response:
```json
{"key":"3X4MPL3K3Y" , "status": "success"}
```

#### Orders a ticket for a movie at a location (represented by orderID) [Returns ticket id]
```browser
localhost/Order/key=<USERKEY>&movieID=<MOVIEID>&locationID=<LOCATIONID>
```
```json
{"status":"success","message":"Ticket successfuly ordered"}
```


#### Returns tickets order history:
```browser
localhost/History/key=<USERKEY>
```

Response:
```json
{
"status": "success",
"orders": [
{
"id": "1",
"movieID": "1",
"locationID": "1",
"canceled": "true",
"userKey": "WO1V3RK3YDCBA4321"
},
{
"id": "2",
"movieID": "2",
"locationID": "2",
"canceled": "true",
"userKey": "WO1V3RK3YDCBA4321"
}
]
}
```
#### Cancel a ticket

```browser
localhost/Cancel/key=<USERKEY>&orderID=<ORDERID>
```

Response:

```json
{"status":"success","message":"Ticket successfuly canceled"}

```
#### Lists Movies information (empty for all movies):

```browser
localhost/Movies/
localhost/Movies/ID=<MOVIEID>
localhost/Movies/title=<MOVIENAME>

```
Response:
```json
{"status":"success","movies":[{
                "id":"1",
                "title":"THOR",
                "producer":"MARVEL",
                "year":"2015",
                "info":"A MOVIE ABOUT SOMEONE WITH A HAMMER",
                "link":"thor.io"
        },{
                "id":"2",
                "title":"SPIDERMAN HOMECOMING",
                "producer":"MARVEL",
                "year":"2017",
                "info":"A MOVIE ABOUT SPIDERMAN JUST WITH A NEW ACTOR",
                "link":"SMHC.io"
        },{
                "id":"3",
                "title":"THE DARK KNIGHT",
                "producer":"DC",
                "year":"2014",
                "info":"A MOVIE ABOUT SOMEONE WITH MONEY AND TIME",
                "link":"BATMAN.io"
        }]}
```

#### Lists locations information (empty for all locations)
```browser
localhost/Locations/
localhost/Locations/ID=<LOCATIONID>
localhost/Locations/city=<LOCATIONCITY>
localhost/Locations/country=<LOCATIONCOUNTRY>
```

Response:
```json
{
  "status": "success",
  "locations": [
    {
      "country": "Israel",
      "city": "Tel Aviv",
      "address": "HaMasger 2"
    },
    {
      "country": "Israel",
      "city": "Beer Sheva",
      "address": "Mesada 10"
    }
  ]
}
```
