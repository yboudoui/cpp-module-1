/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 08:46:09 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 09:08:47 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main( void )
{
	Serializer serializer;
	Data *data = new Data;

	data->login = "yboudoui";
	data->passwd = "1234lol4321";

	uintptr_t	ptr_serialized = serializer.serialize(data);
	Data		*unserialized = serializer.deserialize(ptr_serialized);

	std::cout << unserialized->login << std::endl;
	std::cout << unserialized->passwd << std::endl;

	delete unserialized;

	return (0);
}
