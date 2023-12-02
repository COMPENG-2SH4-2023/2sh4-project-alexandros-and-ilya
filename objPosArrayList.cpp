#include "objPosArrayList.h"

// objPosArrayLists are array lists where each member is of type objPos

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;//we want the player to be able to fill the entire board assuming
    //they are good enough at Snake
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList != sizeArray && sizeList>0)
    {
        for(int i = sizeList; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }

        aList[0].setObjPos(thisPos);

        sizeList++;
    }
    if (sizeList<=0)
    {
        aList[0].setObjPos(thisPos);
        sizeList=1;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList != sizeArray)
    {
        aList[sizeList++].setObjPos(thisPos);
    }

}

void objPosArrayList::removeHead()
{
    if (sizeList > 1)
    {
        for (int i = 0; i < sizeList - 1; i++)
        {
            aList[i] = aList[i + 1];
        }

        sizeList--;
    }
    if (sizeList <= 1)
    {
        sizeList = 0;
    }
}

void objPosArrayList::removeTail()
{
    if (sizeList>0)
    {
        sizeList--;//"lazy deletion" (saves computation time)
    }
    if(sizeList<=0)
    {
        sizeList = 0;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}