#include "tableNode.h"

tNode::tNode()
{
    songInfo = new song;
    next = NULL;
}


tNode::~tNode()
{
    if(songInfo)
        delete songInfo;
}


