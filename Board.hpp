#ifndef Board_hpp
#define Board_hpp

#include "Game.hpp"

class Board
{
public:

        Board ( HANDLE &handle );

        void MapSwitch ( HANDLE handle, char map );

        void PaintBoard ( HANDLE handle, char maps[ ][ columns + 1 ], int thisRows, int thisColumns );

        bool IsWall ( char next );

        void Points ( HANDLE handle, PJ pacman );

        HANDLE Start ( );
        void PrintBoard ( );
        void Restart ( Character *charArray, COORD *positions );

};
#endif
