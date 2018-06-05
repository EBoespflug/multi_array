#include "../multi_array.hpp"

#include <iostream>
#include <numeric>

template<typename Container>
void print(Container c)
{
    std::cout << c.size() << '\n';
    for(auto&& v : c)
        std::cout << v << ' ';
    std::cout << '\n';
}

int main()
{
    eb::multi_array<int, 3, 2, 2> arr1{0};
    eb::multi_array<int, 3, 2, 2> arr2{0};

    std::iota(arr1.begin(), arr1.end(), 1);

    print(arr1);
    print(arr2);

    arr2(0, 0, 0) = 0;
    arr2(0, 0, 1) = 1;
    arr2(0, 1, 0) = 2;
    arr2(0, 1, 1) = 3;
    arr2(1, 0, 0) = 4;
    arr2(1, 0, 1) = 5;
    arr2(1, 1, 0) = 6;
    arr2(1, 1, 1) = 7;
    arr2(2, 0, 0) = 8;
    arr2(2, 0, 1) = 9;
    arr2(2, 1, 0) = 10;
    arr2(2, 1, 1) = 11;

    for(auto& i : arr1)
        --i;

    print(arr1);
    print(arr2);

    if(arr1 == arr2)
        std::cout << "Equals !\n";
    else
        std::cout << "Not equals !\n";
}
