/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:38:51 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/18 11:08:56 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void)src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::sortVector(std::vector<int> &arr)
{
	this->_fordJohnsonSort(arr);
}

void	PmergeMe::sortList(std::list<int> &arr)
{
	this->_fordJohnsonSort(arr);
}


long PmergeMe::_jacobNum(long n)
{   
	return (round((pow(2, n + 1) + pow(-1, n)) / 3));
}
