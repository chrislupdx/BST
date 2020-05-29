#include "tree.h" 
#include <fstream>
#include <iostream>
using namespace std;

int makeSong(tree & songTree);
int retrieve(tree & songTree); //will this be awful to just pass by value
//removeByArist
//displayByKey
//getheight
//isefficient
int main() 
{
    tree niceTree;
    
    niceTree.displayAll();
    makeSong(niceTree); 
    niceTree.displayAll();
    retrieve(niceTree);
    niceTree.displayAll(); 
   
   return 1;
}

int retrieve(tree & songTree) //there's a double free error going on here
{
    std::cout << "retrieve" << std::endl;
    songTree.displayAll();
    
    song foundval;
    char key_tosearch[20];
    cout << "Retrieve" << endl;
    cout << "Enter artist name: " << endl;
    cin.get(key_tosearch, 100, '\n');
    cin.ignore(100, '\n'); cout << endl;
   
    songTree.retrieveByKey(key_tosearch, foundval);

    cout << "Found tracks: " << endl; //make this plural?
    foundval.displayInfo();
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

//        char * keyval = new char[strlen(title_toadd) + 1]; //
 //       strcpy(keyval, title_toadd); //what are we oding here

        song songtoadd(artist_toadd, title_toadd, album_toadd, key1_toadd, key2_toadd, key3_toadd, description_toadd);

        songTree.insert(songtoadd);  //we're indexing by song name

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
};
