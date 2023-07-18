#include "player.h"
#include <iostream>

int Player::get_balance(){
    return balance;
}
void Player::set_balance(int new_balance){
    balance = new_balance;
}
