//Chris Lu
//Project #3
//song.cpp
//This is the implementation of the .cpp file for a song struct. 
//This data structure exists to store song data.

#include "song.h"

//This is the default constructor for song
song::song()
{
    artist = nullptr;
    album = nullptr;
    key1 = nullptr;
    key2 = nullptr;
    key3 = nullptr;
    description = nullptr;
}

//This is a copy function/overloaded constructor for song
song::song(char * artist_toadd, char * title_toadd, char * album_toadd, char * key1_toadd, char * key2_toadd, char * key3_toadd, char * description_toadd)
{
    artist = nullptr;
    songN = nullptr;
    album = nullptr;
    key1 = nullptr;
    key2 = nullptr;
    key3 = nullptr;
    description = nullptr;

    this->artist = new char[strlen(artist_toadd) + 1]; 
    strcpy(this->artist, artist_toadd);

    this->songN = new char[strlen(title_toadd) +1];
    strcpy(this->songN, title_toadd);

    this->album = new char[strlen(album_toadd) +1];
    strcpy(this->album, album_toadd);

    this->key1 = new char[strlen(key1_toadd) + 1];
    strcpy(this->key1, key1_toadd);

    this->key2 = new char[strlen(key2_toadd) + 1];
    strcpy(this->key2, key2_toadd);

    this->key3 = new char[strlen(key3_toadd) + 1];
    strcpy(this->key3, key3_toadd);

    this->description = new char[strlen(description_toadd) + 1];
    strcpy(this->description, description_toadd);
}

//This is the default destructor
song::~song()
{
    if(artist)
        delete [] artist;
    if(songN)
        delete [] songN;
    if(album)
        delete [] album;
    if(key1)
        delete [] key1;
    if(key2)
        delete [] key2;
    if(key3)
        delete [] key3;
    if(description)
        delete [] description;
}

//This function prints the song's data members
int song::displayInfo()
{
    std::cout << std::endl << "Artist: " << artist << std::endl;
    std::cout << "Song:" << songN << std::endl;
    std::cout << "album: " << album << std::endl;
    std::cout << "key1: " << key1 << std::endl;
    std::cout << "key2: " << key2 << std::endl;
    std::cout << "key3: " << key3 << std::endl;
    std::cout << "description: " << description << std::endl;
    return 1;
}

//there are no guard statements here
int song::copySong(song & songToadd)
{
    artist = new char[strlen(songToadd.artist) + 1];
    strcpy(artist, songToadd.artist); 

    songN = new char[strlen(songToadd.songN) + 1];
    strcpy(songN, songToadd.songN);

    album = new char[strlen(songToadd.album) + 1];
    strcpy(album, songToadd.album);

    key1 = new char[strlen(songToadd.key1) + 1]; 
    strcpy(key1, songToadd.key1);

    key2 = new char[strlen(songToadd.key2) + 1]; 
    strcpy(key2, songToadd.key2);

    key3 = new char[strlen(songToadd.key3) + 1];
    strcpy(key3, songToadd.key3);

    description = new char[strlen(songToadd.description) + 1];
    strcpy(description, songToadd.description);

    return 1;
}
