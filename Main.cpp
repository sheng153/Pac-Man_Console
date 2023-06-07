#include "Board.hpp"

std::vector<Enemy> ghosts;
PJ *pacman = nullptr;
Board *scenario = nullptr;

int main ( )
{
        srand ( time ( NULL ) );
        StartGame ( );
        GameLoop ( );

        do {

        } while(true);

        return 0;
}

void StartGame ( )
{
        CONSOLE_CURSOR_INFO cursorInfo;
        HANDLE thisHandle;

        scenario = new Board ( thisHandle );

        GetConsoleCursorInfo ( thisHandle, &cursorInfo );
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo ( thisHandle, &cursorInfo );

        COORD ghostPos[ 4 ];

        int ghostColor[ 4 ] = { blinky, inky, pinky, clide };

        for(int i = 0; i < 4; i++) {
                ghostPos[ i ].X = 12 + i;
                ghostPos[ i ].Y = 12;
        }

        COORD pacmanPos;

        pacmanPos.X = 14;
        pacmanPos.Y = 15;

        pacman = new PJ ( pj, pacmanPos, 219, thisHandle );

        for(int i = 0; i < 4; i++) {
                Enemy ghost ( ghostColor[ i ], ghostPos[ i ], 1, thisHandle );

                ghosts.push_back ( ghost );
        }
}

void GameLoop ( )
{

        COORD input = Input ( );
        COORD winPos;
        winPos.X = rightLimit + 3;
        winPos.Y = downLimit / 2;

        if(pacman->CanMoveTo ( input )) {
                pacman->Move ( input );
        }


        for(int i = 0; i < ghosts.size ( ); i++) {
                if(ghosts[ i ].CanMoveTo ( ghosts[ i ].GetDirection ( ), 1 )) {
                        ghosts[ i ].Move ( ghosts[ i ].GetDirection ( ) );
                }
                else {
                        ghosts[ i ].SetXY ( );
                        ghosts[ i ].SetDirection ( ghosts[ i ].SetInput ( ) );
                        GameLoop ( );
                }
        }

        pacman->PrintLives ( );
        pacman->PrintPoints ( );

        //std::this_thread::sleep_for(std::chrono::milliseconds(sleepFor));
        if(pacman->GetCount ( ) < 290) {
                GameLoop ( );
        }


        SetConsoleCursorPosition ( pacman->GetHandle ( ), winPos );
        std::cout << "You won!!";

}

void LimitValues ( SHORT &change, int min = leftLimit, int max = rightLimit )
{
        if(change <= min) {
                change = max - 1;
        }
        else if(change > max) {
                change = min;
        }
}

COORD Input ( )
{
        char *input = new char ( getch ( ) );

        COORD movement;

        movement.X = 0;
        movement.Y = 0;

        while(_kbhit ( )) {
                getch ( );
        }

        switch(*input) {
        case 'w':
                movement.Y = -1;
                delete input;
                return movement;
        case 's':
                movement.Y = 1;
                delete input;
                return movement;
        case 'a':
                movement.X = -1;
                delete input;
                return movement;
        case 'd':
                movement.X = 1;
                delete input;
                return movement;
        }
        delete input;
        return movement;
}