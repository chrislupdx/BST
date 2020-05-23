//Chris Lu
//Project 3
//Tablenode.h
//This is the implementaiton of the .h file for the tablenode struct


#include "song.h"

struct tNode
{
    //Default constructor
    tNode();
    //Default destructor
    ~tNode();

    song * songInfo;
    tNode * next;
};
