/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:33:24 by rcosta-c          #+#    #+#             */
/*   Updated: 2025/04/15 00:33:25 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Right way to use this tool: ./Sed <filename> <oldword> <newword>" << std::endl;
        return (1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string newfilename = filename + ".replace";
    if (s1.empty())
    {
        std::cout << "Error: Empty string to replace" << std::endl;
        return (1);
    }
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cout << "Error: Can't open input file" << std::endl;
        return (1);
    }
    std::ofstream outfile(newfilename.c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error: Can't create output file" << std::endl;
        infile.close();
        return (1);
    }    
    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
    }
    infile.close();
    outfile.close();
    return (0);
}