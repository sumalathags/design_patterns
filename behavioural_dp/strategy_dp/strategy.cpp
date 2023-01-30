#include "strategy.hpp"

int main(int argc, char* argv[])
{
    Merge merge;
    Quick quick;
    Heap  heap;

    Sequential sequential;
    BinaryTree binaryTree;
    HashTable  hashTable;

    Collection colA;
    colA.set_sort(&quick);
    colA.sort();

    colA.set_sort(&merge);
    colA.sort();

    Collection colB;
    colB.set_search(&binaryTree);
    colB.search();

    colB.set_search(&hashTable);
    colB.search();

    return 0;
}