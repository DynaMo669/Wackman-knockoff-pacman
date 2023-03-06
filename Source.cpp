#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <tchar.h>
#include <thread>
#include <vector>

#include <utility>
#include <algorithm>

#define ymin1 mmap[ghost.y_pos - 1][ghost.x_pos] != '#' 
#define yplu1 mmap[ghost.y_pos + 1][ghost.x_pos] != '#'
#define xmin1 mmap[ghost.y_pos][ghost.x_pos - 1] != '#'
#define xplu1 mmap[ghost.y_pos][ghost.x_pos + 1] != '#'


using namespace std;

int x_coordinate = 30;
int y_coordinate = 20;
int foodindex[20][25];  // if '.' then 1, else 0


int flag = 0;
bool dead = false;




class Pacman {

public:

    int x_pos = 1;
    int y_pos = 1;
    
    Pacman() { x_pos ; y_pos ; };
};

class Ghost {
public:

    int x_pos = 23;
    int y_pos = 18;

    Ghost() { x_pos; y_pos; };

};



//void Generate_map(CHAR mmap[20][25], Pacman&, Ghost&);
void GhostsMovement(CHAR mmap[20][25], Pacman&, Ghost&);

void append_map(CHAR mmap[20][25], Pacman&, Ghost&);


CHAR map[20][25] = {  //map[y][x]
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','.','#'},
    {'#','.','#','.','.','.',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','#','#',' ',' ',' ',' ',' ','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','#'},
    {'#','.','#','#','#','#','#','#','#','#','.','.','#','#','#','#','#','#','#','#','#','#','#','.','#'},
    {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}

};





void calc_foodindex(CHAR mmap[20][25]) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 20; j++) {

            if (mmap[j][i] == '.') {
                foodindex[j][i] = 1;
            }
            else { foodindex[j][i] = 0; }

        }

    }
}


/*void Generate_map(CHAR mmap[20][25], Pacman& pacman, Ghost& ghost) {
    for (int i = 0; i < (y_coordinate); i++) {
        for (int j = 0; j < (x_coordinate); j++) {

            
            printf("%lc", mmap[i][j]);
        }
        printf("\n");
    }


}*/

void append_map(CHAR mmap[20][25], Pacman &pacman, Ghost &ghost) {


    if (GetAsyncKeyState(VK_DOWN)) {
        int n_y = pacman.y_pos;

        if(mmap[pacman.y_pos+1][pacman.x_pos] != '#'){
            pacman.y_pos = pacman.y_pos + 1;
            mmap[n_y][pacman.x_pos] = ' ';
            mmap[pacman.y_pos][pacman.x_pos] = 'C';
            foodindex[pacman.y_pos][pacman.x_pos] = 0;
        }
        
        
    }
   else if (GetAsyncKeyState(VK_LEFT)) {
       int n_x = pacman.x_pos;
           
       if (mmap[pacman.y_pos][pacman.x_pos-1] != '#') {
           pacman.x_pos = pacman.x_pos - 1;
           mmap[pacman.y_pos][n_x] = ' ';
           mmap[pacman.y_pos][pacman.x_pos] = 'C';
           foodindex[pacman.y_pos][pacman.x_pos] = 0;
       }

        }
    

   else if (GetAsyncKeyState(VK_UP)) {
        int n_y = pacman.y_pos;

        if (mmap[pacman.y_pos - 1][pacman.x_pos] != '#') {
            pacman.y_pos = pacman.y_pos - 1;
            mmap[n_y][pacman.x_pos] = ' ';
            mmap[pacman.y_pos][pacman.x_pos] = 'C';
            foodindex[pacman.y_pos][pacman.x_pos] = 0;
        }

       
        }

   else if (GetAsyncKeyState(VK_RIGHT)) {
        int n_x = pacman.x_pos;

        if (mmap[pacman.y_pos][pacman.x_pos + 1] != '#') {
            pacman.x_pos = pacman.x_pos + 1;
            mmap[pacman.y_pos][n_x] = ' ';
            mmap[pacman.y_pos][pacman.x_pos] = 'C';
            foodindex[pacman.y_pos][pacman.x_pos]=0;
        }

        }
    

   
} 



