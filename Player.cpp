#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');
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
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    //See how game mechanics gives you input
    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case 'w':
        case 'W':
            if(myDir != UP && myDir != DOWN)
                myDir = UP;
            break;
        case 'a':
        case 'A':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = LEFT;
            break;
        case 's':
        case 'S':
            if(myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;
        case 'd':
        case 'D':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = RIGHT;
            break;
        case 'k':
        case 'K':
            mainGameMechsRef->IncrementScore();
            break;
        case 't':
        case 'T':
            mainGameMechsRef->setLoseTrue();
            break;
        default:
            break;
    }
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if(myDir == UP)
        playerPos.y--;
    else if(myDir == LEFT)
        playerPos.x--;
    else if(myDir == DOWN)
        playerPos.y++;
    else if(myDir == RIGHT)
        playerPos.x++;

    if(playerPos.x == 0) 
        playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
    else if(playerPos.x == mainGameMechsRef->getBoardSizeX()-1)
        playerPos.x = 1;
    else if(playerPos.y == 0)
        playerPos.y = mainGameMechsRef->getBoardSizeY()-2;
    else if(playerPos.y == mainGameMechsRef->getBoardSizeY()-1)
        playerPos.y = 1;
}

bool Player::checkFoodConsumption()
{

}

bool Player::checkSelfCollision()
{

}
