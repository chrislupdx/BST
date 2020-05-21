//Prog3
//This is the implementation of the interface file for prorgram 3
#include "table.h" 
#include <iostream>
#include <fstream>

using namespace std; 

//This function makes a song and inserts it into the hashtable
int makeSong(table & songTable);
int deleteArtist(table & songTable);  //houses user propmpts for deleting an artist
int querySong(table & songTable);
int readFile(song *& songs);
int displaySearchWrapper(table & songTable);
int main()
{
    cout << "Program 3: Playlists" << endl;

    table songTable; 
    int size = 60;                  //This sets the number the # of song structs created and lines parsed from the textfile
    song * songs = new song[size];  
    songTable.readFile(songs, size);      
    songTable.displayAll();

    cout << "Choices: " << endl;
    cout << "1. Delete an artist" << endl;
    cout << "2. Search for a title" << endl;
    cout << "3. Retrieve a song" << endl; 
    cout << "4. Add a song" << endl;
    cout << "0 to exit" << endl;


    int option; 
    cin >> option;
    cin.ignore(100, '\n');
    do
    {
        if(option == 1)
        {
            cout << "Deleting artist: " << endl;
            deleteArtist(songTable);
            songTable.displayAll();    //it's cool we're getting a different set of songs but from where
            cout << "Choices: " << endl;
            cout << "1. Delete an artist" << endl;
            cout << "2. Search for a title" << endl;
            cout << "3. Retrieve a song" << endl; 
            cout << "4. Add a song" << endl;
            
            cin >> option;
            cin.ignore(100, '\n');

        }
        if(option == 2)
        {
            cout << "Seaching by keyword: " << endl; 
            displaySearchWrapper(songTable);
            cout << endl;

            // songTable.displayAll();    //it's cool we're getting a different set of songs but from where
            cout << "Choices: " << endl;
            cout << "1. Delete an artist" << endl;
            cout << "2. Search for a title" << endl;
            cout << "3. Retrieve a song" << endl; 
            cout << "4. Add a song" << endl;
            cout << "0 to exit" << endl;
            cin >> option;
            cin.ignore(100, '\n');
        }
        if(option == 3)
        {
            cout <<"Retrieve song: " << endl;
            songTable.displayAll();

            cout << "Enter song: " << endl;
            char title_tofind[34];
            cin.get(title_tofind, 34, '\n');
            cin.ignore(100, '\n');
            song songFound;

            songTable.retrieveSong(title_tofind, songFound);

            cout << "returned song: " << endl;
            songFound.displayInfo();
            cout << endl;

            cout << "Choices: " << endl;
            cout << "1. Delete an artist" << endl;
            cout << "2. Search for a title" << endl;
            cout << "3. Retrieve a song" << endl; 
            cout << "4. Add a song" << endl;
            cout << "0 to exit" << endl;
            cin >> option;
            cin.ignore(100, '\n');
        }
        if(option == 4)
        {
            cout << "Add a song: " << endl;
            makeSong(songTable);

            cout << "Choices: " << endl;
            cout << "1. Delete an artist" << endl;
            cout << "2. Search for a title" << endl;
            cout << "3. Retrieve a song" << endl; 
            cout << "4. Add a song" << endl;
            cout << "0 to exit" << endl;
            cin >> option;
            cin.ignore(100,'\n');
        }
    }
    while(option != 0);
    return 1;
}

int displaySearchWrapper(table & songTable)
{
    cout << "search for a thing by title? (y/n) " << endl;
    char answer;
    cin >> answer;
    cin.ignore();
    if(answer == 'y')
    {
        cout << "Title to search by: " << endl;
        char titlesearch[25];
        cin.get(titlesearch, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;
        songTable.displaySearch(titlesearch);
    }
    return 1;
}

int querySong(table & songTable)
{
    char song_toq[20];
    cout << "Song query? " << endl;
    cin.get(song_toq, 100, '\n');
    cin.ignore(100, '\n'); cout << endl;

    song found_song;

    //ewww if we have 3 tables do we just display all 3 tables
    songTable.retrieveSong(song_toq, found_song); 
    return 1;
}

//will need to take in all 3 tables
int deleteArtist(table & songTable)
{
    char artist_todelete[20];
    bool done = false;
    do
    {
        cout << "Delete an artist: " << endl;
        cout << "Artist name? " << endl;
        cin.get(artist_todelete, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;
        songTable.removeArtistTracks(artist_todelete); //deletes at all 3 tables

        cout << "Delete another artist? y/n " << endl;
        char answer;
        cin >> answer; 
        cin.ignore(100, '\n');
        if(answer == 'n')
        {
            done = true;
        }

    }
    while(done == false);

    return 1;
}

//Prompts user for song info fields, ONLY adds to
//songTable see line 95
int makeSong(table & songTable)
{
    bool done = false;
    do {  
        char artist_toadd[20];
        char title_toadd[20];
        char key1_toadd[20];
        char key2_toadd[20];
        char key3_toadd[20];
        char album_toadd[20];
        char description_toadd[20];

        cout << "artist name? ";
        cin.get(artist_toadd, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        cout << "title_toadd? ";
        cin.get(title_toadd, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        cout << "album ? ";
        cin.get(album_toadd, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        cout << "key1? ";
        cin.get(key1_toadd, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        cout << "key2? ";
        cin.get(key2_toadd, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        cout << "key3? ";
        cin.get(key3_toadd, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        cout << "decription? ";
        cin.get(description_toadd, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        char * keyval = new char[strlen(title_toadd) + 1];
        strcpy(keyval, title_toadd);

        song * songtoadd = new song(artist_toadd, title_toadd, album_toadd, key1_toadd, key2_toadd, key3_toadd, description_toadd);

        songTable.insertSong(title_toadd, *songtoadd);  //double check we're idnexing right

        cout << "Add another song? y/n" << endl; //endless looping check p2 loop
        char answer;
        cin >> answer;
        cin.ignore(100, '\n');
        if(answer == 'n')
        {
            done = true;
        }
    }
    while(done == false); //weird

    return 1;
};
