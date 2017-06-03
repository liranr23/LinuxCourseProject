# Linux Environment Project
## To Run:
```bash
$cd src
$./compile.sh
$./run.sh
```
## Make sure you install the relevant tools:

### Fast CGI:
```bash
sudo apt-get install libfcgi-dev
sudo apt-get install spawn-fcgi
```

## Nginx
```bash
sudo apt-get install nginx
```

## For Client script
```bash
sudo apt-get install curl
```

## Sqlite3
```bash
sudo apt-get install sqlite3  (On some flavors installed by default eg; Ubuntu 16.04)
sudo apt-get install libsqlite3-dev
```



## API:

Using HTTP Get Requests:

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
localhost/Cancel/id=<ORDERID>&key=<USERKEY>
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
## Interface
```browser
Bash interface :
	./client -h :	synopsis
	./client -v :	version with authors names
	
	Register to system:
		./client --register username:password
	
	Recover lost userkey:
		./client --recoverKey <USERNAME>:<PASSWORD>
	
	View movies :
		All movies:
			./client --movies
	
		By ID:
			./client --movieID <MOVIEID>
		
		By Name (or part of name,prefix):
			./client --movieName "MOVIE NAME"
			
	View locations:
		All without filtering:
			./client --locations
		
		By ID:
			./client --locationID <ID>
		
		By Country:
			./client --locations --country <COUNTRY>, may be used country prefix
		
		By City:
			./client --locations --city <CITY> , may be used city prefix
      
    Order : IN DEVELOPING
```
