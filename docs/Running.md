# How to run:

```bash
cd src
chmod +x run.sh
./run.sh (Copies nginx configuration to /usr/shared/nginx kills & starts an fcgi spawn
```
## Restoring Database:

```bash
cd db
chmod +x refreshDB.sh
./refreshDB.sh (Removes and runs the initDB executable which reloads the tables/records)
```

## Running local website for remote api (Droplet on digitalOcean)
- Change the <Root> (root ..../distLocal) line in movies.conf to: ../distRemote.
- Run as instructed above.
## Shutting down:

```bash
sudo kill -KILL "$(pgrep fcgi)"
sudo nginx -c movies.conf -s quit
```
