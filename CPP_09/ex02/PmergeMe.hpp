/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:47:51 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/05 00:11:07 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();

        void run(int ac, char **av);

    private:

        std::deque<int> _deque;
        std::vector<int> _vector;

        double _vecTime;
        double _deqTime;
        
        void vecFordJohnsonSort(std::vector<int>& arr);
        void vecFordJohnsonRecursive(std::vector<int>& arr, int left, int right);
        void vecMergeInsert(std::vector<int>& arr, int left, int mid, int right);
        void vecBinaryInsert(std::vector<int>& arr, int left, int right, int value);
        
        void deqFordJohnsonSort(std::deque<int>& arr);
        void deqFordJohnsonRecursive(std::deque<int>& arr, int left, int right);
        void deqMergeInsert(std::deque<int>& arr, int left, int mid, int right);
        void deqBinaryInsert(std::deque<int>& arr, int left, int right, int value);

};