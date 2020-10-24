#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <queue>
#include <time.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <set>
#include <iterator>

class game {
    int level;

    //max y and x values for win and hud
    int win_y, win_x, hud_y, hud_x;

    int player_x, player_y, player_health, player_speed;
    int player_countdown;
    int player_score;
    bool bfb_used;
    const int max_projectiles=5;
    //y, x
    int projectiles[5][2];

    struct enemy {
        int y, x, health, projectile_y, projectile_x;
    };
    std::queue<enemy> all_enemies;

    int max_number_of_enemies;
    //y, x, health, projectile_y, projectile_x
    int enemies[25][5];

    struct powerup {
        int y, x, type;
    };
    std::queue<powerup> all_powerups;

    const int types_of_powerups = 3;
    char powerup_appearance[3] = {'#','*', '@'};

    const int max_number_of_powerups = 1;
    //y, x, type
    int powerups[1][3];
public:
    game();
    game(WINDOW * win, WINDOW * hud,int,int,int,int,int,int,int[5][5],int[1][3]);
    void display(WINDOW * win, WINDOW * hud);
    void update(int);
    bool isOver();
    // helper functions to access private game variables
    int getLevel();
    int getDimensions(int i);
    int getPlayer(int i);
    bool getFlag();
    int getPlayerX();
    int getPlayerY();
    int getPlayerSpeed();
    int getPlayerScore();
    int getPlayerHealth();
    void levelup();
    void setPos(int, int);
    game& operator=(game &g);
    // Player movement
    char playerMove(char);
    // Check if enemies are empty
    bool enemies_empty();
    //adds enemies to buffer queue
    void generate_enemies(int);
    //adds enemies to enemies[][] array
    void add_enemies();
    bool powerups_empty();
    //adds powerups to queue
    void generate_powerups(int);
    //adds powerups to array
    void add_powerups();
    //check value of player countdown time
    int get_player_countdown();
    //check whether bfb powerup is used
    bool get_bfb_used();
    //reduce countdown time
    void reduce_player_countdown();
};

//Functions for Leaderboard.txt

void saveLeaderboard(int score);
void displayLeaderBoard(WINDOW * mm, int menu_y, int menu_x);

#endif
