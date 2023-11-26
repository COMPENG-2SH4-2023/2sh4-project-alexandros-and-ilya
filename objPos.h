#ifndef OBJPOS_H
#define OBJPOS_H

class objPos//you can't change this
{
    public:
        int x;
        int y;
        char symbol;

        objPos();//default constructor
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym);

        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        void getObjPos(objPos &returnPos);
        char getSymbol();

        bool isPosEqual(const objPos* refPos);
        
        char getSymbolIfPosEqual(const objPos* refPos);
};

#endif