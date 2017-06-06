## Installation:
### Make sure you install the relevant tools:

#### Fast CGI:
```bash
sudo apt-get install libfcgi-dev
sudo apt-get install spawn-fcgi
```

#### Nginx
```bash
sudo apt-get install nginx
```

#### For Client script
```bash
sudo apt-get install curl
```

#### Sqlite3
```bash
sudo apt-get install sqlite3  (On some flavors installed by default eg; Ubuntu 16.04)
sudo apt-get install libsqlite3-dev
```

#### Autotools

After installing the relevant tools, refer to the [Autotools](Autotools.md) instructions for compliation and linking

## To Run:
```bash
$cd src
$./compile.sh
$./run.sh
```
