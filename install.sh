#!/bin/sh

mkdir lib
cd lib

# Install Zeromq
git clone https://github.com/zeromq/libzmq
cd libzmq
mkdir build
cd build
cmake ..
sudo make -j4 install
cd ../..

# Install C++ Zeromq
git clone https://github.com/zeromq/cppzmq
cd cppzmq
mkdir build
cd build
cmake ..
sudo make -j4 install
cd ../..

# Copy Spd source files
git clone https://github.com/gabime/spdlog
cd ..

# Link librairies
sudo ldconfig

# Install Client and Server
mkdir build
cd build
cmake ..
make

