#include "Structures/List.h"

#include <iostream>
#include <string>
#include <list>


int main()
{
    pms::List<int> my_list;
    int a = 0;

    for (int j = 0; j < 5; ++j)
    {
        std::cout << "Enter a number to start: ";
        std::cin >> a;

        for (int i = 0; i < 1000000; ++i)
        {
            my_list.InsertHead(i);
        }

        std::cout << "Enter a number to clear the list: ";
        std::cin >> a;

        for (int i = 0; i < 1000000; ++i)
        {
            my_list.RemoveHead();
        }
    }

    std::cout << "Enter a number to end: ";
    std::cin >> a;

    return 0;
}
