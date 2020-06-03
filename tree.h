//Chris Lu
//Project 4
//Tree.h
//This is the implementation of the .h file for a binary search tree.
//This page includes both the tree class ADT and the node
#include "song.h"
#include <fstream>

//This is the base node structure the tree is comprised of.
struct tNode
{
    //Default constructor
    tNode();

    //Destructor
    ~tNode();

    
    tNode(song & songToadd);
    song * songData;
    tNode * left;
    tNode * right;
};

class tree
{
    public:

        tree(); //Default constructor
        ~tree(); //Default destructor

        //for reading files
        int readFile(song **&songs, int size);

        //insert stuff we need to do 
        int insert(song & song); 

        //displays in order of smallest to largest
        int displayAll();  

        //Returns the first matching track
        int retrieveByKey(char * key_tosearch, song & foundval); 

        //Displays all found/matching artists
        int displayByKey(char * key_tosearch);

        //Removes all artists
        int removeArtist(char * key);
                
        //get_height
        int getHeight(); 

        //is_efficient
        int isEfficient();        

    private:
        tNode * root;
        
        //The recursive call for calculating height
        int getHeight(tNode * root);

        //for finding the in order successor
        int ios(tNode * tree, tNode *& returnVal);
        
        //for finding the in order successor's parent
        int iosParent(tNode* tree, tNode *& returnVal);

        //The recursive call for removing all artists of a specific search key
        int removeArtist(tNode *& root, char * key, bool LR);
        
        //The recursive call for displayByKey
        int displayByKey(tNode * root, char * searchKey);
        
        //int retrieveByKey(tNode * root, char *, song & foundval); //recursive function
        int retrieveByKey(tNode *root, char *, song & song);
      
        //Recursive call displaying all values in thet ree
        int displayAll(tNode *& root);

        //Insertion function
        int insert(tNode *& root, song & song_toadd);

        int removeAll(); //removes everything from the tree
        int removeAll(tNode *& root); //The recursive call
};
