//Chris Lu
//Project 3
//Tree.h
//this is the implementation of the .h file for a binary search tree
#include "song.h"

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

        //insert stuff we need to do 
        int insert(song & song); 

        //displays in order of smallest to largest
        int displayAll();  

        //to match artist? any fucking field?
        int retrieveByKey(char * key_tosearch, song & foundSong);  //wrapper
        
        int displayByKey(char * key_tosearch);
        //removeArtist
        //displayByKey
        //get_height
        //is_efficient
    private:
        tNode * root;
        int ios(tNode * tree, tNode * returnVal);
        int retrieveByKey(tNode * root, char *, song & foundval); //recursive function
        int displayAll(tNode *& root); //needs to print by artist name
        int insert(tNode *& root, song & song_toadd);
        int removeAll(); //removes everything from the tree
        int removeAll(tNode *& root); //a recursive function
};
