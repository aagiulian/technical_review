#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <zmq.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <thread>
#include "spdlog/spdlog.h"

#define SERVER		"tcp://localhost:5653"  // Sets the server address
#define LOG_FILE 	"log.txt" 				// Sets log file location
#define LOG_FORMAT 	"[%x %H:%M:%S] [%n] %v" // Sets log format, see readme for more info

class GpsSentence
{
	public:
		GpsSentence(char *s);
		int		fix_quality() const; 		// Extracts fix quality info from GPS sentence
		char	*altitude() const;	 		// Extracts altitude info from GPS sentence
		void	log(char *logger) const;	// Logs both fix quality and altitude
	private:
		char 	*gps_data;
		char	*logger = NULL;
};

#endif
