//Chris Lu
//Project 4
//Treenode.cpp
//This is the implementation of the .h file for the tablenode struct
//which is stored at tree.h

#include "tree.h"

//Default constructor
tNode::tNode()
{
    songData = nullptr;
    left = nullptr;
    right = nullptr; 
} 

//Parameterized constructor that calls song's copySong function
tNode::tNode(song & songToadd)
{
    left = NULL;
    right = NULL; 
    songData = NULL;
    songData = new song;
    songData->copySong(songToadd);
}

//Destructor
tNode::~tNode()
{
    if(songData)
    {
        delete songData;
        songData = NULL;
    }
}
