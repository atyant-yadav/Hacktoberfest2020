#include "newGame.h"

game::game() {
    // Default constructor
    // Screen settings
    win_y = 0;
    win_x = 0;
    hud_y = 5;
    hud_x = 0;
    getmaxyx(stdscr, win_y, win_x);
    win_y -= 6;
    hud_x = win_x;
    // Player coordinates
    player_x = win_x / 2;
    player_y = (win_y / 6) * 5;
    // Player attributes
    player_health=3;
    player_speed=2;
    player_score=0;
    player_countdown=0;
    // Enemy cap - for level progression
    max_number_of_enemies = 5;
    level = 1;
    // BFB Powerup flag
    bfb_used = false;
    // Projectile array setup
    for(int i = 0; i < max_projectiles; i++) {
        projectiles[i][0] = -10;
	    projectiles[i][1] = -10;
    }
    // Enemy array setup
    for(int i = 0; i < max_number_of_enemies; i++) {
        enemies[i][0] = -1;
	    enemies[i][1] = -1;
    }
}

game::game(WINDOW * win, WINDOW * hud, int lvl, int px, int py, int ps, int pscore, int ph, int pe[5][5], int pu[1][3]) {
    // Parameterised constructor
    // Setup screen attributes
    getmaxyx(win, win_y, win_x);
    getmaxyx(hud, hud_y, hud_x);
    // Set player attributes, flags and enemy cap
    level = lvl;
    player_x = px;
    player_y = py;
    player_health = ph;
    player_speed = ps;
    player_score = pscore;
    player_countdown = 0;
    max_number_of_enemies = 5;
    bfb_used = false;
    std::cerr << "Assignment complete\n";
    // Projectile setup
    for(int i = 0; i < max_projectiles; i++) {
        projectiles[i][0] = -10;
	    projectiles[i][1] = -10;
    }
    std::cerr << "Projectiles set\n";
    // Enemy setup
    for(int i = 0; i < max_number_of_enemies; i++) {
        for(int stat = 0; stat < 5; stat++)
	        enemies[i][stat] = pe[i][stat];
    }
    std::cerr << "Enemies set\n";
    // Powerup setup
    for(int i = 0; i < max_number_of_powerups; i++) {
        for(int stat = 0; stat < 3; stat++)
	        powerups[i][stat] = pu[i][stat];
    }
    std::cerr << "Powerups set\n";
}

