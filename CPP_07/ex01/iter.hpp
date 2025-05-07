#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

template <typename T>

void    iter(T *array, size_t length, void (*f)(T &))
{
    for (size_t i = 0; i < length; ++i)
    {
        f(array[i]);
    }
}