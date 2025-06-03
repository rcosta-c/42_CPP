/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:47:51 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/03 15:00:25 by rcosta-c         ###   ########.fr       */
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
        
        void mergeInsertSort(std::vector<int>& arr);
        void insertIntoSorted(std::vector<int>& sorted, int value);
        
        void mergeInsertSort(std::deque<int>& arr);
        void insertIntoSorted(std::deque<int>& sorted, int value);

};