#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H
#include <string>
using std::string;
class GameCharacter{
    public: 
    string name;
    int currentHealth, maxHealth, attack, defense;
    GameCharacter(string, int, int, int);
    int takeDamage(int);
    bool checkisDead();
};
#endif
