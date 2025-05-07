/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:23:05 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:06 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cfloat>

enum ScalarType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

class Scalar
{
	public:
		static void convert(const std::string &value);
		
	private:
		Scalar();
		Scalar(const Scalar &src);
		Scalar &operator=(const Scalar &src);
		~Scalar();
	
		static ScalarType identifyType(const std::string &value);
		static bool isChar(const std::string &value);
		static bool isInt(const std::string &value);
		static bool isFloat(const std::string &value);
		static bool isDouble(const std::string &value);
		static bool isPseudo(const std::string &value);
		
		static void convertFromChar(char c);
		static void convertFromInt(int n);
		static void convertFromFloat(float f);
		static void convertFromDouble(double d);
		static void handlePseudo(const std::string &value);
};