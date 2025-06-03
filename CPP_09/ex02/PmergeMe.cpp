/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:47:55 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/03 15:00:04 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0)
{}

PmergeMe::PmergeMe(const PmergeMe &copy) : _deque(copy._deque), _vector(copy._vector), 
      _vecTime(copy._vecTime), _deqTime(copy._deqTime) 
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if(this != &copy)
    {
        _deque = copy._deque;
        _vector = copy._vector;
        _vecTime = copy._vecTime;
        _deqTime = copy._deqTime;
    }
        *this= copy;
    return(*this);
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::insertIntoSorted(std::vector<int>& sorted, int value)
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

void PmergeMe::insertIntoSorted(std::deque<int>& sorted, int value)
{
    std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

void PmergeMe::mergeInsertSort(std::vector<int>& arr)
{
    if (arr.size() <= 1) return;
    
    std::vector<int> sorted;
    sorted.push_back(arr[0]);
    for (size_t i = 1; i < arr.size(); ++i)
    {
        insertIntoSorted(sorted, arr[i]);
    }
    arr = sorted;
}

void PmergeMe::mergeInsertSort(std::deque<int>& arr)
{
    if (arr.size() <= 1) return;
    
    std::deque<int> sorted;
    sorted.push_back(arr[0]);
    for (size_t i = 1; i < arr.size(); ++i)
    {
        insertIntoSorted(sorted, arr[i]);
    }
    arr = sorted;
}


void PmergeMe::run(int ac, char** av)
{
    for (int i = 1; i < ac; ++i)
    {
        for (int j = 0; av[i][j]; ++j)
        {
            if (!isdigit(av[i][j]))
            {
                std::cerr << "Error" << std::endl;
                return;
            }
        }
        int num = std::atoi(av[i]);
        if (num <= 0)
        {
            std::cerr << "Error" << std::endl;
            return;
        }
        _vector.push_back(num);
        _deque.push_back(num);
    }
    if (_vector.empty())
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << "Before:";
    for (size_t i = 0; i < _vector.size() && i < 5; ++i)
        std::cout << " " << _vector[i];
    if (_vector.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
    
    std::vector<int> vecCopy = _vector;
    std::deque<int> deqCopy = _deque;
    
    clock_t start = clock();
    mergeInsertSort(vecCopy);
    clock_t end = clock();
    _vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    
    start = clock();
    mergeInsertSort(deqCopy);
    end = clock();
    _deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    
    std::cout << "After:";
    for (size_t i = 0; i < vecCopy.size() && i < 5; ++i)
        std::cout  << " " << vecCopy[i];
    if (vecCopy.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque : " << _deqTime << " us" << std::endl;
}