/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:03:17 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/08 12:57:33 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main(void) {
	std::cout << "┌─────────────┐" << std::endl;
	std::cout << "│ MutantStack │" << std::endl;
	std::cout << "└─────────────┘" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << std::endl;
		while (it != ite)
		{
			std::cout << "\t[" <<*it << "]" << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl;
	std::cout << "┌──────┐" << std::endl;
	std::cout << "│ List │" << std::endl;
	std::cout << "└──────┘" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << std::endl;
		while (it != ite)
		{
			std::cout << "\t[" <<*it << "]" << std::endl;
			++it;
		}
	}

	return 0;
}

