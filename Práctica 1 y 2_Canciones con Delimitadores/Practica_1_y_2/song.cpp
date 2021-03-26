#include "song.h"

string Song::getId() const
{
    return id;
}

void Song::setId(const string &value)
{
    id = value;
}

string Song::getNombre() const
{
    return nombre;
}

void Song::setNombre(const string &value)
{
    nombre = value;
}

string Song::getInterprete() const
{
    return interprete;
}

void Song::setInterprete(const string &value)
{
    interprete = value;
}

string Song::getStatus() const
{
    return status;
}

void Song::setStatus(const string &value)
{
    status = value;
}

string Song::getGenero() const
{
    return genero;
}

void Song::setGenero(const string &value)
{
    genero = value;
}

Song::Song()
{

}
