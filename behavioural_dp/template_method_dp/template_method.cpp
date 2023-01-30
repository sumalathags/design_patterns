#include "template_method.hpp"

int main(){

    std::cout << '\n';

    QuickSort quick;
    Sort* sort = &quick;          // (5)
    sort->processData();

    std::cout << "\n\n";

    BubbleSort bubble;
    sort = &bubble;               // (6)
    sort->processData();

    std::cout << '\n';
  
}
Footer
© 2023 GitHub, Inc.
Footer navigation
Term