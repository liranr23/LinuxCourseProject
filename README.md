# Linux Environment Project

## Make sure you install the relevant tools:

### Fast CGI:
```
- sudo apt-get install libfcgi-dev
- sudo apt-get install spawn-fcgi
```

## Nginx
```
- sudo apt-get install nginx
```

## For Client script
```
- sudo apt-get install curl
```

## Sqlite3
```
- sudo apt-get install sqlite3  (On some flavors installed by default eg; Ubuntu 16.04)
- sudo apt-get install libsqlite3-dev
```



## API:

Using HTTP Get Requests:

#### Registers a new user with the username and password passed if possible
```
- localhost/Register/username=<USERNAME>&password=<PASSWORD>
```
Response:
```json
{"key":"3X4MPL3K3Y" , "status": "success"}
```

#### Returns user's key
```
- localhost/RecoverKey/username=<USERNAME>&password=<PASSWORD>
```


#### Orders a ticket for a movie at a location (represented by orderID) [Returns ticket id]
```
- localhost/Order/key=<USERKEY>&movieID=<MOVIEID>&locationID=<LOCATIONID>
```


#### Cancel a ticket
```
- localhost/Cancel/id=<ORDERID>&key=<USERKEY>
```

#### Returns tickets order history:
```
- localhost/History/key=<USERKEY>
```


#### Lists Movies information (empty for all movies):
```
- localhost/Movies/
- localhost/Movies/ID=<MOVIEID>
- localhost/Movies/name=<MOVIENAME>

```

#### Lists locations information (empty for all locations)
```
- localhost/Locations/
- localhost/Locations/ID=<LOCATIONID>
- localhost/Locations/city=<LOCATIONCITY>
- localhost/Locations/country=<LOCATIONCOUNTRY>
```

## Interface
