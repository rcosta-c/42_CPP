/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:27:31 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/02 23:27:33 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>


class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        void loadDB(const std::string &db);
        void processInput(const std::string &input);
        float getPriceForDate(const std::string &date);

    private:
        bool ValidateDate(const std::string &date);
        bool ValidateValue(const std::string &value);
    
        std::string trim(const std::string &str);
        bool isLeapYear(int year);
        int getDaysInMonth(int year, int month);


        std::map<std::string, float> _priceDatabase;
};