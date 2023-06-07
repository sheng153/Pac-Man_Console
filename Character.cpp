#include "Board.hpp"

Character::Character ( int color, COORD pos, int character, HANDLE handle )
{
        COORD initDir;

        initDir.X = 1;
        initDir.Y = 0;

        SetHandle ( static_cast< HANDLE >( handle ) );

        SetCharacterColor ( color );

        SetChar ( character );

        SetPosition ( pos );
        SetDirection ( initDir );

        Paint ( );
}

void Character::SetHandle ( HANDLE handle ) {
        this->handle = handle;
}

void Character::SetChar ( int character )
{
        this->character = character;
}

void Character::SetDirection ( COORD dir )
{
        this->direction = dir;
}

void Character::SetCharacterColor ( int col )
{
        color = ( col > 0 ) ? col : pj;
}

void Character::SetName ( std::string name )
{
        this->name = name;
}

bool Character::CanMoveTo ( COORD direction )
{
        char output = ' ';
        DWORD count;

        direction.X += GetPosition ( ).X;
        direction.Y += GetPosition ( ).Y;

        ReadConsoleOutputCharacter ( GetHandle ( ), &output, 1, direction, &count );


        if(output == char ( 250 ) || output == char ( 79 ) || output == ' ' || output == char ( GetChar ( ) )) {
                SetOutput ( output );
                return true;
        }

        return false;
}

void Character::SetOutput ( char output ) {
        this->output = output;
}

void Character::SetPosition ( COORD position )
{
        LimitValues ( position.Y, upLimit, downLimit );
        LimitValues ( position.X, leftLimit - 1, rightLimit );

        this->position = position;
}

void Character::Move ( COORD dir )
{
        this->Clean ( );

        COORD newPos;
        newPos.X = 0;
        newPos.Y = 0;

        newPos.X = GetPosition ( ).X + dir.X;
        newPos.Y = GetPosition ( ).Y + dir.Y;

        SetPosition ( newPos );
        Paint ( );
}

void Character::Paint ( )
{
        SetConsoleTextAttribute ( GetHandle ( ), color );
        SetConsoleCursorPosition ( GetHandle ( ), GetPosition ( ) );
        std::cout << ( ( char ) GetChar ( ) );
}

void Character::Clean ( ) {
        SetConsoleCursorPosition ( GetHandle ( ), GetPosition ( ) );

        std::cout << " ";
}