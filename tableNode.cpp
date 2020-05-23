//Chris Lu
//Project 3
//Tablenode.cpp
//This is the implementaiton of the .cpp file for the tablenode struct

#include "tableNode.h"

//This is the default constructor
tNode::tNode()
{
    songInfo = new song;
    next = NULL;
}

//This is the default destructor
tNode::~tNode()
{
    if(songInfo)
        delete songInfo;
}


