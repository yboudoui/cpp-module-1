/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:12:33 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 13:48:18 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>

class	Array {
	public:
		Array(void): _arr(new T()), _size(0) {};
		Array(unsigned int n): _arr(new T[n]), _size(n) {};
		Array(const Array& other): _arr(new T[other._size]), _size(other._size) {
			for (unsigned int i = 0; i < _size; i++) {_arr[i] = other._arr[i];}
		};
		~Array(void) {delete[] _arr;}
		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _arr;
				_arr = new T[other._size];
				_size = other._size;
				for (unsigned int i = 0; i < _size; i++) {_arr[i] = other._arr[i];}
			}
			return (*this);
		}
		T& operator[]( unsigned int i ) const {
			if (i < 0 || i >= _size) {throw std::out_of_range("Good try");}
			return (_arr[i]);
		}
		unsigned int	size(void) const {return (_size);}
	private:
		T				*_arr;
		unsigned int	_size;
};

#endif
