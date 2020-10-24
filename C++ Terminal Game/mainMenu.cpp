#include "mainMenu.h"

void main_menu(WINDOW * mm, int menu_y, int menu_x) {

    int input;

    // render menu screen to take player input
    
    while (1)  {
	
        wmove(mm, menu_y / 2 - 5, menu_x / 2 - 30);
        waddstr(mm, "  ___      _        _     _   _____      _     _     ");
	wmove(mm, menu_y / 2 - 4, menu_x / 2 - 30);
        waddstr(mm, " / _ \\    | |      (_)   | | /  __ \\    (_)   (_)    ");
	wmove(mm, menu_y / 2 - 3, menu_x / 2 - 30);
        waddstr(mm, "/ /_\\ \\___| |_ _ __ _  __| | | /  \\/_ __ _ ___ _ ___ ");
	wmove(mm, menu_y / 2 - 2, menu_x / 2 - 30);
        waddstr(mm, "|  _  / __| __| '__| |/ _` | | |   | '__| / __| / __|");
	wmove(mm, menu_y / 2 - 1, menu_x / 2 - 30);
        waddstr(mm, "| | | \\__ \\ |_| |  | | (_| | | \\__/\\ |  | \\__ \\ \\__ \\");
	wmove(mm, menu_y / 2 - 0, menu_x / 2 - 30);
        waddstr(mm, "\\_| |_/___/\\__|_|  |_|\\__,_|  \\____/_|  |_|___/_|___/");

	wmove(mm, menu_y / 2 + 3, menu_x / 2 - 7);
        waddstr(mm, "1* NEW GAME");
	wmove(mm, menu_y / 2 + 4, menu_x / 2 - 7);
        waddstr(mm, "2* LEADERBOARD");
	wmove(mm, menu_y / 2 + 5, menu_x / 2 - 7);
        waddstr(mm, "3* EXIT");
        
	wmove(mm, menu_y / 2 + 7, menu_x / 2 - 13);
        waddstr(mm, "PLEASE SELECT AN OPTION: ");

        wrefresh(mm);
	sleep(1);
	input = wgetch(mm);

        //handle invalid inputs from player
      
        if (input < '1' || input > '3') {
            sleep(1);
	    werase(mm);
	    wmove(mm, menu_y / 2, menu_x / 2 - 12);
	    waddstr(mm, "---ERROR: WRONG INPUT---");
	    wrefresh(mm);
            sleep(2);
            werase(mm);
	    continue;
        }
	else break;
    }
    sleep(2);
    // call functions based on player input
    switch(input)   {
        case '1':  // start player game
                break;
        case '2': // display player leaderboard - top 10 scores
                displayLeaderBoard(mm, menu_y, menu_x);
                main_menu(mm, menu_y, menu_x);
                break;
        case '3': // exit game 
                werase(mm);
                delwin(mm);
                endwin();
                exit(0);
                break;
    }
}
