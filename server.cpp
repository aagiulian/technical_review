/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:40:12 by agiulian          #+#    #+#             */
/*   Updated: 2018/01/07 18:02:46 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zmq.hpp>
#include <unistd.h>
#include <iostream>

// Some fix quality and altitude random value generator
const char *generate_random_gps_values()
{
	std::string	gps_sentence;
	char	alt[10];
	
	sprintf(alt, "%.1lf", random()/(double)RAND_MAX * (0.0-1000.0) + 1000.0);
	gps_sentence = ("$GPGGA,123519,4807.038,N,01131.000,E,");
	gps_sentence += random()%9 + '0';
	gps_sentence += "3,08,0.9,";
	gps_sentence += alt;
	gps_sentence += ",M,46.9,M,,*47";
	return ((gps_sentence.c_str()));
}

// Starts publisher and sends gps sentence in an infinite loop
int main ()
{
	zmq::context_t context (1);
	zmq::socket_t publisher (context, ZMQ_PUB);

	publisher.bind("tcp://*:5653"); 		// Set desired port number here
	std::cout << "Server launched.." << std::endl;
	while (1) 
	{
		const char *gps_data;

		gps_data = generate_random_gps_values();
		zmq::message_t message(strlen(gps_data) + 1);
		std::cout << "Message sent : " << gps_data << std::endl;
		snprintf ((char *) message.data(), strlen(gps_data) + 1, "%s", gps_data); 
		publisher.send(message);
		usleep(1000000);
	}
	return 0;
}