void game::display(WINDOW * win, WINDOW * hud) {

    //display player
    wmove(win, player_y, player_x);
    waddstr(win, " ^ ");
    wmove(win, player_y+1, player_x);
    waddstr(win, "/#\\");
    wmove(win, player_y+2, player_x);
    waddstr(win, "H#H");

    //display player projectiles
    for(int i = 0; i < max_projectiles; i++) {
        if(projectiles[i][0] == -10)
            continue;
	wmove(win, projectiles[i][0], projectiles[i][1]);
	waddch(win, '!');
    }

    //display enemies
    for(int i = 0; i < max_number_of_enemies; i++) {
        // Check if enemy is off-screen[0] or dead[2]
        if(enemies[i][0] == -1 || enemies[i][2] == -1)
            continue;

        // Variables to make life easy
        int enemy_y = enemies[i][0], enemy_x = enemies[i][1];
	    bool overlap = false;

	    //check overlapping between player and enemy (enemies[i])
	    for(int a = player_x - 2; a < player_x + 2; a++)
            for(int b = player_y; b < player_y + 3; b++)
                if(enemy_y == b && enemy_x == a)    {
                    overlap = true;
                    player_health--;
                }

	    //check if enemy hit by projectile
	    for(int a = 0; a < max_projectiles; a++) {
            if(enemy_y > projectiles[a][0] && (enemy_x - 1 == projectiles[a][1] || enemy_x == projectiles[a][1] || enemy_x + 1 == projectiles[a][1] || enemy_x + 2 == projectiles[a][1]))  {
                //Enemy overlaps projectiles
                overlap = true;
            }
	    }

	    //if overlapping or hit - set enemy health to -1, and skip display
        if(overlap) {
            enemies[i][0] = -1;
            enemies[i][1] = -1;
            enemies[i][2] = -1;
            enemies[i][3] = -1;
            enemies[i][4] = -1;
	        continue;
	    }

	    //display enemy. only 1 kind so far
	    wmove(win, enemy_y, enemy_x);
	    waddstr(win, "O-O");

	    //display powerup
	    for(int j = 0; j < max_number_of_powerups; j++) {

	        //if powerup overlaps with enemy
	        if((powerups[j][0] == -1) || (powerups[j][0] == enemy_y && powerups[j][1] >= enemy_x - 1 && powerups[j][1] <= enemy_x + 3)) {
	            powerups[j][0] = -1;
	        }

            //if powerup overlaps with player
            if((powerups[j][0] >= player_y) && (powerups[j][0] <= player_y + 2) && (powerups[j][1] >= player_x - 2) && (powerups[j][1] <= player_x + 2))    {
                powerups[j][0] = -1;
                switch(powerups[j][2])  {
                    case 0: //extra life powerup
                            player_health++;
                            break;
                    case 1: //BFB powerup
                            player_score += 10;
                            for (int k = 0; k < max_number_of_enemies; k++) {
                                enemies[k][0] = -1;
                                enemies[k][1] = -1;
                                enemies[k][2] = -1;
                                enemies[k][3] = -1;
                                enemies[k][4] = -1;
                            }
                            player_countdown = 100;
                            bfb_used = true;
                            break;
                    case 2: // fast movement powerup
                            player_countdown = 300;
                            player_speed += 2;
                            break;
                }
            }

	        //to make sure powerup y,x are within WINDOW * win. Stops powerup from "sticking" to enemies
	        else if(powerups[j][0] >= 0 && powerups[j][1] >= 0 && powerups[j][0] <= win_y - 1 && powerups[j][1] <= win_x - 1) {
	            wmove(win, powerups[j][0], powerups[j][1]);
	            waddch(win, powerup_appearance[powerups[0][2]]);
	        }
	    }
    } 

    //displaying the HUD

    //line separating win and hud
    for(int i = 0; i < hud_x; i++) {
        waddch(hud, '_');
    }

    //display Level
    wmove(hud, hud_y/2, hud_x/5);
    std::string lvl = "Level: " + std::to_string(level);
    waddstr(hud, lvl.c_str());

    //display player_health
    wmove(hud, hud_y/2, hud_x/5*3);
    for(int i = 0; i < player_health; i++) {
        waddstr(hud,"O ");
    }

    //display score
    wmove(hud, hud_y/2 + 2, hud_x/2 - 7);
    std::string scr = "Score: " + std::to_string(player_score);
    waddstr(hud, scr.c_str());
}

void game::update(int tick) {

    //update player projectiles
    for(int i = 0; i < max_projectiles; i++) {
        if(projectiles[i][0] == -10) continue;
	projectiles[i][0] = (projectiles[i][0] == 0) ? -10 : projectiles[i][0] - 1;
    }

    //only update enemies every 15 ticks
    if(tick % 15 == 0) {
        for(int i = 0; i < max_number_of_enemies; i++) {
            if(enemies[i][0] == -1 || enemies[i][2] == -1) 
                continue;

	    enemies[i][0] = (enemies[i][0] == win_y) ? enemies[i][0] : enemies[i][0] + 1;
            // took a chunk from here to update enemy status and prevent "ghost" enemies
        }
    }

    //placed the chunk outside the 15 tick block to eliminate respawning indestructible "ghost" enemies
    for (int i = 0; i < max_number_of_enemies; i++) {
        //enemy reaches end of map
	    if(enemies[i][0] == win_y) {
            	player_health--;

		    //reset enemy to default
		    for(int reset = 0; reset < 5; reset++) {
		        enemies[i][reset] = -1;
		    }
	    }
    }

    //if enemy gets hit by player projectile
    for(int i = 0; i < max_number_of_enemies; i++) {
        for(int j = 0; j < max_projectiles; j++) {
            if((enemies[i][1] - 2 == projectiles[j][1] || enemies[i][1] - 1 == projectiles[j][1] || enemies[i][1] == projectiles[j][1] || enemies[i][1] + 1 == projectiles[j][1] || enemies[i][1] + 2 == projectiles[j][1]) && enemies[i][0] >= projectiles[j][0] && projectiles[j][0] != -10) {
                player_score++;
                enemies[i][2]--;
                //check for enemy death
                projectiles[j][0] = -10;
                projectiles[j][1] = -10;
            }
            if (enemies[i][2] < 0) {
                // Reset dead enemies
                for(int reset = 0; reset < 5; reset++) {
		            enemies[i][reset] = -1;
		        }
            }
	    }
    }
    //powerups
    if(tick % 15 == 0)  {
        // update powerup status
        for(int i = 0; i < max_number_of_powerups; i++) {
	        if(powerups[i][0] == -1)
	            continue;
            powerups[i][0] = (powerups[i][0] == win_y) ? -1 : powerups[i][0] + 1;
        }
    }

    // check powerup countdown and powerup flags 
    if(player_countdown <= 0 && player_speed > 2)    {
        player_countdown = 0;
        player_speed = 2;
    }

    else if (player_countdown <= 0 && bfb_used == true) {
        player_countdown = 0;
        bfb_used = false;
    }

    if (player_countdown > 0)   {
        player_countdown--;
    }
}

