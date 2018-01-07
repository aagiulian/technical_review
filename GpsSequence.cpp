/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GpsSequence.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:52:40 by agiulian          #+#    #+#             */
/*   Updated: 2018/01/07 16:54:52 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.hpp"


		GpsSentence::GpsSentence(char *gps_data)
		: gps_data(gps_data)
{}

// Extracts fix quality from Gps sentence
int		GpsSentence::fix_quality() const 
{
	int i, j;

	i = j = 0;
	while (gps_data[i])
	{
		if (gps_data[i] == ',')
			j++;
		if (j == 6)
			return (gps_data[i + 1] - '0');
		i++;
	}
	return (0);
}

// Extracts altitude from Gps sentence
char	*GpsSentence::altitude() const
{
	int 	i, j, k;
	double	altitude;
	char 	*temp;

	i = j = k = 0;
	while (gps_data[i])
	{
		if (gps_data[i] == ',')
			++j;
		if (j == 9)
		{
			j = ++i;
			while (gps_data[i] && gps_data[i] != ',' && i++)
				++k;
			return (strndup(gps_data + j, k));
		}
		i++;
	}
	return (0);
}

// Logs Fix quality and altitude with Spd logger
void	GpsSentence::log(char *logger) const
{
	spdlog::get(logger)->info("Fix quality : {} / Altitude : {} meters", fix_quality(), altitude());
}
