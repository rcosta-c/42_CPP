/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:47:55 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/05 00:11:00 by rcosta-c         ###   ########.fr       */
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
    return(*this);
}

PmergeMe::~PmergeMe()
{}


void PmergeMe::vecBinaryInsert(std::vector<int>& arr, int left, int right, int value)
{
    std::vector<int>::iterator pos = std::lower_bound(arr.begin() + left, arr.begin() + right, value);
    arr.insert(pos, value);
}

void PmergeMe::vecMergeInsert(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> temp;
    int i = left;
    int j = mid + 1;
    
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);
    for (size_t k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

void PmergeMe::vecFordJohnsonRecursive(std::vector<int>& arr, int left, int right)
{
    if (right - left <= 16)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }
    
    int mid = left + (right - left) / 2;
    vecFordJohnsonRecursive(arr, left, mid);
    vecFordJohnsonRecursive(arr, mid + 1, right);
    vecMergeInsert(arr, left, mid, right);
}

void PmergeMe::vecFordJohnsonSort(std::vector<int>& arr)
{
    if (arr.size() <= 1) return;
    vecFordJohnsonRecursive(arr, 0, arr.size() - 1);
}



void PmergeMe::deqBinaryInsert(std::deque<int>& arr, int left, int right, int value)
{
    std::deque<int>::iterator pos = std::lower_bound(arr.begin() + left, arr.begin() + right, value);
    arr.insert(pos, value);
}

void PmergeMe::deqMergeInsert(std::deque<int>& arr, int left, int mid, int right)
{
    std::deque<int> temp;
    int i = left;
    int j = mid + 1;
    
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    
    while (j <= right)
        temp.push_back(arr[j++]);
    for (size_t k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

void PmergeMe::deqFordJohnsonRecursive(std::deque<int>& arr, int left, int right)
{
    if (right - left <= 16)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        return;
    }
    
    int mid = left + (right - left) / 2;
    deqFordJohnsonRecursive(arr, left, mid);
    deqFordJohnsonRecursive(arr, mid + 1, right);
    deqMergeInsert(arr, left, mid, right);
}

void PmergeMe::deqFordJohnsonSort(std::deque<int>& arr)
{
    if (arr.size() <= 1) return;
    deqFordJohnsonRecursive(arr, 0, arr.size() - 1);
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
    vecFordJohnsonSort(vecCopy);
    clock_t end = clock();
    _vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    
    start = clock();
    deqFordJohnsonSort(deqCopy);
    end = clock();
    _deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    
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