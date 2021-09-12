#include "Structures/List.h"

#include <iostream>
#include <string>
#include <list>


int main()
{
    pms::List<int> my_list;
    int a = 0;

    std::cout << "Enter a number to start: ";
    std::cin >> a;

    for (int i = 0; i < 100000; ++i)
    {
        my_list.InsertHead(i);
    }

    std::cout << "Enter a number to clear the list: ";
    std::cin >> a;

    /*for (int i = 0; i < 100000; ++i)
    {
        my_list.RemoveHead();
    }*/
    my_list.Clear();

    std::cout << "Enter a number to start (2): ";
    std::cin >> a;

    for (int i = 0; i < 100000; ++i)
    {
        my_list.InsertHead(i);
    }

    std::cout << "Enter a number to clear the list: ";
    std::cin >> a;

    /*for (int i = 0; i < 100000; ++i)
    {
        my_list.RemoveHead();
    }*/
    my_list.Clear();

    std::cout << "Enter a number to start (3): ";
    std::cin >> a;

    for (int i = 0; i < 100000; ++i)
    {
        my_list.InsertHead(i);
    }

    std::cout << "Enter a number to clear the list: ";
    std::cin >> a;

    /*for (int i = 0; i < 100000; ++i)
    {
        my_list.RemoveHead();
    }*/
    my_list.Clear();

    std::cout << "Enter a number to end: ";
    std::cin >> a;

    return 0;
}
