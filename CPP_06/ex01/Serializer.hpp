/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:57:51 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/05 21:57:52 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <stdint.h>
#include <exception>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cfloat>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();

		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};