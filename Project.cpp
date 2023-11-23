#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "player.h"



using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;
bool exitFlag;
objPos myPos;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
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
    
    myGM= new GameMechs(26,13);//x+y board dimensions
    myPlayer= new Player (myGM);

}

void GetInput(void)
{

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
}

void DrawScreen(void)
{
    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);
    MacUILib_clearScreen();  
    MacUILib_printf("Board size = <%dx%d>, Player pos=<%d,%d> %c \n", 
    myGM->getBoardSizeX(),myGM->getBoardSizeY(),
    tempPos.x, tempPos.y, tempPos.symbol);  

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