bool game::isOver() {
    // return game over status
    if(player_health <= 0) 
        return true;
    return false;
}

int game::getLevel()    {
    // return game level
    return level;
}

int game::getDimensions(int i) {
    // return dimensions of screen
    int a[4];
    a[0] = win_y;
    a[1] = win_x;
    a[2] = hud_y;
    a[3] = hud_x;
    return a[i];
}

int game::getPlayer(int i) {
    //return dimensions of the player
    int a[5];
    a[0] = player_x;
    a[1] = player_y;
    a[2] = player_health;
    a[3] = player_speed;
    a[4] = player_countdown;
    return a[i];
}

bool game::getFlag()    {
    //get flag for BFB powerup
    return bfb_used;
}

int game::getPlayerX()  {
    return player_x;
}

int game::getPlayerY()  {
    return player_y;
}

int game::getPlayerSpeed()  {
    return player_speed;
}

int game::getPlayerScore()  {
    return player_score;
}

int game::getPlayerHealth() {
    return player_health;
}

void game::levelup()    {
    level++;
    // Increment enemy cap for level progression
    if (max_number_of_enemies <= 25)
        max_number_of_enemies++;
}

void game::setPos(int x, int y)   {
    // Set player position
    player_x = x;
    player_y = y;
}

game& game::operator=(game &g)  {
    // assignment operator overloading to copy game from one object to another
    level = g.getLevel();
    win_y = g.getDimensions(0);
    win_x = g.getDimensions(1);
    hud_y = g.getDimensions(2);
    hud_x = g.getDimensions(3);
    player_x = g.getPlayer(0);
    player_y = g.getPlayer(1);
    player_health = g.getPlayer(2);
    player_speed = g.getPlayer(3);
    player_score = g.getPlayerScore();
    player_countdown = g.getPlayer(4);
    bfb_used = g.getFlag();
    return *this;
}

char game::playerMove(char move) {
    switch(move) {
	    //left
        case 'a':
            //Left world boundary is 0+1, as a border may be drawn "NO BORDER SO 1 REMOVED"
            player_x = (player_x == 0) ? player_x : player_x - player_speed;
	    player_x = (player_x < 0) ? 0 : player_x;
	    break;

	    //right
	    case 'd':
	        //Right world boundary is 80-1-3, accounting for player model dimensions "NO BORDER SO -1 REMOVED"
	        player_x = (player_x == win_x - 3) ? player_x : player_x + player_speed;
		player_x = (player_x > win_x - 3) ? win_x - 3 : player_x;
	    break;

	    //shoot
	    case 'w':
	        for(int i=0; i<max_projectiles; i++) {
                if(projectiles[i][0] != -10)
                    continue;
		        projectiles[i][0] = player_y - 1;
		        projectiles[i][1] = player_x + 1;
		        break;
	        }
	    break;

        //pause
        case 'p':
        break;
    }
    return move;
}

bool game::enemies_empty() {
    // Check if enemies array is empty
    bool empty = true;
    for(int i = 0; i < max_number_of_enemies; i++) {
        if(!(enemies[i][0] == -1 || enemies[i][2] == -1)) {
            empty = false;
	    }
    }
    return empty;
}

