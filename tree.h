//Chris Lu
//Project 3
//Tree.h
//this is the implementation of the .h file for a binary search tree
#include "song.h"
#include <fstream>

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

        tree(); //does it get initialized blank
        //maybe an orloaded copy constructor?
        ~tree();

        //for reading files
        int readFile(song **&songs, int size);

        //insert stuff we need to do 
        int insert(song & song); 

        //displays in order of smallest to largest
        int displayAll();  

        //Returns the first matching track
        int retrieveByKey(char * key_tosearch, song & foundval); 

        //UNIFNISHED
        int retrieveByKeyAll(char *key_tosearch, tree & foundSongs);

        //Displays all found/matching artists
        int displayByKey(char * key_tosearch);

        //Removes all artists
        int removeArtist(char * key);
        
        //get_height
        //is_efficient

    private:
        tNode * root;
        

        //for finding the in order successor
        int ios(tNode * tree, tNode * returnVal);
        
        //UNIFINISHED 
        int retrieveByKeyAll(tNode *root, char *, tree & foundSongs);
        
        //The recursive call for displayByKey
        int displayByKey(tNode * root, char * searchKey);
        
        //int retrieveByKey(tNode * root, char *, song & foundval); //recursive function
        int retrieveByKey(tNode *root, char *, song & song);
       
        int displayAll(tNode *& root); //needs to print by artist name
        int insert(tNode *& root, song & song_toadd);
        int removeAll(); //removes everything from the tree
        int removeAll(tNode *& root); //a recursive function
};
