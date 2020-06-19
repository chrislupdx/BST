//Prog4
//This is the implemntation for the interface of program 4.  
//Chris Lu
//main.cpp
#include "tree.h" 
#include <fstream>
#include <iostream>
using namespace std;

int makeSong(tree & songTree); //This wrapper funtion calls 
int retrieve(tree & songTree); //This calls tree's retrieveByKey function
int displayFoundKey(tree & songTree); //This calls displayByKey
int removeByArtist(tree & songTree); //Calls remove 
int isEfficient(tree & songTree); //Calls the efficiency function
int main() 
{
    tree niceTree;
    int size = 5; //we are controlling the outset size of the tree here
    song ** songs = new song *[size];
    niceTree.readFile(songs, size); //i think we are hardcoding the file loaction

    cout << "Program 4: Playlist" << endl;

    niceTree.displayAll();
    cout << "height is " << niceTree.getHeight() << endl;
    isEfficient(niceTree);

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
            removeByArtist(niceTree); 
            niceTree.displayAll();
            cout << "height is " << niceTree.getHeight() << endl;
            isEfficient(niceTree);

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
            displayFoundKey(niceTree); 
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
        if(option == 3)
        {
            cout <<"Retrieve song: " << endl;
            niceTree.displayAll();       
            retrieve(niceTree);

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
            makeSong(niceTree);

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

    niceTree.displayAll();
    return 1;
}

int isEfficient(tree & songTree)
{
    cout << "is efficient?" << endl;
    if(songTree.isEfficient())
    {
        cout << "Yes." << endl;
    }
    else
    {
        cout << "No." << endl;
    }

    return 1;
}

int removeByArtist(tree & songTree)
{
    char to_delete[20]; 
    cout << "Remove artist" << endl;
    cout << "Enter artist to remove" << endl;
    cin.get(to_delete, 100, '\n');
    songTree.removeArtist(to_delete);
    cout << "did" << endl;    
    return 1;
}

int displayFoundKey(tree & songTree)
{
    bool done = false;
    do
    {
        char key_tosearch[20];
        cout << "display by key" << endl;
        cout << "enter artist to search by" << endl;
        cin.get(key_tosearch, 100, '\n');
        songTree.displayByKey(key_tosearch);

        cout << "display another key? y/n" << endl;
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

//only retrieves one value
int retrieve(tree & songTree) 
{
    bool done = false;
    do
    {
        song foundval; 
        char key_tosearch[20];
        cout << "Retrieve" << endl;
        cout << "Enter artist name: " << endl;
        cin.get(key_tosearch, 100, '\n');
        cin.ignore(100, '\n'); cout << endl;

        songTree.retrieveByKey(key_tosearch, foundval);

        cout << "Found tracks: " << endl;
        foundval.displayInfo();

        cout << "retrieve another? y/n" << endl;
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

int makeSong(tree & songTree)
{       
    bool done = false;
    do 
    {  
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

        song songtoadd(artist_toadd, title_toadd, album_toadd, key1_toadd, key2_toadd, key3_toadd, description_toadd);

        songTree.insert(songtoadd); 

        cout << "Add another song? y/n" << endl;
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
