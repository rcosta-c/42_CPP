#pragma once
#include <string>
#include <iostream>
#include <exception>

class Scalar
{
	public:
		Scalar(void);
		Scalar(std::string str);
		Scalar(Scalar const &copy);
		Scalar &operator=(const Scalar &copy);
		~Scalar();
	
		void convert();

	private:
		std::string _str;
};