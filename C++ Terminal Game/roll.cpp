#include "roll.h"

void rollTheIntro(WINDOW * up, int up_y, int up_x, WINDOW * mid, int mid_y, int mid_x, WINDOW * low, int low_y, int low_x, std::string message) {

    // Setup timing parameters
    
    int pause = 20, message_pause = 8;
    int message_len = message.length();

    // Set line parameters
    
    int number_of_lines = 1;
    for(int i = 0; i < message_len; i++)
        if(message[i] == '\n')
            number_of_lines++;
    
    std::string * lines = new std::string[number_of_lines];
    
    for(int i = 0, i_lines = 0; i < message_len && i_lines < number_of_lines; i++) {
        if(message[i] == '\n') {
            i_lines++;
            continue;
        }
        lines[i_lines] += message[i];
    }

    // Animation Setup and Implementation
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 11);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(low, low_y / 2 - 1, low_x / 2 + 10);
    waddch(low, '_');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 12);
    waddch(up, '(');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(low, low_y / 2 - 1, low_x / 2 + 11);
    waddch(low, ')');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    for(int i = 0; i < 8; i++) {
        wmove(up, up_y / 2 + 1, up_x / 2 - 11 + i);
        waddch(up, '_');
        wrefresh(up);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
        wmove(low, low_y / 2 - 2, low_x / 2 + 10 - i);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
            
    }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 3);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(low, low_y / 2 - 1, low_x / 2 + 2);
    waddch(low, '/');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 2);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
    wmove(low, low_y / 2 - 1, low_x / 2 + 1);
    waddch(low, '\\');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
    wmove(low, low_y / 2 - 1, low_x / 2 - 0);
    waddch(low, '/');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 0);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
    wmove(low, low_y / 2 - 0, low_x / 2 - 1);
    waddch(low, '/');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 - 1, up_x / 2 - 0);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
    wmove(low, low_y / 2 + 1, low_x / 2 - 1);
    waddch(low, '\\');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 - 1, up_x / 2 - 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
    wmove(low, low_y / 2 + 1, low_x / 2 - 0);
    waddch(low, '/');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 1);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
    wmove(low, low_y / 2 - 0, low_x / 2 - 0);
    waddch(low, '\\');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 0);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
    wmove(low, low_y / 2 - 1, low_x / 2 - 1);
    waddch(low, '\\');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            
    wmove(up, up_y / 2 + 1, up_x / 2 + 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
    wmove(low, low_y / 2 - 1, low_x / 2 - 2);
    waddch(low, '/');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));

    
    wmove(up, up_y / 2 + 1, up_x / 2 + 2);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
    wmove(low, low_y / 2 - 1, low_x / 2 - 3);
    waddch(low, '\\');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    

    for(int i = 0; i < 8; i++) {
        wmove(up, up_y / 2 + 1, up_x / 2 + 3 + i);
        waddch(up, '_');
        wrefresh(up);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
        wmove(low, low_y / 2 - 2, low_x / 2 - 4 - i);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));

    }
    wmove(up, up_y / 2 + 1, up_x / 2 + 10);
    waddch(up, ')');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
    wmove(low, low_y / 2 - 1, low_x / 2 - 12);
    waddch(low, '(');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    
    wmove(up, up_y / 2 - 0, up_x / 2 + 9);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
          
    wmove(low, low_y / 2 - 1, low_x / 2 - 11);
    waddch(low, '_');
    wrefresh(low);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));

    // Print words in animation
    
    for(int i = 0; i < number_of_lines; i++) {
        int len = lines[i].length();
        wmove(mid, mid_y / 2 - number_of_lines / 2 + i, mid_x / 2 - len / 2);
        for(int j = 0; j < len; j++) {
            waddch(mid, lines[i][j]);
            wrefresh(mid);
            std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
        }
    }
    
    delete [] lines;
}
