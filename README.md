# Linux Environment Project

## Make sure you install the relevant tools:

- sudo apt-get install libfcgi-dev
- sudo apt-get install spawn-fcgi
- sudo apt-get install nginx
- sudo apt-get install curl


## API:

Using HTTP Get Requests:

Registers a new user with the username and password passed if possible
- Register:   Localhost/Register/username="USERNAME"&password="PASSWORD"

Orders a ticket for a movie at a location (represented by orderID) [Returns ticket id]
- Order:      Localhost/Order/id="orderID"&username="USERNAME"&password="PASSWORD"


Cancel a ticket (before the screening)
- Cancel:     Localhost/Cancel/id="ticketID"&username="USERNAME"&password="PASSWORD"

Returns tickets order history [Shows tickets ids too] :
- History:    Localhost/History/username="USERNAME"&password="PASSWORD"


Lists all the movies in all the theaters
- Movies:     Localhost/Movies

Lists all the locations of the theaters
- Locations:  Localhost/Locations

Lists all the movies at a location
- Movies at a location: Localhost/Location/Movies

Returns information about a specific movie
- Movie info:  Localhost/Movie

## Interface
