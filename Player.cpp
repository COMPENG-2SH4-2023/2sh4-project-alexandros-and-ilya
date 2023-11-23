#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@');
//no heap member yet
}


Player::~Player()
{
    // delete any heap members here
    //leave empty until iteration 3
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input =mainGameMechsRef->getInput();
    // PPA3 input processing logic  
    switch (input)
    {
    case 'w':
    case 'W':
        if (myDir!=UP and myDir!=DOWN)
        {
            myDir=UP;
        }
    case 'S':
    case 's':
        if (myDir!=UP and myDir!=DOWN)
        {
            myDir=DOWN;
        }
        break;
    case 'A':
    case 'a':
        if (myDir!=RIGHT and myDir!=LEFT)
        {
            myDir=LEFT;
        }
    case 'D':
    case 'd':
        if (myDir!=RIGHT and myDir!=LEFT)
        {
            myDir=RIGHT;
        }
        break;
    
    default:
        break;
    }      
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

