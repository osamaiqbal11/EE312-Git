//UtPod.cpp

#include <cstdlib>
#include <iostream>
#include "UtPod.h"
#include <time.h>

using namespace std;

//UtPod class declaration

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
    podMemSize = MAX_MEMORY;
    songs=NULL;
    time_t number;
    number = time (NULL);
    srand(number);
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
    if((size > MAX_MEMORY)|| (size<=0)){
        podMemSize = MAX_MEMORY;
    }
    else{
        podMemSize = size;
    }
    songs=NULL;
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/

int UtPod::addSong(Song const &s){
   // SongNode * songs1 = songs;

    if( (s.getSize()) > podMemSize){
        return NO_MEMORY;
    }
    else{
        SongNode *nodepnt= new SongNode;

        nodepnt->next = NULL;
        nodepnt->s = s;
        nodepnt->next = songs;
        songs = nodepnt;

        return SUCCESS;

    }
   // songs = songs1;
}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed


   input parms -

   output parms -
*/

int UtPod::removeSong(Song const &s){

    //temp = temp->next;
    //return SUCCESS;
    SongNode *temp = songs;
    SongNode *dltTemp = temp;

    while( temp != NULL) {
        if (temp->s == s) {
            dltTemp->next = temp->next;
            delete temp;
            return SUCCESS;
        }
        else{
            dltTemp = temp;
            temp = temp->next;
        }
    }
    if ( temp == NULL){
        return NOT_FOUND;
    }
    else{
        return SUCCESS;
    }

}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::shuffle(){
    int i = 0;
    SongNode *songs1= songs;
    SongNode *p1=songs1;
    SongNode *p2=songs1;

    while(i<numSongs()){
        int num1 = rand()%(numSongs());
        int num2 = rand()%(numSongs());
        int j =0;
        while(j<num1){
            p1=songs1->next;
            j++;
        }
        j =0;
        while(j<num2){
            p2=songs1->next;
            j++;
        }
        swapSongs(p1->s,p2->s);
        i++;
    }


}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms -

   output parms -
*/

void UtPod::showSongList(){
    SongNode *songs1 = songs;
    if(songs!= NULL) {
        while (songs != NULL) {
            cout << songs->s.getArtist() << ", " << songs->s.getTitle() << ", " << songs->s.getSize() << " MB" << "\n";
            songs = songs->next;
        }
    }
    else{
        int lol = 0;
    }
    songs = songs1;
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::sortSongList(){
    SongNode * songs1 = songs;
    for (SongNode *p = songs; p!= NULL; p = p->next){
        for(SongNode *p2 = p->next; p2!= NULL; p2 =p2->next){
            if (p2->s < p->s)
                swapSongs(p2->s, p2->s);
        }
    }


}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms -

   output parms -
*/
void UtPod::clearMemory(){
    SongNode * songs1 = songs;
    SongNode *temp= songs1;
    while(songs1!= NULL){
        while (temp->next!= NULL){
            temp=temp->next;
        }
        delete temp;
        temp = songs1;
    }

}


/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

int UtPod::getTotalMemory(){
    return (podMemSize);

}




/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms -

   output parms -
*/
void UtPod::swapSongs(Song song1, Song song2){
    Song temp= song2;

    temp.setArtist(song2.getArtist());
    temp.setTitle(song2.getTitle());
    temp.setSize(song2.getSize());
    song2.setArtist(song1.getArtist());
    song2.setTitle(song1.getTitle());
    song2.setSize(song1.getSize());
    song1.setArtist(temp.getArtist());
    song1.setTitle(temp.getTitle());
    song1.setSize(temp.getSize());

    //song2 =song1;
    //song1 = temp;
}

int UtPod::numSongs(){
    int total= 0;
    SongNode * songs1 = songs;

    while(songs1!= NULL){
        total++;
        songs1->next;
    }
    return (total);
}



int UtPod::getRemainingMemory(){
    SongNode * songs1 = songs;

    int total =0;
    while(songs1!=NULL){
        total = total + songs1->s.getSize();
        songs1 = songs1->next;
    }
    return total;

}

UtPod::~UtPod(){
    clearMemory();
}