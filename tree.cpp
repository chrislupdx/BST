//Chris Lu
//Project 4
//Table.cpp
//This is the implemtation of the .cpp for the table.cpp

#include "tree.h"
using namespace std;

tree::tree()
{
    root = NULL; 
}

tree::~tree()
{
    this->removeAll();
}

int tree::isEfficient()
{
    return 1;
}

int tree::getHeight(tNode * root)
{
    if(!root) return 0;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    int height = max(lHeight, rHeight) + 1;
    return height;
}

//The wrapper function
int tree::getHeight()
{
    if(!root) return 0;

    return getHeight(root);
}

//this is a wrapper function?? (plualizes it?)
int tree::removeArtist(char * key)
{
    //where do we call it to for repetition
    if(!root) return 0;
    bool LR;
    removeArtist(root, key, LR);
    return 1;
}

//a single removal, pre-order style
int tree::removeArtist(tNode *& root, char * key, bool LR)
{
    if(!root)   //base case
    {
        return 0;
    }
    int isMatching = strcmp(root->songData->artist, key); //wher does it go
    if(isMatching == 0 ) //if we have a match
    {
        if(!root->left && !root->right) //a leaf/no children
        {
            delete root;
            root = NULL;
        }
        //(if this is the 1st stackframe/og root (delete case needs to be written)
        //IF we're not @ the og stackframe
        else 
            //else if(this->root != root && LR) //if we came from the left (if LR is true == left) //but what about the first run?
        {
            if(!root->right && root->left) //1 child (if we ONLY have left)
            {
                tNode * hold = root->left;
                delete root;
                root = hold;
                return 1;
            }
            else if(root->right && !root->left)  //we might need t account for the third one
            {
                tNode * hold = root->left;
                delete root;
                root = hold;
                return 1;
            }
            else //if 2 children, ios invocation
            {
                tNode * ios = NULL; 
                tNode * ios_parent = NULL; //the parent OR ITSELF
                iosParent(root->right , ios_parent);
                if(!ios_parent->left) //if there isn't a smaller val than ios' parent
                {
                    ios = ios_parent; //ios_parent is in fact the righful ios
                    ios->left = root->left; //reconnect, but don't self assign
                }
                else  //if root>right has a left subtree
                {
                    ios = ios_parent->left;         //ios_parent has a smaller value which ios ought to be
                    ios_parent->left = ios->right;  //reconnect the 
                    ios->left = root->left;         //assign ios' left child to the left child of the remove target 
                    ios->right = root->right;       //assign ios' right child to the right child of the remove target
                }
                delete root;
                root = ios;
                removeArtist(root, key, true);
            }
        }
        //else if (this->root != root && !LR) //we came from the right
        //{
        //    if(root->right && !root->left) //1 child ONLY right
        //    {
        //        tNode * hold = root->right;
        //        delete root;
        //        root = hold;
        //        return 1;
        //    }
        //    else if(root->left && !root->right) //1 child ONLY left
        //    {
        //        tNode * hold = root->right;
        //        delete root;
        //        root = hold;
        //        return 1;
        //    }
        //    else        //if 2 children
        //    {
        //        tNode * ios = NULL; 
        //        tNode * ios_parent = NULL; //the parent OR ITSELF
        //        iosParent(root , ios_parent);
        //        if(!ios_parent->right) //if there isn't a bigger val than ios' parent
        //        {
        //            ios = ios_parent;
        //        }
        //        else 
        //        {
        //            ios = ios_parent->right;
        //        }
        //        //this one needs <3 and thought
        //        ios->right = root->right;
        //        ios->left = root->left;
        //        root = ios->right; //not sure if this needs to be left lets checkA
        //        delete ios;
        //        ios = NULL; 
        //        //ios_parent->right = NULL; //if we assign null to null 
        //        removeArtist(root, key, false);
        //    }
        //}
        //else is needed here
    }
    else if(isMatching > 0) //if artist > key, that means we need to look for smaller stuff
    {
        return removeArtist(root->left, key, true); //true == left
    }
    else //if key > artist, we need to look for a larger value
    {
        return removeArtist(root->right,key,false);
    }
    return 1; //ughd
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

//In order successor should be the smallest item in the right subtree
int tree::ios(tNode * tree, tNode *& returnVal)
{
    if(!tree) return 0;
    if(!tree->left) //when we have reached the smallest
    {
        returnVal = tree;
        return 1;
    }
    ios(tree->left, returnVal);

    return 1; 
}

//get leftmost thing in right subtree
//In order successor should be the smallest item in the right subtree 
int tree::iosParent(tNode * tree, tNode *& returnVal)
{
    if(!tree) return 0;
    if(tree->left && !tree->left->left) //the parent of iOS
    {
        returnVal = tree;
        return 1;
    }
    if(!tree->left) //if there is no left, we are the left
    {
        returnVal = tree;
        return 1;
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
    //std::cout << "displayall" << std::endl;
    displayAll(root);
    std::cout << "done" << std::endl;
    return 1;
}


//having some troubl with bigger vals:q
//
int tree::displayAll(tNode *& root)  
{
    if(!root) return 0;

    int count = displayAll(root->left) + 1;
    root->songData->displayInfo();

    return count + displayAll(root->right);
}

int tree::retrieveByKey(char * key_tosearch, song & foundval )
{
    return retrieveByKey(root, key_tosearch, foundval);
}

//this retrieves only the first
int tree::retrieveByKey(tNode * root, char * key_tosearch, song & foundval)
{
    if(!root) return 0;

    int isMatching = strcmp(root->songData->artist, key_tosearch);
    if(isMatching == 0) //if we find a match, append it and keep searching?
    {
        foundval.copySong(*root->songData); //not sure if doneA
        return 1;
    }
    else if(isMatching > 0)
    {
        return retrieveByKey(root->left, key_tosearch, foundval);
    }
    else
    {
        return retrieveByKey(root->right, key_tosearch, foundval);
    }
}

//BELOW IS A MOD FOR TREE INSERT INSTEAD OF SONG
int tree::retrieveByKeyAll(char * key_tosearch, tree & foundSongs )
{
    return retrieveByKeyAll(root, key_tosearch, foundSongs);
}

//BELOW IS A UNIFINISEHD MOD FOR TREE INSERT INSTEAD OF SONG
int tree::retrieveByKeyAll(tNode * root, char * key_tosearch, tree & foundSongs)
{
    if(!root) return 0;

    int isMatching = strcmp(root->songData->artist, key_tosearch);
    if(isMatching == 0) //if we find a match, append it and keep searching?
    {
        //foundval.copySong(*root->songData); //not sure if doneA
        return 1;
    }
    else if(isMatching > 0)
    {
        return retrieveByKeyAll(root->left, key_tosearch, foundSongs);
    }
    else
    {
        return retrieveByKeyAll(root->right, key_tosearch, foundSongs);
    }
}

//write a retriveallmatches 
//how do we do it return an array of values
int tree::displayByKey(char * key_tosearch)
{
    displayByKey(root, key_tosearch); 
    return 1;    
}

//recursive
int tree::displayByKey(tNode * root, char * searchKey)
{
    if(!root) return 0; //if leaf

    int count = displayByKey(root->left, searchKey);
    int isMatching = strcmp(root->songData->artist, searchKey);
    if(isMatching == 0)
    {
        root->songData->displayInfo();
    }
    return count + displayByKey(root->right, searchKey);
}

//pull stuff into songs
int tree::readFile(song **&songs,int size)
{
    int SIZE = 100; //line item is n number of chars
    int DESCSIZE = 900;
    ifstream inFile;

    inFile.open("musicshort.txt");

    if(inFile)
    {
        int count = 0;
        char eof = inFile.peek();
        while((!inFile.eof()) && (eof != -1) && (count < size))
        {
            char tempfile[100];
            inFile.get(tempfile, SIZE, '|');
            inFile.ignore(10, '|');

            char temptitle[100];
            inFile.get(temptitle, SIZE, '|');
            inFile.ignore(10, '|');

            char tempAlbum[100];
            inFile.get(tempAlbum, SIZE, '|');
            inFile.ignore(10, '|');

            char tempKey1[100];
            inFile.get(tempKey1, SIZE, '|');
            inFile.ignore(10, '|');

            char tempKey2[100];
            inFile.get(tempKey2, SIZE, '|');
            inFile.ignore(10, '|');

            char tempKey3[100];
            inFile.get(tempKey3, SIZE, '|');
            inFile.ignore(10, '|');

            char tempDesc[400];
            inFile.get(tempDesc, DESCSIZE, '\n'); inFile.ignore(10, '\n');

            song newsong(tempfile, temptitle, tempAlbum, tempKey1, tempKey2, tempKey3, tempDesc); //temptitle==song name, tempfile==artist
            insert(newsong);  //we are using the artist name as key in the BST

            eof = inFile.peek();
            count++;
        }
    }
    inFile.close();
    inFile.clear();
    return 1;
}
