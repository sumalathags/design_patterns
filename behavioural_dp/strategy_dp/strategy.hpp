#include <iostream>

class SortBehavior
{
public:
    virtual void sort() const = 0;
};
class Merge : public SortBehavior
{
public:
    virtual void sort() const { std::cout << "Merge sort()\n"; }
};
class Quick : public SortBehavior
{
public:
    virtual void sort() const { std::cout << "Quick sort()\n"; }
};
class Heap : public SortBehavior
{
public:
    virtual void sort() const { std::cout << "Heap sort()\n"; }
};
// ================================
class SearchBehavior
{
public:
    virtual void search() const = 0;
};
class Sequential : public SearchBehavior
{
public:
    virtual void search() const { std::cout << "Sequential search()\n"; }
};
class BinaryTree : public SearchBehavior
{
public:
    virtual void search() const { std::cout << "BinaryTree search()\n"; }
};
class HashTable : public SearchBehavior
{
public:
    virtual void search() const { std::cout << "HashTable search()\n"; }
};
// Context
class Collection
{
private:
    SortBehavior*   m_sort;
    SearchBehavior* m_search;

public:
    Collection() {}
    void set_sort(SortBehavior* s) { m_sort = s; }
    void set_search(SearchBehavior* s) { m_search = s; }
    void sort() const { m_sort->sort(); }
    void search() const { m_search->search(); }
};