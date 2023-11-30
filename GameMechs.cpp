#include "GameMechs.h"
#include "MacUILib.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = '\0';
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;

    foodPos.setObjPos(-1, -1, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = '\0';
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;

    foodPos.setObjPos(-1, -1, 'o');
}

// do you need a destructor?

GameMechs::~GameMechs()
{
    
}

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
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
    return boardSizeY;
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}

void GameMechs::generateFood(objPosArrayList* blockOff)
{
    foodPos.symbol = 'o';
    bool StuckFlag = true;
    objPos tempBody;

    while(StuckFlag)
    {
        StuckFlag = false;

        foodPos.x = rand()%(getBoardSizeX()-2)+1;   
        foodPos.y = rand()%(getBoardSizeY()-2)+1;

        for(int k = 0; k < blockOff->getSize(); k++)
        {
            blockOff->getElement(tempBody, k);
            if(foodPos.x == tempBody.x && foodPos.y == tempBody.y)
            {
                StuckFlag = true;
            }
        }
    }

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
