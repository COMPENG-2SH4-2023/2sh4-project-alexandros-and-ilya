#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    int ListSize = 0;
    int ArrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    int ListSize;
    return ListSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    int ListSize;
    int ArrayCapacity;
    if(ListSize != ArrayCapacity)
    {
        for(int i = ListSize; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }

        aList[0].setObjPos(thisPos);

        ListSize++;
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    int ListSize;
    int ArrayCapacity;
    if(ListSize != ArrayCapacity)
    {
        aList[ListSize++].setObjPos(thisPos);
    }

}

void objPosArrayList::removeHead()
{
    int ListSize;
    for(int i = 0; i < ListSize - 1; i++)
    {
        aList[i] = aList[i+1];
    }

    ListSize--;
}

void objPosArrayList::removeTail()
{
    int ListSize;
    ListSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    int ListSize;
    returnPos.setObjPos(aList[ListSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}
