//Chris Lu
//Project 4
//Table.cpp
//This is the implemtation of the .cpp for the table.cpp

#include "tree.h"

tree::tree()
{
    root = NULL; 
}

tree::~tree()
{
    this->removeAll();
}

//recursive call, returns the # of nodes
int tree::removeAll(tNode *& root)
{
    if(!root) return 0;

    int val = removeAll(root->left) + removeAll(root->right);  //after the traversal
        
    delete root;
    root = NULL; 
    
    return val;
}

int tree::ios(tNode * tree, tNode * returnVal)
{
    if(!tree) return 0;
    if(!tree->left)
    {
    returnVal = tree->left;
    }
    ios(tree->left, returnVal);

   return 1; 
}

//This wrapper does nothing but shield the outside from recursion
int tree::removeAll()
{
    if(!root) return 0;
    removeAll(root);
    return 1;
}

//recursive insert
int tree::insert(song & song_toadd)
{
    insert(root, song_toadd);

    return 1;
}

//we're inserting songs, and keying them by song title
int tree::insert(tNode *& root, song & song_toadd) 
{
    if(!root)
    {
        root = new tNode(song_toadd); //implicitly hooks root's right pointer to this one
        return 1;
    }
    //check if < 0 is greater than or smller than?
    else if(strcmp(root->songData->artist, song_toadd.artist) < 0) 
    {
       return insert(root->right, song_toadd);  //**!
    }
    else
    {
        return insert(root->left, song_toadd);
    } 
}

int tree::displayAll()
{
    std::cout << "displayall" << std::endl;
    return displayAll(root);
}


int tree::displayAll(tNode *& root)  
{
    if(!root) return 0;

    int count = displayAll(root->left) + 1;
    root->songData->displayInfo();

    return count + displayAll(root->right);
}

int tree::retrieveByKey(char * key_tosearch, song & foundSong)
{
    return retrieveByKey(root, key_tosearch, foundSong);
}

//this retrieves
int tree::retrieveByKey(tNode * root, char * key_tosearch, song & foundval)
{
    if(!root) return 0;
    
    int foundValue = strcmp(root->songData->artist, key_tosearch);
    if(foundValue == 0)
    {
        foundval.copySong(*root->songData); //not sure if done
        return 1;
        //get rid of the return
        //and instead insert it into a subtree
    }
    else if(foundValue >  0) //are we inserting:w
    {
        return retrieveByKey(root->left, key_tosearch, foundval);
    }
    else
    {
        return retrieveByKey(root->right, key_tosearch, foundval);
    }
}

//how do we do it return an array of values
int tree::displayByKey(char * key_tosearch)
{
    
    
}
