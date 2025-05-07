/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:21:35 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/05/07 10:53:03 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class test
{
    public:
    
        static void addTwo(int &num)
        {
            num += 2;
        }

        static void addThree(int &num)
        {
            num += 3;
        }

        static void changeCase(std::string &str)
        {
            int i = 0;
            while(str[i])
            {
                if(std::isupper(str[i]))
                    str[i] = std::tolower(str[i]);
                else
                    str[i] = std::toupper(str[i]);
                i++;
            }
        }
    private:
        test();
        test(const test &src);
        test &operator=(const test &src);
        ~test();
};

int main( void )
{
        
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << "          TEST 1 (addTwo)          " << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;  
    int	array1[] = {1 , 3, 5};
    std::cout << "((Before))" << std::endl;
    for (int i = 0; i < 3; i++)
    {
		std::cout << array1[i] << std::endl;
	}
    std::cout << "((After))" << std::endl;
    ::iter(array1, 3, test::addTwo);
	for (int i = 0; i < 3; i++)
    {
		std::cout << array1[i] << std::endl;
	}
    
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << "          TEST 2 (addThree)          " << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;   
    int	array2[] = {1 , 3, 5};
    std::cout << "((Before))" << std::endl;
    for (int i = 0; i < 3; i++)
    {
		std::cout << array2[i] << std::endl;
	}
    std::cout << "((After))" << std::endl;
	::iter(array2, 3, test::addThree);
		for (int i = 0; i < 3; i++)
        {
			std::cout << array2[i] << std::endl;
		}

    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << "          TEST 3 (changeCase)          " << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;    
    std::string	array3[] = {"black" , "start", "BlackOut", "UuUpPSsYYY"};
    std::cout << "((Before))" << std::endl;
    for (int i = 0; i < 3; i++)
    {
		std::cout << array3[i] << std::endl;
	}
    std::cout << "((After))" << std::endl;
	::iter(array3, 4, test::changeCase);
	for (int i = 0; i < 4; i++)
    {
		std::cout << array3[i] << std::endl;
	}
}