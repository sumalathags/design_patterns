#include "visitor.hpp"

int main()
{
    Stock* set[] = { new Apple, new Google, new Google, new Apple, new Apple, 0 };

    BuyVisitor  buy_operation;
    SellVisitor sell_operation;
    for (int i = 0; set[i]; i++)
    {
        set[i]->accept(&buy_operation);
    }
    buy_operation.total_stocks();

    for (int i = 0; set[i]; i++)
    {
        set[i]->accept(&sell_operation);
    }
    sell_operation.total_stocks();
}