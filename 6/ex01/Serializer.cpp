/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 08:49:30 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 09:06:47 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *data) {
	return (reinterpret_cast<uintptr_t>(data));
}

Data*	Serializer::deserialize(uintptr_t data) {
	return (reinterpret_cast<Data*>(data));
}
