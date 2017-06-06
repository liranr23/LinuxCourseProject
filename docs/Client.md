
# Interface
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
      
   Ordering :	
	View orders history
		./client --history <USER_KEY>
		
	Order new ticket:
		./client --order-ticket <MOVIE_ID>:<LOCATION_ID> --userkey <USER_KEY>
		
	Cancel ticket order:
		./client --cancel-ticket <TICKET_ID> --userkey <USER_KEY>
```
