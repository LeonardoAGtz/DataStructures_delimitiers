#ifndef SONG_H
#define SONG_H
#include <iostream>

using namespace std;

class Song
{
    string id, nombre, interprete, genero, status;
public:
    Song();

    string getId() const;
    void setId(const string &value);
    string getNombre() const;
    void setNombre(const string &value);
    string getInterprete() const;
    void setInterprete(const string &value);
    string getStatus() const;
    void setStatus(const string &value);
    string getGenero() const;
    void setGenero(const string &value);
};

#endif // SONG_H
