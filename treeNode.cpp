//Chris Luj
//Project 4
//Treenode.cpp
//This is the implementatio nfo the .h file for the tablenode struct

#include "tree.h"

tNode::tNode()
{
    songData = nullptr;
    left = nullptr;
    right = nullptr; 
} 

tNode::tNode(song & songToadd)
{
    left = NULL;
    right = NULL; 
    songData = NULL;
    songData = new song;
    songData->copySong(songToadd);
}

tNode::~tNode()
{
    if(songData)
    {
        delete songData;
        songData = NULL;
    }
}
