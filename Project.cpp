#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "time.h"

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
 
    while(myGM->getExitFlagStatus() == false && myGM->getLoseFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30, 15);
    myPlayer = new Player(myGM);

    srand((unsigned)time(&t));

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
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;

            if(i == 0||j==0||i == myGM->getBoardSizeY()-1||j == myGM->getBoardSizeX()-1)
            {
                MacUILib_printf("%c",'#');
            }
            else if(i == objFoodPos.y && j == objFoodPos.x)
            {
                MacUILib_printf("%c", objFoodPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        printf("\n");
    }    

    printf("Score is equal to %d\n", myGM->getScore());
    printf("The location of the point is at x = %d, y = %d\n", objFoodPos.x, objFoodPos.y);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM;
    delete myPlayer;
}
