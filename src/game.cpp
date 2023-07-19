#include <iostream>
#include <thread>
#include <chrono>
#include "game.h"
#include "player.h"

void cls() {
    system("clear");
}

class Server {
public:
    std::string name;
    bool is_owned = false;
    int cost;
    int ram;
};

void income(Player& player, Server& server, int worth, int delay_seconds) {
    while(true){
        while (server.is_owned) {
            std::this_thread::sleep_for(std::chrono::seconds(delay_seconds));
            player.set_balance(player.get_balance() + worth);
            }
        }
    }

std::string player_input;

void Game::start() {
    // Initialize first server.
    Server server1;
    server1.name = "testserver";
    server1.cost = 400;
    server1.ram = 4 * 1024;

    Player player;
    player.set_balance(400);

    game_status = true;

    std::thread incomeThread(income, std::ref(player), std::ref(server1), 10, 10); // Start the income generation thread // This takes in the function 'income' (&Player, worth, delay in seconds)

    while (game_status) {
        cls();
        std::cout << "Balance: " << player.get_balance() << std::endl;
        std::cout << "Servers: " << player.servers_owned << std::endl;
        std::cout << "<Player>: ";

        std::cin >> player_input;

        if (player_input == "buy") {
            if (!server1.is_owned) {
                player.servers_owned = 1;
                player.server_list.push_back(server1.name);
                player.set_balance(player.get_balance() - server1.cost);
                server1.is_owned = true; // Update the ownership flag
            }
        }
        else if (player_input == "sell") {
            if (server1.is_owned) {
                player.servers_owned = 0;
                player.server_list.clear();
                player.set_balance(player.get_balance() + server1.cost);
                server1.is_owned = false; // Update the ownership flag
            }
        }
        else {
            cls();
            std::cout << "Incorrect argument" << std::endl;
        }
    }

    server1.is_owned = false; // Stop the income generation thread before exiting
    incomeThread.join();
}

void Game::stop() {
    game_status = false;
}
