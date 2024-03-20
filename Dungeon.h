#ifndef DUNGEON_H
#define DUNGEON_H
#include "Player.h"
#include "Room.h"
class Dungeon{
    public: 
    Player player;
    Room rooms[4];
    Dungeon(Player);
    int runDungeon();
    void enterRoom(Room*);
    void handleEmptyRoom(Room*);
    void handleLootRoom(Room*);
    void handleEnemyRoom(Room*);
    void handleLootActions(Room*);
    void handleFightActions(GameCharacter*);
    void handleMovementActions(Room*);
    void printActions(int, string[]);
    int performEndgameLogic();



};
#endif
