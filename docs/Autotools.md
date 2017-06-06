# Autotools

Make sure you've installed the needed tools (Sqlite,FCGI,Nginx etc..)
For Ubuntu installation instructions refer to [Installation](Installation.md)

## To Run:
```bash
$sudo apt-get install autotools-dev
$sudo apt-get install autoconf
$sudo apt install libtool-bin
```

### Order of things

You need to put the files from this directory into to original one, the one in src will be in the original src!

#### Notice
You can change the directory you wish to install the files, the default is "/usr/local/bin" to the executable and "/usr/local/lib" to the dynamic library!

#### In this case you need to change Database.h and add THE PATH!!!("../databse.db" isn't enough!)

Also, if you wish to change the library directory. You will need to use:
```bash
$export LD_LIBRARY_PATH=YOURPATH
```
or to change it in the Makefile.am inside src directory("fcgi_LDFLAGS = -Wl,-rpath -Wl,YOURPATH").
if you wish to change the default dir of make you can either change it in ./configure or to run the command make as 
```bash
$./configure --prefix=/somewhere/else/than/usr/local
or
$./sudo make install DESTDIR=YOURDIR
```

##### The default case:

```bash
$mkdir m4
$autoreconf --install
$./configure
$make
$sudo make install
```

After you done these, You'll have an executable src/fcgi which is dependant on the dynamic library created above.

#### To continue refer to [How to Run](Running.md)
