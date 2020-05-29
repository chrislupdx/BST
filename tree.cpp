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

int tree::displayByKey(tNode * root, char * searchKey)
{
    if(!root) return 0; //if leaf
    //let's to in-order: left, - then visit - then right

    int count = displayByKey(root->left, searchKey);
    int isMatching = strcmp(root->songData->artist, searchKey);
    if(isMatching == 0)
    {
    root->songData->displayInfo();
    }
    displayByKey(root->left, searchKey);

    return count + displayByKey(root->right, searchKey);
}

//pull stuff into songs
int tree::readFile(song **&songs,int size)
{
 int SIZE = 100; //line item is n number of chars
     int DESCSIZE = 900;
     ifstream inFile;
 
     inFile.open("music.txt");
 
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
