#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');
    // more actions to be included
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
//no heap member yet
}


Player::~Player()
{
    // delete any heap members here
    //leave empty until iteration 3
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
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
        default:
            break;
    }
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    bool eatenFlag;
    bool selfcollisionFlag;
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    if(myDir == UP)
        currentHead.y--;
    else if(myDir == LEFT)
        currentHead.x--;
    else if(myDir == DOWN)
        currentHead.y++;
    else if(myDir == RIGHT)
        currentHead.x++;

    if(currentHead.x == 0) 
        currentHead.x = mainGameMechsRef->getBoardSizeX()-2;
    else if(currentHead.x == mainGameMechsRef->getBoardSizeX()-1)
        currentHead.x = 1;
    else if(currentHead.y == 0)
        currentHead.y = mainGameMechsRef->getBoardSizeY()-2;
    else if(currentHead.y == mainGameMechsRef->getBoardSizeY()-1)
        currentHead.y = 1;

    playerPosList->insertHead(currentHead);

    eatenFlag = checkFoodConsumption();
    if(eatenFlag)
    {
        mainGameMechsRef->IncrementScore();
        playerPosList->insertTail(currentHead);
        mainGameMechsRef->generateFood(playerPosList);
    }
    playerPosList->removeTail();

    selfcollisionFlag = checkSelfCollision();
    if(selfcollisionFlag)
    {
        mainGameMechsRef->setLoseTrue();
    }

}

bool Player::checkFoodConsumption()
{
    objPos tempHead;
    objPos tempFood;

    mainGameMechsRef->getFoodPos(tempFood);
    playerPosList->getHeadElement(tempHead);

    if(tempFood.x == tempHead.x && tempFood.y == tempHead.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::checkSelfCollision()
{
    objPos tempHead;
    objPos bodyPart;
    
    playerPosList->getHeadElement(tempHead);

    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(bodyPart, i);
        if(bodyPart.x == tempHead.x && bodyPart.y == tempHead.y)
        {
            return true;
        }
    }

    return false;
    
}

