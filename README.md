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

#### Returns user's key
```
- localhost/RecoverKey/username=<USERNAME>&password=<PASSWORD>
```


#### Orders a ticket for a movie at a location (represented by orderID) [Returns ticket id]
```
- localhost/Order/id=<ORDERID>&key=<USERKEY>
```


#### Cancel a ticket (before the screening)
```
- localhost/Cancel/id=<TICKETID>&key=<USERKEY>
```

#### Returns tickets order history [Shows tickets ids too] :
```
- localhost/History/key=<USERKEY>
```


#### Lists all the movies in all the theaters
```
- localhost/Movies/
```

#### Lists all the locations of the theaters
```
- localhost/Locations/
```

#### Returns information about a specific location
```
- localhost/Location/ID=<LOCATIONID>
- localhost/Location/city=<LOCATIONCITY>
- localhost/Location/country=<LOCATIONCOUNTRY>
```

#### Returns information about a specific movie
```
- localhost/Movie/ID=<MOVIEID>
- localhost/Movie/name=<MOVIENAME>
```

## Interface
