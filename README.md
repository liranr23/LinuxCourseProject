# Linux Environment Project

## Make sure you install the relevant tools:

### Fast CGI:
- sudo apt-get install libfcgi-dev
- sudo apt-get install spawn-fcgi

## Nginx
- sudo apt-get install nginx

## For Script
- sudo apt-get install curl

## Sqlite3
- sudo apt-get install sqlite3  (On some flavors installed by default eg; Ubuntu 16.04)
- sudo apt-get install libsqlite3-dev



## API:

Using HTTP Get Requests:

### Registers a new user with the username and password passed if possible
- Register:   Localhost/Register/username="USERNAME"&password="PASSWORD"

### Returns user's key
- RecoverKey: Localhost/RecoverKey/username="USERNAME"&password="PASSWORD"


### Orders a ticket for a movie at a location (represented by orderID) [Returns ticket id]
- Order:      Localhost/Order/id="orderID"&key="userKey"


### Cancel a ticket (before the screening)
- Cancel:     Localhost/Cancel/id="ticketID"&key="userKey"

### Returns tickets order history [Shows tickets ids too] :
- History:    Localhost/History/key="userKey"


### Lists all the movies in all the theaters
- Movies:     Localhost/Movies/

### Lists all the locations of the theaters
- Locations:  Localhost/Locations/

### Lists all the movies at a location
- Movies at a location: Localhost/Location/Movies/

### Returns information about a specific movie
- Movie info:  Localhost/Movie/ID="movieID"



## Interface
