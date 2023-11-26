#include "GameMechs.h"
#include "MacUILib.h"
#include <stdlib.h>

//seed the RNG in the constructors
GameMechs::GameMechs()
{
    input = '\0';
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 26;
    boardSizeY = 13;
    score=0;

    foodPos.setObjPos(-1,-1,'o');//initialize foodPos offscreen
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = '\0';
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 26;
    boardSizeY = 13;
    score=0;
    foodPos.setObjPos(-1,-1,'o');//initialize foodPos offscreen

}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    if(input == ' ')
        setExitTrue();

    return input;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::IncrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

void GameMechs::generateFood(objPos blockOff)
{
    //generate random x and y coords and make
    //sure that they are not border or blockOff
    //check against bordersize x +y
    //you have an isPosEqual() method in objPos
}
void GameMechs::getFoodPos(objPos &returnPos)
{

}

