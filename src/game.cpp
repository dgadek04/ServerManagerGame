#include <iostream>
#include "game.h"
#include "player.h"

void cls(){
    system("clear");
}
std::string player_input; 

void Game::start(){
    Player player;
    game_status = true;

    while(game_status == true){
        cls();
        std::cout<<"Balance:"<<" "<<player.get_balance()<<std::endl;
        std::cout<<"<Player>:"<<" ";std::cin>>player_input;


    }
}
void Game::stop(){
    game_status = false;
}