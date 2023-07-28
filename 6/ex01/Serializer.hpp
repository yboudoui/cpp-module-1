/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 08:48:35 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 09:08:33 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>

typedef struct	s_Data
{
	std::string	login;
	std::string	passwd;
}	Data;


class Serializer {
	public:
		static uintptr_t serialize(Data *);
		static Data* deserialize(uintptr_t);
};

#endif