void GhostsMovement(CHAR mmap[20][25], Pacman& pacman, Ghost& ghost) {
    
    

    int current_x = ghost.x_pos;
    int current_y = ghost.y_pos;
    int delta_x = abs(pacman.x_pos - ghost.x_pos);
    int delta_y = abs(pacman.y_pos - ghost.y_pos);
    if ((delta_x > delta_y || delta_x == 0) && (yplu1 || ymin1) ) {

        if (pacman.y_pos < ghost.y_pos && ymin1 ) {

            
            if (foodindex[ghost.y_pos][ghost.x_pos] == 0) {
                mmap[ghost.y_pos][ghost.x_pos] = ' ';
                }
            else {
                mmap[ghost.y_pos][ghost.x_pos] = '.';
            }
                ghost.y_pos = ghost.y_pos - 1;
                mmap[ghost.y_pos][ghost.x_pos] = 'G';
                
            
        };
            

        
        

        if (pacman.y_pos > ghost.y_pos && yplu1  ) {

            
            if (foodindex[ghost.y_pos][ghost.x_pos] == 0) {
                mmap[ghost.y_pos][ghost.x_pos] = ' ';
            }
            else {
                mmap[ghost.y_pos][ghost.x_pos] = '.';
            }
            ghost.y_pos = ghost.y_pos + 1;
            mmap[ghost.y_pos][ghost.x_pos] = 'G';
        }


    }

    if ((delta_x < delta_y || delta_y == 0) && (xplu1 || xmin1)) {

        if (pacman.x_pos < ghost.x_pos && xmin1) {


            
            if (foodindex[ghost.y_pos][ghost.x_pos] == 0) {
                mmap[ghost.y_pos][ghost.x_pos] = ' ';
            }
            else {
                mmap[ghost.y_pos][ghost.x_pos] = '.';
            }
            ghost.x_pos = ghost.x_pos - 1;
            mmap[ghost.y_pos][ghost.x_pos] = 'G';
        }


        if (pacman.x_pos > ghost.x_pos && xplu1) {

            
            if (foodindex[ghost.y_pos][ghost.x_pos] == 0) {
                mmap[ghost.y_pos][ghost.x_pos] = ' ';
            }
            else {
                mmap[ghost.y_pos][ghost.x_pos] = '.';
            }
            ghost.x_pos = ghost.x_pos + 1;
            mmap[ghost.y_pos][ghost.x_pos] = 'G';

        }
    }
    if (ghost.y_pos == pacman.y_pos && ghost.x_pos == pacman.x_pos) {

        dead = true;
    }
    
    }



    int main() {
        
        
        
        HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        SetConsoleActiveScreenBuffer(console);
        
        CONSOLE_SCREEN_BUFFER_INFO bob;
        
        Pacman p;
        Ghost g;
        

        while (true) {
            //system("CLS");
            append_map(map, p, g);
            this_thread::sleep_for(40ms);
            GhostsMovement(map, p, g);
            this_thread::sleep_for(40ms);

            //Generate_map(map, p,g );

            //this_thread::sleep_for(40ms);



            CHAR map1d[20 * 25];
            for (int i = 0; i < 20; ++i) {

                for (int j = 0; j < 25; ++j) {

                    map1d[i * 25 + j] = map[i][j];

                };
            };
            //char mop[9][2]; //= { 'A', 'B', 'C', 'd', 'e', '5', '6','3','6', 'A', 'B', 'C', 'd', 'e', '5', '6','3','6' };


            CHAR_INFO buffer[20 * 25];
            CHAR_INFO YOU_DIED[30] ;
            string x = { "GAME OVER YOU DIED  YOU SUCK  "};
            
            for (int i = 0; i < 30; ++i) {

                YOU_DIED[i].Attributes = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE;
                YOU_DIED[i].Char.AsciiChar = x[i];
            }
        
            
            
            COORD charbufsize = { 25,20 };
            COORD youdiedsize = { 10,3 };
            
            SMALL_RECT writearea = { 2, 2, 30, 30 };
            COORD charpos = { 0, 0 };
            SMALL_RECT writearea2 = { 2, 2, 10, 10 };
        

            for (int i = 0; i < (20 * 25); i++)
            {
                buffer[i].Char.AsciiChar = map1d[i];
                buffer[i].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            }
            WriteConsoleOutputA(console, buffer, charbufsize , charpos, &writearea);
            
            this_thread::sleep_for(40ms);
            
            if (dead == true) {

               
                HANDLE gameover = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
                SetConsoleActiveScreenBuffer(gameover);
                
                WriteConsoleOutputA(gameover, YOU_DIED, youdiedsize, {0,0 }, &writearea2);
                this_thread::sleep_for(4000ms);
            }


           
        }

        
        
        
    }







    