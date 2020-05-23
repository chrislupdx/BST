//Chris Lu //Project 3
//Table.cpp
//This is the implementation of the .cpp file for the hash table ADT

#include "table.h"
using namespace std;

//The default constructor for the hash table
table::table(int size)
{
    hash_table_size = size;
    hash_table = new tNode * [size];
    for (int i = 0; i < size; i++)
    {
        hash_table[i] = NULL;
    }
}

//Default destructor
table::~table()
{
    for(int i = 0; i < hash_table_size; i++)
    {
        delete hash_table[i];
        hash_table[i] = NULL; 
    }

    hash_table_size = 0;
}

//This function recursively traverses a chain, leveraging song's 
//print function on each recursive call
int table::displayMatches(tNode * head)
{
    if(!head) return 0;

    head->songInfo->displayInfo();    

    displayMatches(head->next);

    return 1;
}

//display all matches for a search key (user input)
int table::displaySearch(char * sK)
{
    int searchI = hash_function(sK);
    tNode * head = hash_table[searchI];
    if(!head)
    {
        return 0; //is emptpy
    }
    else
    {
        std::cout << "Match found, display? (y/n)" << std::endl; 
        char answer; 
        cin >> answer;
        if(answer == 'y')
        {
            displayMatches(head);
        }

    }
    return 1;
}

//This hash function concanetates the ascii value of each character in the given string
int table::hash_function(char *key) const
{
    int hash = 0;
    int keyLen = strlen(key);
    for(int i = 0; i<keyLen; i++)
    {
        hash =+ key[i];
    }
    return hash;
}

//this is the interface function for insertion.
int table::insertSong(char * key_val, song & song_toadd)
{
    int i = hash_function(key_val) % hash_table_size; 
    
    tNode * temp = hash_table[i]; //hold onto the old part
    if(!hash_table[i]) //if empty
    {
    hash_table[i] = new tNode;
    hash_table[i]->songInfo->copySong(song_toadd);
    }
    else                //else (if not empty)
    {
    hash_table[i] = new tNode;
    hash_table[i]->songInfo->copySong(song_toadd);
    hash_table[i]->next = temp;
    }
    return 1;
}

//iterates through the chain, calling displaySong on each node
int table::displayChain(tNode * head) //head==hash_table[i] rn
{
    while(head)
    {
        head->songInfo->displayInfo();
        head = head->next;
    }
    return 1;
}

//displayAll is a wrapper function that iterates through the table
int table::displayAll() //this displays the whole hash table
{
    std::cout << "Contents of the table: " << std::endl;
    for(int i = 0; i < hash_table_size; i++)
    {
        if(hash_table[i])
        {
            std::cout << "Chain #" << i << " : " << std::endl;
            displayChain(hash_table[i]);
            std::cout << std::endl;
        } 
    }
    return 1;
}

//This function takes the char parm, hashes it into an index and copys found with the matching value
//if it finds multiples, it should write found over resulting in only the last
int table::retrieveSong(char * title_to_find, song & found)
{
    int retrieveI = hash_function(title_to_find);

    for(int i = 0; i < hash_table_size; i++)                //traverse the hash table
    {
        if(retrieveI == i)                                  //When you find the right chain
        {
            tNode * head = hash_table[i]; 
            while(head)                                     //Traverse the chain
            {
                if(strcmp(title_to_find, head->songInfo->songN) == 1) //if does not match
                {
                    head = head->next;
                } 
                else {
                    found.copySong(*head->songInfo);              
                    std::cout << head->songInfo->displayInfo(); //songs, not entries
                    return 1; 
                }
            }
        }
    }
    return 1;
}

//Traverse the table to find matching artist tracks, then calls a recursive deletion
int table::removeArtistTracks(char * artist_to_find)
{
    //traverse the entire hash table
    for(int i = 0; i < hash_table_size; i++)
        removeFChain(artist_to_find, hash_table[i]);

    return 1;
}

//This function recursively iterates through the chain and find+deletes matching values
int table::removeFChain(char * artist_to_find, tNode *& head)
{
    if(!head) return 0;
    if(strcmp(artist_to_find, head->songInfo->artist) == 0) 
    {
        tNode * temp = head->next;
        delete head;
        head = temp;
        return removeFChain(artist_to_find, head); //this is traversal
    }
    return removeFChain(artist_to_find, head->next);
}

//parses the file into song structs, then inserts them into the table
int table::readFile(song *& songs, int size) //songs is an array
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
            insertSong(temptitle, newsong);  //we are using the song titles as keys

            eof = inFile.peek();
            count++;
        }
    }
    inFile.close();
    inFile.clear();
    return 1;
}
