#include "../multi_array.hpp"

#include <iostream>

int main()
{
    eb::multi_array<int, 2, 2> arr{12};

    std::cout << arr.size() << '\n';
}
