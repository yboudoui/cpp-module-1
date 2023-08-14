/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:52:25 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/13 21:32:05 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstdio>
# include <sstream>

# include <algorithm>
# include <iterator>
# include <vector>
# include <list>
# include <utility>

template<typename V>
std::string toString(const V& value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

static const unsigned long jacobsthal_diff[] = {
2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

template<typename T, template < typename, typename = std::allocator<T> > class C>
typename C<T>::iterator	to(typename C<T>::iterator it, long long i)
{
	typename C<T>::iterator	out = it;
	std::advance(out, i);
	return (out);
}

template<typename T, template < typename, typename = std::allocator<T> > class C>
size_t	find_pos(typename C<T>::iterator first, typename C<T>::iterator last, int v)
{
	typename C<T>::iterator	start = first;
	size_t	size = std::distance(first, last) / 2;
	while (size) {
		if (v > *to<T,C>(first, size)) {
			std::advance(last, -size);
		} else {
			std::advance(first, size);
		}
		size = std::distance(first, last) / 2;
	}
//	return ((v > (*first)) ? start - first : last - start);
//	return ((v > (*first)) ? std::distance(start, first) : std::distance(last, start));
	return ((v > (*first)) ? std::distance(start, first) : std::distance(start, last));
}

template<typename T, template < typename, typename = std::allocator<T> > class C>
C<T>	swap_using_size(C<T> input, size_t size)
{
	C<T>			out;
	typename C<T>::iterator	it;

	for (it = input.begin(); it != input.end(); it = to<T,C>(it, size * 2)) {
		if (*it > *to<T,C>(it,size)) {
			out.insert(out.end(), it, to<T,C>(it, size));
			it = to<T,C>(it, size);
			out.insert(out.end(), it, to<T,C>(it, size));
			it = to<T,C>(it, -size);
		} else {
			it = to<T,C>(it, size);
			out.insert(out.end(), it, to<T,C>(it, size));
			it = to<T,C>(it, -size);
			out.insert(out.end(), it, to<T,C>(it, size));
		}
	}
	return (out);
}

template<typename T, template < typename, typename = std::allocator<T> > class C>
C<T>	ford_johnson(C<T> container, size_t size)
{
	size_t	dist = container.size();
	C<T>	*remaind = NULL;
	C<T>	out, tmp;
	typename C<T>::iterator	it[2];

	if ( (dist / size) == 1.0 ) { return (container); }
	size_t	mod = dist % (size * 2);
	if (mod) {
		remaind = new C<T>(to<T,C>(container.end(), -mod), container.end());
		dist -= mod;
		container.erase(to<T,C>(container.end(), -mod), container.end());
	}
	tmp = swap_using_size(container, size);
	tmp = ford_johnson(tmp, size * 2);

	size_t	pos = 0;
	C<T>	a;
	C<typename C<T>::iterator>	b;

	if ((tmp.size() / size) != 2) {
		for (size_t i = 0; i < (tmp.size() - size); i += (size * 2)) {
			it[0] = to<T,C>(tmp.begin(), i);
			it[1] = to<T,C>(tmp.begin(), i + size);
			out.insert(out.end(), it[0], it[1]);
			a.insert(a.end(), *it[0]);
			b.insert(b.end(), it[1]);
		}
		for (size_t i = 0; (jacobsthal_diff[i] - 1) < b.size(); i++) {
			int k = jacobsthal_diff[i] - 1;
			typename C<typename C<T>::iterator>::iterator	itb[2] = {b.begin(), b.begin()};
			std::advance(itb[0], k);
			pos = find_pos <T,C>(to<T,C>(a.begin(), k - 1), a.end(), (*(*itb[0])));
			a.insert(to<T,C>(a.begin(), pos), (*(*itb[0])));
			std::advance(itb[1], k);
			out.insert(to<T,C>(out.begin(), (pos * size)), (*itb[0]), to<T,C>((*itb[1]), size));
			b.erase(itb[0]);
		}
		while (b.size()) {
			typename C<typename C<T>::iterator>::iterator	itb[2] = {b.begin(), b.begin()};
			pos = find_pos<T, C>(a.begin(), a.end(), (*(*itb[0])));
			a.insert(to<T,C>(a.begin(), pos), (*(*itb[0])));
			out.insert(to<T,C>(out.begin(), (pos * size)), (*itb[0]), to<T,C>((*itb[1]), size));
			b.erase(b.begin());
		}
	} else { out = tmp; }

	if (remaind) {
		pos = find_pos<T, C>(a.begin(), a.end(), *(remaind->begin()));
		out.insert(to<T,C>(out.begin(), (pos * size)), remaind->begin(), remaind->end());
		delete remaind;
	}
	return (out);
}

template<typename T, template < typename, typename = std::allocator<T> > class C>
void	print_container(C<T> container) {
	typename C<T>::iterator	it;
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << " " << *it;
	}
}

#endif
