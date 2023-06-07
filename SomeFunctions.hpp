#ifndef SomeFunctions_hpp
#define SomeFunctions_hpp

//g++ -o Pacman Main.cpp Board.cpp Character.cpp PJ.cpp Enemy.cpp

#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <conio.h>
#include <vector>

#define PacmanChar 2
#define GhostChar 2

static const int rows = 25;
static const int columns = 29;
static const int leftLimit = 1;
static const int upLimit = 0;
static const int rightLimit = 28;
static const int downLimit = 24;
static const int sleepFor = 200;

static const int background = 0x0F0;

enum Color {
        pj = 0x00E,
        blinky = 0x00C,
        inky = 0x00B,
        pinky = 0x00D,
        clide = 0x00A,
        frightenedGhost = 0x004,
        food = 0x00f,
        wall = 0x009,
        pointsColor = 0x001
};

enum Rotation {
        right = 1,
        down = 2,
        left = 3,
        up = 4,
        error = 0
};

enum input {
        x = true,
        y = false
};

struct User {
        std::string name;
        int maxPoints;
        int points;
};

void LimitValues ( int &, int, int );
void LimitValues ( float &, float, float );
void LimitValues ( SHORT &, int, int );

void StartGame ( );
void GameLoop ( );

COORD Input ( );

#endif