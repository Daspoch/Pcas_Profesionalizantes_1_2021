#include <iostream>

int main()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;

    std::cin.ignore();
    std::cin.get();

    return 0;
}
