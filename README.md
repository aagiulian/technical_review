# Bilberry Technical Review 

A TCP server that sends GPS NMEA GGA sentences every seconds.

A TCP client that connects to the GPS server and logs its fix quality and altitude in a file.

Project is compiled with C++11

### Installing

```
git clone https://github.com/darklink41/technical_review
cd technical_review
sh install.sh
```

Now just run the client and the server
```
./server
./client
```

## Options 

Server port should be modified server.cpp for server and in client.hpp for client

In client.hpp you can set the emplacement of the logfile as well as the logging format (see https://github.com/gabime/spdlog/wiki/3.-Custom-formatting for custom formatting)

In order to kill the client or server, just Ctrl-C


## Built With

* [ZeroMQ](http://zeromq.org/) - Fast Distributed Messaging library
* [Spdlog](https://github.com/gabime/spdlog) - Fast C++ logging library


## Authors

* **Arthur Giuliano** [darklink41](https://github.com/darklink41)

