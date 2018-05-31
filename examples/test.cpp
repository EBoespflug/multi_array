#include "../multi_array.hpp"

#include <iostream>

int main()
{
    eb::multi_array<int, 3, 5, 2, 5, 1, 6> arr;

    std::cout << arr.size() << '\n';
}
