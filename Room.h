#ifndef ROOM_H
#define ROOM_H
#include "Item.h"
#include "GameCharacter.h"
#include <vector>
using std::vector;
class Room{
    public:
    int pos = 0;
    bool isexit = false;
    vector <Item> items;
    vector <GameCharacter> enemies;
    Room(int = 0, bool = false, vector<Item> = vector<Item>(), vector<GameCharacter> = vector<GameCharacter>());
    void clearLoot();
    void clearEnemies();
};
#endif
