#include "Board.hpp"

Enemy::Enemy( int col, COORD fixedPosition, int symbol, HANDLE handle ) : Character( col, fixedPosition, symbol, handle )
{
        xy = x;
        SetPrevChar(' ');
}

void Enemy::SetTimer()
{

}

bool Enemy::CanMoveTo(COORD direction, int space){

        char output = ' ';
        DWORD count;

        direction.X += GetPosition().X;
        direction.Y += GetPosition().Y;

        ReadConsoleOutputCharacter(GetHandle(), &output, 1, direction, &count);

        if (output == char(250) || output == char(79) || output == ' ') {
                SetPrevChar(output);
                return true;
        }
        if (output == char(GetChar())) {
                return true;
        }
        return false;

}

COORD Enemy::SetInput() {
        
        COORD input;
        
        input.X = 0;
        input.Y = 0;

        switch (GetInput()) {
                case x:
                        input.Y = (rand() % 2 == 0) ? -1 : 1;
                        return input;
                case y:
                        input.X = (rand() % 2 == 0) ? -1 : 1;
                        return input;
        }
}

void Enemy::Clean(){

        SetConsoleCursorPosition(GetHandle(), GetPosition());

        std::cout << GetPrevChar();
}

void Enemy::SetPrevChar(char prevChar) {
        this -> prevChar = prevChar;
}

void Enemy::SetXY() {
        switch (xy) {
        case x:
                xy = y;
                break;
        case y:
                xy = x;
                break;
        }
}

void Enemy::SetState( short state )
{
        this -> state = (state > -1 && state < 6) ? state : this -> state;
}
