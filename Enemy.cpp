#include "Board.hpp"

Enemy::Enemy( int col, COORD fixedPosition, int symbol, HANDLE handle ) : Character( col, fixedPosition, symbol, handle )
{

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

        if (output == char(250) || output == char(79) || output == ' ' || output == char(GetChar())) {
                return true;
        }
        SetXY();
        return false;

}

COORD Enemy::SetInput() {
        
        COORD input;
        
        input.X = 0;
        input.Y = 0;

        switch (GetInput()) {
                case x:
                        input.Y = rand() - 2 % 2;
                        return input;
                case y:
                        input.X = rand() - 2 % 2;
                        return input;
        }
}

void Enemy::Clean(){

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
