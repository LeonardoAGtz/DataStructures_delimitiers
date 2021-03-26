#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>
#include <cstdio>

class Song{
    public:
        Song();
        Song(const Song&);

        std::string getArtist();
        void setArtist(const std::string &);

        std::string getName();
        void setName(const std::string &);

        std::string getGenre();
        void setGenre(const std::string &);

        std::string getId();
        void setId(const std::string &value);

        std::string getStatus();
        void setStatus(const std::string &value);

        std::string toString();

        Song& operator = (const Song&);

        friend std::ostream& operator << (std::ostream&, Song&);
        friend std::istream& operator >> (std::istream&, Song&);

        bool operator == (const Song&);
        bool operator != (const Song&);
        bool operator <= (const Song&);
        bool operator >= (const Song&);
        bool operator < (const Song&);
        bool operator > (const Song&);


private:
        std::string artist;
        std::string name;
        std::string genre;
        std::string id;
        std::string status;
};

#endif
