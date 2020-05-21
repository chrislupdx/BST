//This is the implementaiton of the table node. These
//are the nodes that will store individuals song's indices
//and a pointer to 

#include "song.h"

struct tNode
{
   tNode();
   ~tNode();
    
    song * songInfo;
    tNode * next;
};
