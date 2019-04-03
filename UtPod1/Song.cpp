//Song.cpp

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include <string>


Song::Song(){

    title = "";
    artist = "";
    size = 0;
}

Song::Song(string _artist, string _title, int _size){
    artist= _artist;
    title= _title;
    size= _size;
}

string Song::getTitle() const{
    return title;

}

string Song::getArtist() const{
    return artist;

}

int Song::getSize() const{
    return size;

}

void Song::setTitle(string _title){
    this->title= _title;

}

void Song::setArtist(string _artist){
    this->artist= _artist;
}

void Song::setSize(int _size){
    this->size= _size;

}

bool Song::operator <(Song const &rhs){

    if(artist != rhs.artist){
        if(artist < rhs.artist){
            return true;
        }
        else{
            return false;
        }
    }
    if(title != rhs.title){
        if( title < rhs.title){
            return true;
        }
        else{
            return false;
        }
    }
    if(size != rhs.size){
        if(size < rhs.size){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Song::operator >(Song const &rhs){
    if( artist != rhs.artist){
        if(artist > rhs.artist){
            return true;
        }
        else{
            return false;
        }
    }
    if( title != rhs.title){
        if(title > rhs.title){
            return true;
        }
        else{
            return false;
        }
    }
    if( size != rhs.size){
        if(size > rhs.size){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Song::operator ==(Song const &rhs){
    if((title == rhs.title) && (artist == rhs.artist) && (size == rhs.size)){
        return true;
    }
    else{
        return false;
    }

}