#include "../multi_array.hpp"

#include <iostream>

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
    eb::multi_array<int, 3, 2, 2> arr{3};
    eb::multi_array<int, 3, 2, 2> arr2{2};

    print(arr);
    print(arr2);

    //arr2(2, 1, 1) = 15;

    for(auto& i : arr)
        --i;



    print(arr2);

    if(arr == arr2)
        std::cout << "Equals !\n";
    else
        std::cout << "Not equals !\n";
}
