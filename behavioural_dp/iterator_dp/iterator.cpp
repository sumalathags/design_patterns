#include <iostream>
#include <vector>

int main()
{
    std::vector<int>           numbers  = { 1, 2, 3, 4, 5 };
    std::vector<int>::iterator iterator = numbers.begin();
    while (iterator != numbers.end())
    {
        std::cout << *iterator << std::endl;
        iterator++;
    }
    return 0;
}
