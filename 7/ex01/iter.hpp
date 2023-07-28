/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:16:44 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 10:21:00 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T> void	iter(T *array, size_t length, void (*func)(T)) {
	if (array == NULL || length == 0 || func == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
#endif
