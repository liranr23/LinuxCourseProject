#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "fcgio.h"
#include "Location.h"
#include "User.h"
#include "RequestManager.h"

using namespace std;

int main(void) {
    // Backup the stdio streambufs
    streambuf * cin_streambuf  = cin.rdbuf();
    streambuf * cout_streambuf = cout.rdbuf();
    streambuf * cerr_streambuf = cerr.rdbuf();

    FCGX_Request request;

    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) == 0) {
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);
	
	//Getting the request uri:
	    const char* uri = FCGX_GetParam("REQUEST_URI",request.envp);

        cout << "Content-type: text/plain\r\n"
	     << "\r\n";
	////Output Liran
        //Location l("Israel", "Be'er Sheba");
        //Movie m("1", "check", "me", "2017", "just a movie", "http:www.imdb.com/check");
        //Movie m2("2", "check2", "meeeee", "2017", "just a movie2", "http:www.imdb.com/check2");
        //l.addMovie(m);
        //l.addMovie(m2);
        //<< "\r\n" << l.ToJson() << "\n";
        //<< "\r\n" << uri << "\n";

	//Output Jonathan
	RequestManager::parse(uri);
	cout <<"\n";
    }

    // restore stdio streambufs
    cin.rdbuf(cin_streambuf);
    cout.rdbuf(cout_streambuf);
    cerr.rdbuf(cerr_streambuf);

    return 0;
}
