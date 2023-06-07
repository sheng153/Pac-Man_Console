#include "Board.hpp"

static char map[rows][columns + 1] = {
        "ahhhhhhhhhhhhhnhhhhhhhhhhhhhb",
        "v@;;;;;;;;;;;;v;;;;;;;;;;;;@v",
        "v;ahhb;ahhhhb;v;ahhhhb;ahhb;v",
        "v;v  v;v    v;v;v    v;v  v;v",
        "v;chhd;chhhhd;v;chhhhd;chhd;v",
        "v;;;;;;;;;;;;;;;;;;;;;;;;;;;v",
        "v;hhhh;v;hhhhhnhhhhh;v;hhhh;v",
        "v;;;;;;v;;;;;;v;;;;;;v;;;;;;v",
        "chhhhb;phhhhh;v;hhhhho;ahhhhd",
        "     v;v;;;;;;i;;;;;;v;v     ",
        "     v;v;ahhhh2hhhhb;v;v     ",
        "hhhhhd;v;v    2    v;v;chhhhh",
        " ;;;;;;;;v    2    v;;;;;;;; ",
        "hhhhhb;v;v    2    v;v;ahhhhh",
        "     v;v;chhhhhhhhhd;v;v     ",
        "     v;v;;;;;;;;;;;;;v;v     ",
        "ahhhhd;v;hhhhhnhhhhh;v;chhhhb",
        "v;;;;;;;;;;;;;v;;;;;;;;;;;;;v",
        "v;hhhb;hhhhhh;v;hhhhhh;ahhh;v",
        "v;;;;v;;;;;;;;;;;;;;;;;v;;;;v",
        "phhh;v;v;hhhhhnhhhhh;v;v;hhho",
        "v;;;;;;v;;;;;;v;;;;;;v;;;;;;v",
        "v;hhhhhmhhhhh;v;hhhhhmhhhhh;v",
        "v@;;;;;;;;;;;;;;;;;;;;;;;;;@v",
        "chhhhhhhhhhhhhhhhhhhhhhhhhhhd"
};

short movement[rows][columns];

Board::Board( HANDLE &handle )
{
        handle = this -> Start();
}

void Board::PaintBoard( HANDLE handle, char maps[][columns + 1], int thisRows, int thisColumns )
{
        COORD position;
        for(int y = 0; y < rows; y++) {
                for(int x = 0; x < columns; x++) {
                        SetConsoleTextAttribute( handle, wall );
                        position.X = x;
                        position.Y = y;
                        SetConsoleCursorPosition( handle, position );

                        MapSwitch( handle, maps[y][x] );
                }
        }
}

bool Board::IsWall(char next)
{
        switch(next) {
                case 'p':
                        return true;
                        break;
        }
        return false;
}



void Board::Points(HANDLE handle, PJ pacman)
{
        COORD pointsPos;
        pointsPos.X = rightLimit + 1;
        pointsPos.Y = upLimit - 1;

        SetConsoleCursorPosition( handle, pointsPos );
        SetConsoleTextAttribute( handle, pointsColor );
        std::cout << "Points: " << pacman.GetPoints();
}

HANDLE Board::Start()
{

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

        PaintBoard( handle, map, rows, columns );

        return handle;
}

void Board::PrintBoard()
{

}

void Board::Restart(Character *charArray, COORD *positions)
{

        for(int i = 0; i < sizeof(charArray)/sizeof(Character); i++) {
                charArray[i].SetPosition(positions[i]);
        }

}

void Board::MapSwitch( HANDLE handle, char map )
{
        switch(map) {
                case 'v':
                        std::cout << char(186);
                        break;
                case 'h':
                        std::cout << char(205);
                        break;
                case 'm':
                        std::cout << char(202);
                        break;
                case 'n':
                        std::cout << char(203);
                        break;
                case 'o':
                        std::cout << char(185);
                        break;
                case 'p':
                        std::cout << char(204);
                        break;
                case 'a':
                        std::cout << char(201);
                        break;
                case 'b':
                        std::cout << char(187);
                        break;
                case 'c':
                        std::cout << char(200);
                        break;
                case 'd':
                        std::cout << char(188);
                        break;
                case ';':
                        SetConsoleTextAttribute( handle, food );
                        std::cout << char(250);
                        break;
                case '@':
                        SetConsoleTextAttribute( handle, food );
                        std::cout << char(79);
                        break;
                default:
                        std::cout << ' ';
                        break;
        }
}
