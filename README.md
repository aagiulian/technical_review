# Bilberry Technical Review 

A TCP server that sends GPS NMEA GGA sentences every seconds.

A TCP client that connects to the GPS server and logs its fix quality and altitude in a file.


## Getting Started

These insctructions will get you a copy of the project up and running on your local machine.

See Options for notes on options.

### Prerequisites

This project uses ZeroMQ library for distributed messaging and SPDLOG for logging.

Build Zeromq and Zeromq C++
```
git clone https://github.com/zeromq/libzmq
cd libzmq
mkdir build
cd build
cmake ..
sudo make -j4 install

cd ...
git clone https://github.com/zeromq/cppzmq
cd cppzmq
mkdir build
cd build
cmake ..
sudo make -j4 install
```

Download Spdlog in a directory you will remember
```
git clone https://github.com/gabime/spdlog
```

### Installing

Now it's time to install the project
```
git clone https://github.com/darklink41/technical_review
cd technical_review
cp -R [spdlog's directory]/include/spdlog .
mkdir build
cd build
cmake ..
make
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

