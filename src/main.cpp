#include "Structures/list.h"

#include <iostream>
#include <string>
#include <list>

class Car
{
    public:
        std::string car_plate;
        double price;

    public:
        Car() {};
        Car(std::string car_plate, double price) : car_plate(car_plate), price(price) {};

        // for printing
        friend std::ostream& operator<< (std::ostream& os, const Car& car);

        inline bool operator==(const Car& rhs) const { return (this->car_plate == rhs.car_plate) && (this->price == rhs.price); };
        inline bool operator<(const Car& rhs) const { return this->car_plate < rhs.car_plate; };
};

std::ostream& operator<< (std::ostream& os, const Car& car)
{
    os << car.car_plate << ", " << car.price;
    return os;
}

template <typename T>
void PrintDebug(pms::List<T> dll)
{
    // --------------------
    // debug
    std::cout << "list size: " << dll.Size() << std::endl;
    std::cout << "list: ";
    if (dll.Size() != 0)
    {
        for (size_t i = 0; i < dll.Size(); ++i) { std::cout << dll.At(i); if (i != dll.Size() - 1) { std::cout << " | "; } }
        std::cout << "\n";
    }
    else
        std::cout << "\n";

    std::cout << "head: ";
    if (dll.Size() != 0)
        std::cout << dll.Head() << std::endl;
    else
        std::cout << "\n";

    std::cout << "tail: ";
    if (dll.Size() != 0)
        std::cout << dll.Tail() << std::endl;
    else
        std::cout << "\n";

    std::cout << "\n" << std::endl;

    // debug
    // --------------------
}

int main()
{
    //std::list<Car> l;
    //std::cout << "l.front: " << l.front() << "\n" << std::endl;

    pms::List<Car> dll;

    PrintDebug(dll);
    dll.InsertHead(Car("ABC1234", 120000.0));
    PrintDebug(dll);
    dll.InsertHead(Car("XYZ2345", 230000.0));
    PrintDebug(dll);
    dll.InsertHead(Car("ABC1234", 145000.0));
    PrintDebug(dll);

    std::cout << "(\"ABC1234\", 120000.0) Index: " << dll.Search(Car("ABC1234", 120000.0)) << "\n" << std::endl;

    PrintDebug(dll);
    dll.Swap(0,1);
    PrintDebug(dll);

    std::cout << "SORTING:" << std::endl;
    PrintDebug(dll);
    dll.Sort();
    PrintDebug(dll);
    
    dll.Clear();
    PrintDebug(dll);

    return 0;
}
