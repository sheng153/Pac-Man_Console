#include "Board.hpp"

PJ::PJ ( int col, COORD fixedPosition, int character, HANDLE handle ) : Character ( col, fixedPosition, character, handle )
{

        points = 0;
        count = 4;

        SetLives ( 3 );
        SetGameState ( 0 );
}

void PJ::SetPoints ( int newPoints )
{
        points = ( newPoints >= 0 ) ? newPoints : points;
}

void PJ::SetLives ( int newLives )
{
        lives = ( newLives > 0 && newLives < 4 ) ? newLives : lives;
}

bool PJ::CanMoveTo ( COORD direction ) {

        bool can = Character::CanMoveTo ( direction );

        if(!can) {
                return false;
        }

        switch(GetOutput ( )) {
                case char ( 250 ) :
                        SetPoints ( GetPoints ( ) + 100 );
                        SetCount ( );
                        return can;
                        case char ( 79 ) :
                                SetPoints ( GetPoints ( ) + 500 );
                                SetCount ( );
                                return can;
                        default:
                                return can;

        }
}

void PJ::SetCount ( ) {
        this->count++;
}

void PJ::SetGameState ( short state )
{
        gameState = ( state > -1 && state < 3 ) ? state : gameState;
        switch(gameState) {
        case 0:
                break;
        case 1:
                break;
        case 2:
                break;
        }
}

void PJ::PrintLives ( )
{
        COORD livesPos;
        livesPos.X = rightLimit + 1;
        livesPos.Y = upLimit + 1;

        SetConsoleCursorPosition ( GetHandle ( ), livesPos );
        SetConsoleTextAttribute ( GetHandle ( ), GetColor ( ) );

        for(int i; i < GetLives ( ); i++) {
                std::cout << char ( GetChar ( ) );
        }
}

void PJ::EatPowerPellets ( )
{
        SetGameState ( 1 );
}

bool PJ::Collission ( Enemy *thisEnemy, short &state, Enemy *ghost[ ] )
{
        return true;
}

void PJ::PrintPoints ( ) {
        COORD livesPos;
        livesPos.X = leftLimit + 1;
        livesPos.Y = downLimit + 1;

        SetConsoleCursorPosition ( GetHandle ( ), livesPos );
        SetConsoleTextAttribute ( GetHandle ( ), GetColor ( ) );


        std::cout << "Points: " << GetPoints ( );
}