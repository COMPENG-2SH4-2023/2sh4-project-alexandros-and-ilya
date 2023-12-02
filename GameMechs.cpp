#include "GameMechs.h"
#include "MacUILib.h"
#include "MacUILib.h"
//these methods are pretty intuitive
GameMechs::GameMechs()
{
    input = '\0';
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;

    foodPos.setObjPos(-1, -1, 'o');//in default constructor, keeps food out of
    //player's reach
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



GameMechs::~GameMechs()
{
    //no memory allocated in this class!
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
        setExitTrue();//exit key is SPACE

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

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}

void GameMechs::generateFood(objPosArrayList* blockOff)
{
    bool StuckFlag = true;
    objPos tempBody;

    while(StuckFlag)//prevents food from generating on top of the player
    {
        StuckFlag = false;/*StuckFlag is set to true when an object is generated on the 
player body*/

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