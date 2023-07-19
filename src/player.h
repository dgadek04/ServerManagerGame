#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
class Player{
    
    private:
    int balance;
    public:
    int servers_owned = 0;
    std::vector<std::string> server_list;
    int get_balance();
    void set_balance(int new_balance);
    
    };

#endif // PLAYER_H