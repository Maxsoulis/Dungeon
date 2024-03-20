#include "Room.h"

Room::Room(int p, bool ie,vector<Item> it, vector<GameCharacter> e ){
    pos = p;
    isexit = ie;
    items = it;
    enemies = e;
}
    void Room::clearLoot(){
        items.clear();
    }
    void Room::clearEnemies(){
        enemies.clear();
    }
