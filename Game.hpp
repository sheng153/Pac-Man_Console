#ifndef Game_hpp
#define Game_hpp

#include "SomeFunctions.hpp"

static const int PowerPelletsTime = 60;

class Character;
class PJ;
class Enemy;

class Character
{
        public:
                Character( int, COORD, int, HANDLE );

                void SetChar( int );
                void SetDirection( COORD );
                void SetCharacterColor( int );
                void SetName( std::string );
				
		void SetHandle( HANDLE );
				
                virtual bool CanMoveTo( COORD );

                void SetPosition( COORD );

                void SetOutput(char);

                int GetChar()
                {
                        return character;
                };
                int GetColor()
                {
                        return color;
                };
                COORD GetPosition()
                {
                        return position;
                };
                COORD GetDirection(){
                	return direction;	
		};
                std::string GetName()
                {
                        return name;
                };
                char GetOutput() {
                        return output;
                };
                HANDLE GetHandle(){
                        return handle;
		};

                void Move( COORD );
                virtual void Paint();

        private:
                COORD position;
                COORD direction;
                int color;
                int character;
                std::string name;
                
                char output;

                HANDLE handle;
                
                virtual void Clean();
};

class PJ : public Character
{
        public:
                PJ( int, COORD, int, HANDLE );

                void SetPoints( int );
                void SetLives( int );
                void SetGameState( short );
                void PrintLives(  );
                void PrintPoints();

                void SetCount();

                bool CanMoveTo(COORD);

                void EatPowerPellets();
                bool Collission(Enemy *, short &, Enemy * []);

                int GetPoints()
                {
                        return points;
                };
                int GetLives()
                {
                        return lives;
                };
                bool GetGameState()
                {
                        return gameState;
                };
                int GetCount() {
                        return count;
                };

        private:
                int points;
                int count;
                int lives;
                short gameState;
};

class Enemy : public Character
{
        public:

                Enemy( int, COORD, int, HANDLE );

                void SetTimer();

                void SetXY();

                void SetState( short );
                void SetPrevChar(char);

                COORD SetInput();

                bool CanMoveTo(COORD, int);

                char GetPrevChar() {
                        return prevChar;
                };
                input GetInput() {
                        return xy;
                };
                short GetState()
                {
                        return state;
                };
                int GetTimer()
                {
                        return timer;
                };

        private:
                short state;
                int timer;

                bool activeTimer;

                input xy;

                char prevChar;

                void Clean();
};
#endif
