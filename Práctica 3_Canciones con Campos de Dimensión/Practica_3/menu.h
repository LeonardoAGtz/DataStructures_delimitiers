#ifndef MENU_H
#define MENU_H

#include <string>
#include "song.h"
#include <fstream>
#include <sstream>

class Menu
{
public:
    Menu();
    int contadorCanciones();
    int conseguirUltimoN();
    bool existeCancion(std::string ID);
};

#endif // MENU_H
