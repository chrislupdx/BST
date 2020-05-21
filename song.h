#include <cstring> 
#include <cctype>
#include <iostream>

//This song file supports an artist name,
//title of the song, title of the ablum,
//list of three keywords, and a description

//oooh should song be a class or struct

struct song
{
    song();
    song(char * artist_toadd, char * title_toadd, char * album_toadd, char * key1_toadd, char * key2_toadd, char * key3_toadd, char * description_toadd);
    ~song();
    int displayInfo();
    int copySong(song & songToadd);

    char * artist;
    char * songN;
    char * album;
    char * key1;
    char * key2;
    char * key3;
    char * description;
};


