/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:16:07 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/12 18:53:17 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <vector>
#include <utility>

std::vector<int>	ford_johnson(std::vector<int> v_n, size_t size);

template<typename V>
void	p_v(std::string name, std::vector<V> v) {
	std::cout << name << " =[" << v.size() << "]{ ";
	for (size_t n = 0; n != v.size(); n++)
		std::cout << v[n] << ((n == v.size() - 1) ? " " : ", ");
	std::cout << "}; \n";
}

template<typename V>
void	p_v(std::string name, std::vector<V> v, size_t size) {
	std::cout << name << " =[" << v.size() << "]{";
	for (size_t n = 0; n != v.size(); n += size) {
		std::cout << " {";
		for (size_t i = 0; i != size; i++) {
			std::cout << v[n + i] << ((i == size - 1) ? "" : ", ");
		}
		std::cout << "}";
	}
	std::cout << " }; \n";
}

template<typename T>
std::string toString(const T& value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

int	main(int ac, char *av[])
{
	std::vector<int>	v_n;

	if (ac < 3) {
		std::cerr << "Error: wrong number of input. Expected at least 2 argument have " << toString(ac - 1) << std::endl;
		return (1);
	}

	av += 1;
	int	i;
	while (*av) {
		if(sscanf(*av, "%d", &i) != 1) {
			std::cerr << "Argument " << *av << " is not valide" << std::endl;
			return (1);
		}
		v_n.push_back(i);
		av += 1;
	}

	p_v("result",ford_johnson(v_n, 1));
	return (0);
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

size_t	find_pos(std::vector<int>::iterator first, std::vector<int>::iterator last, int v)
{
	std::vector<int>::iterator	start = first;
	size_t	size = std::distance(first, last) / 2;
	while (size) {
		if (v > *(first + size)) { last -= size; } else { first += size; }
		size = std::distance(first, last) / 2;
	}
	return ((v > (*first)) ? start - first : last - start);
}

std::vector<int>	swap_using_size(std::vector<int> input, size_t size)
{
	std::vector<int>			out;
	std::vector<int>::iterator	it;

	for (it = input.begin(); it != input.end(); it += size * 2) {
		if (*it > *(it + size)) {
			out.insert(out.end(), it, it + size);
			it += size;
			out.insert(out.end(), it, it + size);
			it -= size;
		} else {
			it += size;
			out.insert(out.end(), it, it + size);
			it -= size;
			out.insert(out.end(), it, it + size);
		}
	}
	return (out);
}

std::vector<int>	ford_johnson(std::vector<int> v_n, size_t size)
{
	size_t		dist = v_n.size();
	if ( (dist / size) == 1.0 ) { return (v_n); }

	std::vector<int>	*remaind = NULL;
	int					mod = dist % (size * 2);
	if (mod) {
		remaind = new std::vector<int>(v_n.end() - mod, v_n.end());
		dist -= mod;
		v_n.erase(v_n.end() - mod, v_n.end());
	}

	std::vector<int>	out;
	std::vector<int>	tmp;

	p_v("0 ==> tmp", v_n, size * 2);
	tmp = swap_using_size(v_n, size);
	p_v("1 ==> tmp", tmp, size * 2);
	tmp = ford_johnson(tmp, size * 2);
	p_v("2 ==> tmp", tmp, size);

	size_t									pos = 0;
	std::vector<int>						a;
/*
	std::vector<int>	b;
	if ((tmp.size() / size) != 2) {
		for (size_t i = 0; i <= dist - size; i += (size * 2)) {
			out.insert(out.end(), tmp.begin() + i, tmp.begin() + (i + size));
			a.insert(a.end(), tmp.at(i));
			b.insert(b.end(), tmp.begin() + (i + size));
		}
		for (size_t i = 0; (jacobsthal_diff[i] - 1) < b.size(); i++) {
			int k = jacobsthal_diff[i] - 1;
			pos = find_pos(a.begin(), a.end(), *b.at(k));
			a.insert(a.begin() + pos, *b.at(k));
			out.insert(out.begin() + (pos * size), b.at(k), b.at(k) + size);
			b.erase(b.begin() + k);
		}
		for (size_t i = 0; i != b.size(); i++) {
			pos = find_pos(a.begin(), a.end(), *b.at(i));
			a.insert(a.begin() + pos, *b.at(i));
			out.insert(out.begin() + (pos * size), b.at(i), b.at(i) + size);
		}
	} else { out = tmp; }
*/

	std::vector<std::vector<int>::iterator>	b;
	if ((tmp.size() / size) != 2) {
		for (size_t i = 0; i < (tmp.size() - size); i += (size * 2)) {
			out.insert(out.end(), tmp.begin() + i, tmp.begin() + (i + size));
			a.insert(a.end(), tmp.at(i));
			b.insert(b.end(), (tmp.begin() + (i + size)));
		}
		for (size_t i = 0; (jacobsthal_diff[i] - 1) < b.size(); i++) {
			int k = jacobsthal_diff[i] - 1;
			//pos = find_pos(a.begin(), a.end(), *b.at(k));
			pos = find_pos(a.begin() + k - 1, a.end(), *b.at(k));
			a.insert(a.begin() + pos, *b.at(k));
			out.insert(out.begin() + (pos * size), b.at(k), b.at(k) + size);
			b.erase(b.begin() + k);
		}
		while (b.size()) {
			pos = find_pos(a.begin(), a.end(), *b.at(0));
			a.insert(a.begin() + pos, *b.at(0));
			out.insert(out.begin() + (pos * size), b.at(0), b.at(0) + size);
			b.erase(b.begin());
		}
	} else { out = tmp; }

	if (remaind)
		p_v("remaind", *remaind);

	if (remaind) {
		pos = find_pos(a.begin(), a.end(), (*remaind)[0]);
		out.insert(out.begin() + (pos * size), remaind->begin(), remaind->end());
		delete remaind;
	}
	p_v("2 ==> out", out, size);
	std::cout << "======================================" << std::endl;
	return (out);
}
