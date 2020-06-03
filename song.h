//prog4
//this is the implementation of the .h file for the song struct
//Chris Lu
//Song.h
//This song file supports an artist name,
//title of the song, title of the album,
//list of three keywords, and a description

#include <cstring> 
#include <cctype>
#include <iostream>

struct song
{
    //The default constructor 
    song();
  
    //Overloaded constructor
    song(char * artist_toadd, char * title_toadd, char * album_toadd, char * key1_toadd, char * key2_toadd, char * key3_toadd, char * description_toadd);

    //copy consturctor takes an object and fills it with the appropriate 
    song(song & songToadd); //needs to be implemented

    //Default constructor
    ~song();

    //This function displays the struct's parms
    int displayInfo();

    //This function copies the parm into operand.  Used a lot!
    int copySong(song & songToadd); 

    //This function compares the pram to the opereand
    int compareArtist(song *& song_tocheck);
    //int compareTitle(char *& song_tocheck);

    //Data items
    char * artist;
    char * songN;
    char * album;
    char * key1;
    char * key2;
    char * key3;
    char * description;
};


