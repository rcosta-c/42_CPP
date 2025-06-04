/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:27:28 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/06/05 00:13:08 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _priceDatabase(copy._priceDatabase)
{}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if(this != &copy)
        _priceDatabase = copy._priceDatabase;
    return(*this);
}

float BitcoinExchange::getPriceForDate(const std::string& date)
{
    std::map<std::string, float>::iterator it = _priceDatabase.find(date);
    if (it != _priceDatabase.end())
    {
        return (it->second);
    }
    it = _priceDatabase.lower_bound(date);
    if (it == _priceDatabase.begin())
    {
        return (0.0);
    }
    --it;  // Volta para a data anterior
    return (it->second);
}

void BitcoinExchange::loadDB(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, commaPos));
        std::string priceStr = trim(line.substr(commaPos + 1));
        if (!ValidateDate(date))
            continue;       
        float price = std::atof(priceStr.c_str());
        _priceDatabase[date] = price;
    }
    file.close();
    if (_priceDatabase.empty())
    {
        throw std::runtime_error("Error: database is empty.");
    }
}


void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string line;
    if (std::getline(file, line))
    {
        if (line != "date | value")
        {
            file.seekg(0);
        }
    }
    while (std::getline(file, line))
    {
        if (line.empty())
            continue; 
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));
        if (!ValidateDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!ValidateValue(valueStr))
        {
            float val = std::atof(valueStr.c_str());
            if (val < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
            }
            else if (val > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
            }
            else
            {
                std::cout << "Error: bad input => " << line << std::endl;
            }
            continue;
        }
        float amount = std::atof(valueStr.c_str());
        float price = getPriceForDate(date);
        float result = amount * price;
        std::cout << date << " => " << amount << " = " << result << std::endl;
    }
    file.close();
}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::getDaysInMonth(int year, int month)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month - 1];
}

bool BitcoinExchange::ValidateDate(const std::string &date)
{
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    for (size_t i = 0; i < yearStr.length(); i++)
    {
        if (!isdigit(yearStr[i])) return false;
    }
    for (size_t i = 0; i < monthStr.length(); i++)
    {
        if (!isdigit(monthStr[i])) return false;
    }
    for (size_t i = 0; i < dayStr.length(); i++)
    {
        if (!isdigit(dayStr[i])) return false;
    }
    
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());
    if (year < 2009 || year > 2024)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > getDaysInMonth(year, month))
        return false;
    return true;
}

bool BitcoinExchange::ValidateValue(const std::string &value)
{
    std::string trimmedValue = trim(value);
    
    if (trimmedValue.empty())
        return false;
    char* endPtr;
    double val = std::strtod(trimmedValue.c_str(), &endPtr);
    
    if (endPtr == trimmedValue.c_str() || *endPtr != '\0')
        return false;
    if (val < 0)
        return false;
    if (val > 1000)
        return false;
    return true;
}
