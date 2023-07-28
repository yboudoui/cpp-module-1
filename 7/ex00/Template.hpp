/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:05:00 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 10:19:30 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP
/*
template <typename T> void	swap(const T& t1, const T& t2 );
template <typename T> T		min(const T& t1, const T& t2 );
template <typename T> T		max(const T& t1, const T& t2 );
*/
template <typename T> void	swap(T& t1, T& t2 ) {
	T	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template <typename T> T		min(const T& t1, const T& t2 ) {
	return ((t2 <= t1) ? t2 : t1);
}

template <typename T> T		max(const T& t1, const T& t2 ) {
	return ((t2 >= t1) ? t2 : t1);
}
#endif
