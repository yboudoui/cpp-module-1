/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:16:07 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/11 23:52:00 by yboudoui         ###   ########.fr       */
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

template<typename V, int N>
void	ford_johnson(std::vector<V> *v_n);

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

	ford_johnson<int, 32>(&v_n);
	return (0);
}
/*
static const jacobsthal_diff[] = {
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
*/
template<typename V>
void	binary_insert(std::vector<V> *i, typename std::vector<V>::iterator begin, typename std::vector<V>::iterator end, V v)
{
	typename std::vector<V>::iterator bound = std::upper_bound(begin, end, v);
	i->insert(bound, v);
}

template<typename V, int N>
void	ford_johnson(std::vector<V> *v_n)
{
	size_t	limit = v_n->size();
	if (limit == 1) { return; }

	std::vector< std::pair<V,V> >	tmp;
	V			*remaind = NULL;

	std::pair<V,V>	pair;
	if (limit % 2) { remaind = new V((*v_n)[limit--]); }
	for (size_t i = 0; i != limit; i += 2) {
		if ((*v_n)[i] < (*v_n)[i + 1]) {
			pair = std::make_pair((*v_n)[i + 1], (*v_n)[i]);
		} else {
			pair = std::make_pair((*v_n)[i], (*v_n)[i + 1]);
		}
		tmp.insert(tmp.begin(), pair);
	}

	ford_johnson<V, N - 1>(&tmp);

	std::vector<V>		v_o;
	std::vector<V>		b_tmp;

	for (typename std::vector< std::pair<V,V> >::iterator i = tmp.begin(); i != tmp.end(); i++) {
		v_o.insert(v_o.begin(), i->first);
	}
	v_o.insert(v_o.begin(), tmp.end()->second);

	for (typename std::vector< std::pair<V,V> >::iterator i = tmp.begin(); i != tmp.end(); i++) {
		binary_insert(&v_o, v_o.begin(), v_o.end(), i->second);
	}
	if (remaind) {
		binary_insert(&v_o, v_o.begin(), v_o.end(), *remaind);
		delete remaind;
	}
	return ;
}