void game::generate_enemies(int no_of_enemies) {
    // Generate new enemies and queue them
    srand(time(NULL));
    for(int i = 0; i < no_of_enemies; i++) {
        enemy E;
	    E.y = rand() % (5);
	    E.x = rand() % (win_x-3);
	    E.health = 0;
	    E.projectile_y = -1;
	    E.projectile_x = -1;
        
        all_enemies.push(E);	
    }
}

void game::add_enemies() {
    // Add generated enemies to the enemies array
    int i = 0;
    while(!all_enemies.empty() && i < max_number_of_enemies) {
        enemies[i][0] = all_enemies.front().y;
	    enemies[i][1] = all_enemies.front().x;
	    enemies[i][2] = all_enemies.front().health;
	    enemies[i][3] = all_enemies.front().projectile_y;
	    enemies[i][4] = all_enemies.front().projectile_x;

	    all_enemies.pop();
	    i++;
    }

    std::cerr << "Added enemy to array \n";

    // use a set to ensure unique enemy coordinates
    std::set<int> enemy_coordinates{};

    for (int i = 0; i < max_number_of_enemies; i++)    {
        if (enemies[i][1] != -1 && enemies[i][0] != -1 && enemy_coordinates.count(enemies[i][1]) == 0 && enemy_coordinates.count(enemies[i][1] + 1) == 0 && enemy_coordinates.count(enemies[i][1] - 1) == 0)    {
            //not in set
            enemy_coordinates.insert(enemies[i][1] - 1);
            enemy_coordinates.insert(enemies[i][1]);
            enemy_coordinates.insert(enemies[i][1] + 1);
            continue;
        }
        else    {
            // duplicated enemy
            enemies[i][0] += 3;
        }
    }
    std::cerr << "Verified unique coordinates \n";
}

bool game::powerups_empty() {
    // Checks if powerups array is empty
    bool empty = true;
    for(int i = 0; i < max_number_of_powerups; i++) {
        if(powerups[i][0] != -1)
	        empty = false;
    }
    return empty;
}

void game::generate_powerups(int no_of_powerups) {
    // Generate and queue powerups
    srand(time(NULL) + no_of_powerups + 10000);
    for(int i = 0; i < no_of_powerups; i++) {
        powerup P;
	    P.y = rand() % (5);
	    P.x = rand() % (win_x - 3);
	    P.type = rand() % (types_of_powerups);
	    all_powerups.push(P);
    }
}

void game::add_powerups() {
    // Add powerups from queue to array
    int i = 0;
    while(!all_powerups.empty() && i < max_number_of_powerups) {
        powerups[i][0] = all_powerups.front().y;
	    powerups[i][1] = all_powerups.front().x;
	    powerups[i][2] = all_powerups.front().type;
	    i++;
    }
    all_powerups.pop();
}

int game::get_player_countdown()    {
    return player_countdown;
}

bool game::get_bfb_used()   {
    return bfb_used;
}

void game::reduce_player_countdown()    {
    player_countdown--;
}

void saveLeaderboard(int score)    {
    // Save player score to Leaderboard.txt file
    std::ofstream ofile("Leaderboard.txt", std::ios::app);
    ofile << score << "\n"; 
    ofile.close();
}

void displayLeaderBoard(WINDOW * mm, int menu_y, int menu_x)   {
    // Display top 10 scores from the Leaderboard.txt file
    werase(mm);
    std::ifstream ifile("Leaderboard.txt", std::ios::in);
    int i = 0;
    int score = 0;
    int count = 0;
    wmove(mm, menu_y / 2 - 8, menu_x / 2 - 10);
    waddstr(mm, "LEADERBOARD TOP 10");
    std::vector<int> scoreboard;
    while (ifile >> score)    {
        scoreboard.push_back(score);
        i++;
    }
    count = i;
    std::sort(scoreboard.begin(), scoreboard.end(), std::greater<int>());
    i = 0;
    ifile.close();
    while (i < count && i < 10 && scoreboard[i] != 0)  {
        wmove(mm, menu_y / 2 - 6 + i, menu_x / 2 - 12);
        std::string output = "Rank #" + std::to_string(i + 1) + "    " + std::to_string(scoreboard[i]); 
        waddstr(mm, output.c_str());
        i++;
    }
    wrefresh(mm);
    wgetch(mm);
    werase(mm);
}
