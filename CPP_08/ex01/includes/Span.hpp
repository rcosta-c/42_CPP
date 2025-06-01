#pragma once

#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>

class Span
{
    public:
        Span(unsigned int x);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        void addnbr(int x);
        int shrtspan();
        int lngspan();

    private:
        unsigned int   _nbrLimit;
        std::vector<int> _numbers;
};

