#include "GameCharacter.h"
GameCharacter::GameCharacter(string n, int h, int a, int d){
    name = n;
    currentHealth = h;
    maxHealth = h;
    attack = a;
    defense = d;
}
int GameCharacter::takeDamage(int amount){
    int damage = amount - defense;
    if(damage < 0){
        damage = 0;
    }
    currentHealth -= damage;
    return damage;
}
bool GameCharacter::checkisDead(){
    return currentHealth <= 0;
}
