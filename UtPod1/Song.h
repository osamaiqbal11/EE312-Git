//Song.h

#ifndef SONG_H
#define SONG_H

using namespace std;

class Song{

private:
    string title;
    string artist;
    int size;


public:
    Song();
    Song(string _artist, string _title, int _size);

    string getTitle() const;
    string getArtist() const;
    int getSize() const;
    void setTitle(string _title);
    void setArtist(string _artist);
    void setSize(int _size);

    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);


};






#endif