#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "time.h"//needed to seed the random number generator

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

time_t t;

int main(void)
{

    Initialize();
 
    while(myGM->getExitFlagStatus() == false && myGM->getLoseFlagStatus() == false
    && myGM->getScore()<364 )//regular function flow during regular program operation
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    while (myGM->getLoseFlagStatus()==true && myGM->getExitFlagStatus() == false)
    {//Player suicide condition
        GetInput();
        MacUILib_clearScreen();
        MacUILib_printf("Your score was %d\nPress SPACE to exit",myGM->getScore());   
    }
    while(myGM->getScore()==364 && myGM->getExitFlagStatus() == false)//this is for when the player's
    //snake reaches the maximum allowable size to avoid error
    {
        GetInput();
        MacUILib_clearScreen();
        MacUILib_printf("You got the maximum possible score (364)! \nCongratulations!\nPress SPACE to exit");
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30, 15);//board size of 30x15
    myPlayer = new Player(myGM);

    srand((unsigned)time(&t));//seeding the time for true random number generation

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    myGM->generateFood(playerBody);
}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();


}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos objFoodPos;
    myGM->getFoodPos(objFoodPos);

    for(int i = 0; i < myGM->getBoardSizeY(); i++) 
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            drawn = false;

            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);//draws the snake itself
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;

            if(i == 0||j==0||i == myGM->getBoardSizeY()-1||j == myGM->getBoardSizeX()-1)
            {
                MacUILib_printf("%c",'#');//draws border
            }
            else if(i == objFoodPos.y && j == objFoodPos.x)
            {
                MacUILib_printf("%c", objFoodPos.symbol);//draws food
            }
            else
            {
                MacUILib_printf("%c", ' ');//draws empty slots
            }
        }
        MacUILib_printf("\n");
    }    

    MacUILib_printf("Score is equal to %d\n", myGM->getScore());
    MacUILib_printf("\nPress SPACE to exit");

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    delete myGM;
    delete myPlayer;//prevents memory leaks
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
