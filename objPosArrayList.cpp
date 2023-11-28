#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    ListSize = 0;
    ArrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return ListSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
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
    if(ListSize != ArrayCapacity)
    {
        aList[ListSize++].setObjPos(thisPos);
    }

}

void objPosArrayList::removeHead()
{
    for(int i = 0; i < ListSize - 1; i++)
    {
        aList[i] = aList[i+1];
    }

    ListSize--;
}

void objPosArrayList::removeTail()
{
    ListSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[ListSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}
