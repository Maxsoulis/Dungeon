#include "Dungeon.h"
#include <iostream>
Dungeon::Dungeon(Player p){
    player = p;
}
void Dungeon::printActions(int numActions, string actions[]){
    std::cout << "Enter an action" << '\n';
    for(int i = 0; i < numActions; i++){
        std::cout << actions[i];
    }
}

void Dungeon::handleEmptyRoom(Room *room){
    std::cout << "You entered an empty room" << '\n';
    string actions[] = {"a. Move to another room "};
    while(true){
        printActions(1, actions);
        char input = ' ';
        std::cin >> input;
        if(input == 'a'){
            return;
        }
        else {
            std::cout << "That is not an available choice" << '\n';
        }
    }
}
void Dungeon::handleLootActions(Room* room){
    Item item = room-> items.front();
    int size = room -> items.size();
    player.lootRoom(room);
    room -> clearLoot();
    for(int i = 0; i < size; i++ ){
        std::cout << "You open the chest and you find a " << item.name << '\n';
    
    }
     
}
void Dungeon::handleLootRoom(Room *room){


    std::cout << "You entered a loot room" << '\n';
    string actions[] = { "a. Loot chest ", "b. Move to another room "};
    while(true){
        printActions(2, actions);
        char input = ' ';
        std::cin >> input;
        if(input == 'a'){
            handleLootActions(room);
            return;
        }
        else if(input =='b'){
            return;
        }
        else {
            std::cout << "That is not an available choice" << '\n';
        }
}
}
void Dungeon::handleFightActions(GameCharacter *enemy){
    string actions[] = { 
        "a. Attack " , 
        "b. Retreat "};
    while(true){
        printActions(2, actions);
        char input = ' ';
        std::cin >> input;
        if(input == 'a'){
            int damage = enemy->takeDamage(player.attack);
            std::cout << "You did " << damage << " hitpoints of damage to the " << enemy -> name << '\n';
            
        }
        else if(input =='b'){
            player.changeRooms(player.previousRoom);
            enterRoom(player.currentRoom);
            return;
        }
        else {
            std::cout << "That is not an available choice" << '\n';
        }
        if(enemy->checkisDead()){
            std::cout << "You have defeated the " << enemy -> name << '\n';
            player.increaseStats(10, 5, 5);
            player.currentRoom-> clearEnemies();
            return;
        }
        int damage = player.takeDamage(enemy->attack);
        std::cout << "The " << enemy -> name << " did " << damage << '\n';
        std::cout << "You have " << player.currentHealth << " hitpoints left." << '\n';
}
}  
void Dungeon::handleEnemyRoom(Room *room){
    GameCharacter enemy = room-> enemies.front();
    std::cout << "You enter a room and see a "<< enemy.name << " "<< '\n';
    string actions[] = { 
        "a. Fight the " + enemy.name + " ", 
        "b. Go back to previous room "};
    while(true){
        printActions(2, actions);
        char input = ' ';
        std::cin >> input;
        if(input == 'a'){
            handleFightActions(&enemy);
            return;
        }
        else if(input =='b'){
            player.changeRooms(player.previousRoom);
            enterRoom(player.currentRoom);
            
        }
        else {
            std::cout << "That is not an available choice " << '\n';
        }
}
}
void Dungeon::enterRoom(Room * room){
    if(room -> enemies.size() != 0){
        handleEnemyRoom(room);
    }
    else if(room -> items.size() != 0){
         handleLootRoom(room);
    }
    else {
        handleEmptyRoom(room);
    }
}
void Dungeon::handleMovementActions(Room * room){
    while(true){
    if(room->pos == 0){
        string actions[] = {"a. Move right", " b. Move down"};
        printActions(2, actions);
        string input;
        std::cin >> input; 
         if(input == "a"){
            player.changeRooms(&rooms[1]);
            return;
        }
        else if(input == "b"){
            player.changeRooms(&rooms[2]);
            return;
        }
        else std::cout << "Incorrect choice" << '\n';
          
        

    }
    else if(room->pos == 1){
        string actions[] = {"a. Move left" };
        printActions(1, actions);
        string input;
        std::cin >> input; 
         if(input == "a"){
            player.changeRooms(&rooms[0]);
            return;
        }  
        else std::cout << "Incorrect choice" << '\n';
    }
    else if(room->pos == 2){
        string actions[] = {"a. Move right", " b. Move up"};
        printActions(2, actions);
        string input;
        std::cin >> input; 
         if(input == "a"){
            player.changeRooms(&rooms[3]);
            return;
        }
        else if(input == "b"){
            player.changeRooms(&rooms[0]);
            return;
        }
        else std::cout << "Incorrect choice" << '\n';
    }
    else {
        string actions[]= {"a. Move left" };
        printActions(1, actions);
        string input;
        std::cin >> input; 
         if(input == "a"){
            player.changeRooms(&rooms[2]);
            return;
        }
        else std::cout << "Incorrect choice" << '\n';
    }
    }
}
int Dungeon::performEndgameLogic(){
    string actions[] = {"a. Yes", "b. No"};
    while(true){
    printActions(2, actions);
    string input;
    std::cin>> input;
    if(input == "a"){
        return 1;
    }
    else if (input == "b"){
        return 0;
    }
    else {
        std::cout << "Incorrect choice " << "\n";
    }
    }
     
}
int Dungeon::runDungeon(){
    std::cout << "Welcome to the dungeon! Inside you will find rooms that have enemies and loot" << '\n';
    player.currentRoom = &rooms[0];
    player.previousRoom = &rooms[0];

    while(true){
        enterRoom(player.currentRoom);
        if(player.checkisDead()){
            std::cout << "Game over, Try again?" << '\n';
            return performEndgameLogic();
        }
        else {
            if(player.currentRoom->isexit ){
                if(player.currentRoom->enemies.size() == 0){
                  std::cout << "You win, Play again"  << '\n';
                  return performEndgameLogic();
                }
            }
        }
        handleMovementActions(player.currentRoom);
    }
}
