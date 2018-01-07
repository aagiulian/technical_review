/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:56:12 by agiulian          #+#    #+#             */
/*   Updated: 2018/01/07 17:59:02 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.hpp"

// Initializes spd logger
void	init_logger()
{
	spdlog::set_pattern(LOG_FORMAT);
	auto my_logger = spdlog::basic_logger_mt(SERVER, LOG_FILE);
	my_logger->flush_on(spdlog::level::info); 
}

void	log_info(GpsSentence data)
{
	data.log((char*)SERVER);
}

// Initializes ZMQ suscriber connection on GPGGA informations
// Receives gps sequence and logs it in an infinite loop
int main ()
{
	const char 		*filter = "$GPGGA";
	zmq::context_t 	context (1);
	zmq::socket_t	subscriber (context, ZMQ_SUB);
	zmq::message_t	message;

	subscriber.connect(SERVER);
	subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen (filter));
	std::cout << "Client launched.." << std::endl;
	init_logger();
	std::cout << "Logging to " << LOG_FILE << std::endl;
	while (true)
	{	
		subscriber.recv(&message);
		GpsSentence	data((char*)message.data());
		std::cout << "Message received : " << (char*)message.data() << std::endl;
		std::thread t1(log_info, data);	
		t1.join();
	}
	return 0;
}
