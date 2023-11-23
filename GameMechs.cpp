#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input=NULL;
    exitFlag=false;
    boardSizeX=20;
    boardSizeY=10;//default size
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input=NULL;
    exitFlag=false;
    boardSizeX=boardX;
    boardSizeY=boardY;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input=MacUILib_getChar();
    }
    return input;
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

}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}


