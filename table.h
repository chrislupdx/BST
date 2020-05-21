//Chris Lu
//Project 3
//Table.h
//This is the implementaiton of the .cpp file for the hash table ADT>
#include "tableNode.h"
#include <fstream>

class table
{
    public:
        table(int size=293); //change the table size soon
        ~table();

        //This hash function adds the ASCII values of the keys together before modding it (check if moddding)
        int hash_function(char * key) const;

        //this inserts a song by a pre-detirmined index to a hash table
        int insertSong(char * key_val, song & song_toadd); //might need to be private
        int displayAll(); //Unordered display, calls displayChain
        int removeArtistTracks(char * artist_to_find);  //Searches table for the right chain, then deletes artist tracks by artist
        int readFile(song *& songs, int size); //Extracts data from the text file into song structs, inserts them into a table
        int retrieveSong(char * title_to_find, song & found); //supply matching infor back to client that matches search key
        int displaySearch(char * sK); 
    private:
       
        int displayMatches(tNode * head); //Displays matches for a search key
        int removeFChain(char* artist_to_find, tNode *& head);    //recursive artist deletion
        int displayChain(tNode * head);  //Goes through a chain, printing every node
        
        tNode ** hash_table; //This array of head pointers is our ADT
        int hash_table_size; //This is int controlks what it seems to

};
