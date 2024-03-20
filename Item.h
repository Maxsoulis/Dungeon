#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;
class Item{
    public:
    string name;
    int health, defense, attack;
    Item(string, int, int, int);
};
#endif
