/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:04:57 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/31 14:31:36 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		if (*it == value) { return (it); }
	throw std::runtime_error("Value not found in the container");
}

#endif // EASYFIND_TPP

