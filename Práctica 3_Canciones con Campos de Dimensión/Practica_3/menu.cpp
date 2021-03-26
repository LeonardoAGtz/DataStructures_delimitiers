#include "menu.h"
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <math.h>
using namespace std;

Menu::Menu(){
    Song s; ///Objeto song
    string myStr; ///String para uso
    std::string cadenaContador = "";
    while (true) {
        //MENU
        system("cls");
        cout << "Menu Practica 3 by EvoSenpai(Leonardo Aranda 217761528 INNI)" << endl;
        cout << "1) Ingresar Cancion." << endl;
        cout << "2) Mostrar Canciones Activas." << endl;
        cout << "3) Contar Canciones." << endl;
        cout << "4) Eliminacion Logica." << endl;
        cout << "5) Eliminacion Fisica." << endl;
        cout << "6) Editar Cancion." << endl;
        cout << "7) Busqueda." << endl;
        cout << "8) Activar Registro." << endl;
        cout << "0) Salir." << endl;
        cout << ">>";
        getline(cin, myStr);

        if (myStr == "1") { //Añade canción *LISTO*
            char nombreC[30], artistaC[30], generoC[30], idC[8], estatusC[8];
            int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;

            system("cls");
            cout << "Nombre del Artista: ";
            cin.getline(artistaC, 30);
            artistaLen = strlen(artistaC);
            s.setArtist(artistaC);

            cout << "Nombre de la Cancion: ";
            cin.getline(nombreC, 30);
            nombreLen = strlen(nombreC);
            s.setName(nombreC);

            cout << "Genero Musical: ";
            cin.getline(generoC, 30);
            generoLen = strlen(generoC);
            s.setGenre(generoC);

            cadenaContador = std::to_string(contadorCanciones()+1);
            s.setId(cadenaContador);
            strcpy(idC, s.getId().c_str());
            idLen = stoi(s.getId());

            s.setStatus("1");
            strcpy(estatusC, s.getStatus().c_str());
            estatusLen = stoi(s.getStatus());

            cout << "\n Cancion ingresada exitosamente:\n";


            ofstream songsList("ListaCanciones.txt", ios::app);

            if (songsList.is_open()) {

                songsList.write((char*)&nombreLen, sizeof(int));
                songsList.write((char*)&nombreC, nombreLen);

                songsList.write((char*)&artistaLen, sizeof(int));
                songsList.write((char*)&artistaC, artistaLen);

                songsList.write((char*)&generoLen, sizeof(int));
                songsList.write((char*)&generoC, generoLen);

                songsList.write((char*)&idLen, sizeof(int));
                songsList.write((char*)&idC, idLen);

                songsList.write((char*)&estatusLen, sizeof(int));
                songsList.write((char*)&estatusC, estatusLen);

                songsList.close();

            }else{
                continue;
            }
            system("PAUSE");

        }else if (myStr == "2") { // Muestra todas las canciones *LISTO*
            char nombreC[30], artistaC[30], generoC[30], idC[8] = {"1"}, estatusC[8] = {"1"};
            int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;

            system("cls");
            ifstream archivoRec("ListaCanciones.txt", ios::in);
            Song songLoad;

            if (archivoRec.is_open()) {
                cout << "\n\t- CANCIONES: \n";

                while (!archivoRec.eof()) {

                    archivoRec.read((char*)&nombreLen , sizeof(int));
                    archivoRec.read((char*)&nombreC, nombreLen);
                    nombreC[nombreLen] = '\0';
                    songLoad.setName(nombreC);

                    if (archivoRec.eof())
                        break;

                    archivoRec.read((char*)&artistaLen, sizeof(int));
                    archivoRec.read((char*)&artistaC, artistaLen);
                    artistaC[artistaLen] = '\0';
                    songLoad.setArtist(artistaC);

                    archivoRec.read((char*)&generoLen, sizeof(int));
                    archivoRec.read((char*)&generoC, generoLen);
                    generoC[generoLen] = '\0';
                    songLoad.setGenre(generoC);

                    archivoRec.read((char*)&idLen, sizeof(int));
                    archivoRec.read((char*)&idC, idLen);
                    idC[idLen] = '\0';
                    songLoad.setId(idC);

                    archivoRec.read((char*)&estatusLen, sizeof(int));
                    archivoRec.read((char*)&estatusC, estatusLen);
                    estatusC[estatusLen] = '\0';
                    songLoad.setStatus(estatusC);

                    if (songLoad.getStatus() == "1") { //Si el Estatus es 0 no se imprimira
                        cout << "Codigo:  " << songLoad.getId() << endl;
                        cout << "Nombre:  " << songLoad.getName() << endl;
                        cout << "Artista: " << songLoad.getArtist() << endl;
                        cout << "Genero:  " << songLoad.getGenre() << endl << endl;
                    }
                }
            }else{
                continue;
            }
            archivoRec.close();
            system("PAUSE");

        }else if (myStr == "3") { //Cuenta todas las canciones *LISTO*
            system("cls");
            int i = contadorCanciones();
            cout << "Numero de canciones: ";
            cout << i << endl;
            system("PAUSE");

        }else if (myStr == "0") { //Cierrra el programa *LISTO*
            break;
        }else if (myStr == "4") { //Eliminación logica *LISTO*
            system("cls");
            char nombreC[30], artistaC[30], generoC[30], idC[8] = {"1"}, estatusC[8] = {"1"};
            int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;

            ifstream archivoRec("ListaCanciones.txt", ios::in);
            ofstream archivoTemp("Temporal.txt", ios::app);

            if (archivoRec.is_open()) {
                cout << "Ingresa el ID de la cancion a eliminar: ";
                getline(cin, myStr);
                if (existeCancion(myStr)) {
                    while (!archivoRec.eof()) {

                        archivoRec.read((char*)&nombreLen , sizeof(int));
                        archivoRec.read((char*)&nombreC, nombreLen);
                        nombreC[nombreLen] = '\0';

                        if (archivoRec.eof())
                            break;

                        archivoRec.read((char*)&artistaLen, sizeof(int));
                        archivoRec.read((char*)&artistaC, artistaLen);
                        artistaC[artistaLen] = '\0';

                        archivoRec.read((char*)&generoLen, sizeof(int));
                        archivoRec.read((char*)&generoC, generoLen);
                        generoC[generoLen] = '\0';

                        archivoRec.read((char*)&idLen, sizeof(int));
                        archivoRec.read((char*)&idC, idLen);
                        idC[idLen] = '\0';

                        archivoRec.read((char*)&estatusLen, sizeof(int));
                        archivoRec.read((char*)&estatusC, estatusLen);
                        estatusC[estatusLen] = '\0';

                        if (idC == myStr) { //Si el nombre coincidio se pone el estatus en 0

                            char estatusNC[2] = {"2"};
                            int estatusNLen = stoi(estatusNC);

                            archivoTemp.write((char*)&nombreLen, sizeof(int));
                            archivoTemp.write((char*)&nombreC, nombreLen);

                            archivoTemp.write((char*)&artistaLen, sizeof(int));
                            archivoTemp.write((char*)&artistaC, artistaLen);

                            archivoTemp.write((char*)&generoLen, sizeof(int));
                            archivoTemp.write((char*)&generoC, generoLen);

                            archivoTemp.write((char*)&idLen, sizeof(int));
                            archivoTemp.write((char*)&idC, idLen);

                            archivoTemp.write((char*)&estatusNLen, sizeof(int));
                            archivoTemp.write((char*)&estatusNC, estatusNLen);
                        }else{

                            archivoTemp.write((char*)&nombreLen, sizeof(int));
                            archivoTemp.write((char*)&nombreC, nombreLen);

                            archivoTemp.write((char*)&artistaLen, sizeof(int));
                            archivoTemp.write((char*)&artistaC, artistaLen);

                            archivoTemp.write((char*)&generoLen, sizeof(int));
                            archivoTemp.write((char*)&generoC, generoLen);

                            archivoTemp.write((char*)&idLen, sizeof(int));
                            archivoTemp.write((char*)&idC, idLen);

                            archivoTemp.write((char*)&estatusLen, sizeof(int));
                            archivoTemp.write((char*)&estatusC, estatusLen);
                        }
                    }
                }else{
                    continue;
                }
            }else{
                continue;
            }
            
            archivoRec.close();
            archivoTemp.close();

            remove("ListaCanciones.txt"); //Elimina el archivo
            rename("Temporal.txt","ListaCanciones.txt");//Renombra el archivo Temporal
            system("PAUSE");

        }else if (myStr == "5") { //Eliminación física *LISTO*
            system("cls");
            ifstream archivoRec("ListaCanciones.txt", ios::in);
            ofstream archivoTemp("Temporal.txt", ios::app);

            char nombreC[30], artistaC[30], generoC[30], idC[8], estatusC[8];
            int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;


            if (archivoRec.is_open()) {
                cout << "Ingresa el ID de la cancion a eliminar permanentemente: ";
                getline(cin, myStr);
                if (existeCancion(myStr)) {
                    while (!archivoRec.eof()) {

                        archivoRec.read((char*)&nombreLen , sizeof(int));
                        archivoRec.read((char*)&nombreC, nombreLen);
                        nombreC[nombreLen] = '\0';

                        if (archivoRec.eof())
                            break;

                        archivoRec.read((char*)&artistaLen, sizeof(int));
                        archivoRec.read((char*)&artistaC, artistaLen);
                        artistaC[artistaLen] = '\0';

                        archivoRec.read((char*)&generoLen, sizeof(int));
                        archivoRec.read((char*)&generoC, generoLen);
                        generoC[generoLen] = '\0';

                        archivoRec.read((char*)&idLen, sizeof(int));
                        archivoRec.read((char*)&idC, idLen);
                        idC[idLen] = '\0';

                        archivoRec.read((char*)&estatusLen, sizeof(int));
                        archivoRec.read((char*)&estatusC, estatusLen);
                        estatusC[estatusLen] = '\0';
                        string estado = estatusC;

                        if (idC == myStr && estado == "1") { //Si el no nombre coincidio lo guarda
                        }else{
                            archivoTemp.write((char*)&nombreLen, sizeof(int));
                            archivoTemp.write((char*)&nombreC, nombreLen);

                            archivoTemp.write((char*)&artistaLen, sizeof(int));
                            archivoTemp.write((char*)&artistaC, artistaLen);

                            archivoTemp.write((char*)&generoLen, sizeof(int));
                            archivoTemp.write((char*)&generoC, generoLen);

                            archivoTemp.write((char*)&idLen, sizeof(int));
                            archivoTemp.write((char*)&idC, idLen);

                            archivoTemp.write((char*)&estatusLen, sizeof(int));
                            archivoTemp.write((char*)&estatusC, estatusLen);
                        }
                    }
                }else{
                    continue;
                }
            }else{
                system("PAUSE");
            }

            archivoRec.close();
            archivoTemp.close();

            remove("ListaCanciones.txt"); //Elimina el archivo
            rename("Temporal.txt","ListaCanciones.txt");//Renombra el archivo Temporal

            system("PAUSE");

        }else if (myStr == "6") { //Editar datos
            system("cls");
            ifstream archivoRec("ListaCanciones.txt", ios::in);
            ofstream archivoTemp("Temporal.txt", ios::app);

            char nombreC[30], artistaC[30], generoC[30], idC[8], estatusC[8];
            int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;

            if (archivoRec.is_open()) {
                cout << "Ingresa el ID de la cancion a editar: ";
                getline(cin, myStr);

                if (existeCancion(myStr)) {

                    while (!archivoRec.eof()) {

                        Song songLoad;

                        archivoRec.read((char*)&nombreLen , sizeof(int));
                        archivoRec.read((char*)&nombreC, nombreLen);
                        nombreC[nombreLen] = '\0';
                        string nombreL = nombreC;
                        songLoad.setName(nombreC);

                        if (archivoRec.eof())
                            break;

                        archivoRec.read((char*)&artistaLen, sizeof(int));
                        archivoRec.read((char*)&artistaC, artistaLen);
                        artistaC[artistaLen] = '\0';
                        string artistaL = artistaC;
                        songLoad.setArtist(artistaC);

                        archivoRec.read((char*)&generoLen, sizeof(int));
                        archivoRec.read((char*)&generoC, generoLen);
                        generoC[generoLen] = '\0';
                        string generoL = generoC;
                        songLoad.setGenre(generoC);

                        archivoRec.read((char*)&idLen, sizeof(int));
                        archivoRec.read((char*)&idC, idLen);
                        idC[idLen] = '\0';
                        string idL = idC;
                        songLoad.setId(idC);

                        archivoRec.read((char*)&estatusLen, sizeof(int));
                        archivoRec.read((char*)&estatusC, estatusLen);
                        estatusC[estatusLen] = '\0';
                        string estadoL = estatusC;
                        songLoad.setStatus(estatusC);

                        if (idL == myStr && estadoL == "2") {
                        }
                        if (idL == myStr && estadoL == "1") { //Si el nombre coincidio edito los datos y lo guardo al final

                            //Ingresar nuevo
                            cout << "Ingresa el Artista (" << artistaL << "): ";
                            cin.getline(artistaC, 30);
                            artistaLen = strlen(artistaC);
                            s.setArtist(artistaC);

                            cout << "Ingresa el Nombre (" << nombreL << "): ";
                            cin.getline(nombreC, 30);
                            nombreLen = strlen(nombreC);
                            s.setName(nombreC);

                            cout << "Ingresa el Genero (" << generoL << "): ";
                            cin.getline(generoC, 30);
                            generoLen = strlen(generoC);
                            s.setGenre(generoC);

                            s.setId(idL);
                            //strcpy(idL, s.getId().c_str());
                            idLen = stoi(s.getId());

                            cout << "Ingresa el Estado (" << estadoL << "): ";
                            cin.getline(estatusC, 8);
                            s.setStatus(estatusC);
                            strcpy(estatusC, s.getStatus().c_str());
                            estatusLen = stoi(s.getStatus());

                            //cout << s.toString();
                            cout << s << endl << endl;

                            archivoTemp.write((char*)&nombreLen, sizeof(int));
                            archivoTemp.write((char*)&nombreC, nombreLen);

                            archivoTemp.write((char*)&artistaLen, sizeof(int));
                            archivoTemp.write((char*)&artistaC, artistaLen);

                            archivoTemp.write((char*)&generoLen, sizeof(int));
                            archivoTemp.write((char*)&generoC, generoLen);

                            archivoTemp.write((char*)&idLen, sizeof(int));
                            archivoTemp.write((char*)&idC, idLen);

                            archivoTemp.write((char*)&estatusLen, sizeof(int));
                            archivoTemp.write((char*)&estatusC, estatusLen);

                            cout << "Cancion editada con exito, guardada con ID anterior." << endl;
                            continue;

                        }else{

                            archivoTemp.write((char*)&nombreLen, sizeof(int));
                            archivoTemp.write((char*)&nombreC, nombreLen);

                            archivoTemp.write((char*)&artistaLen, sizeof(int));
                            archivoTemp.write((char*)&artistaC, artistaLen);

                            archivoTemp.write((char*)&generoLen, sizeof(int));
                            archivoTemp.write((char*)&generoC, generoLen);

                            archivoTemp.write((char*)&idLen, sizeof(int));
                            archivoTemp.write((char*)&idC, idLen);

                            archivoTemp.write((char*)&estatusLen, sizeof(int));
                            archivoTemp.write((char*)&estatusC, estatusLen);


                        }
                    }
                }else{
                    continue;
                }
            }else{
                continue;
            }

            archivoTemp.close();
            archivoRec.close();

            remove("ListaCanciones.txt"); //Elimina el archivo
            rename("Temporal.txt","ListaCanciones.txt");//Renombra el archivo Temporal

            system("PAUSE");

        }else if (myStr == "7") { //Busqueda *LISTO*
            system("cls");
            ifstream archivoRec("ListaCanciones.txt", ios::in);
            char nombreC[30], artistaC[30], generoC[30], idC[8], estatusC[8];
            int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;

            if (archivoRec.is_open()) {
                cout << "Ingresa el ID de la cancion a buscar: ";
                getline(cin, myStr);
                if (existeCancion(myStr)) {
                    while (!archivoRec.eof()) {

                        Song songLoad;

                        archivoRec.read((char*)&nombreLen , sizeof(int));
                        archivoRec.read((char*)&nombreC, nombreLen);
                        nombreC[nombreLen] = '\0';
                        songLoad.setName(nombreC);

                        if (archivoRec.eof())
                            break;

                        archivoRec.read((char*)&artistaLen, sizeof(int));
                        archivoRec.read((char*)&artistaC, artistaLen);
                        artistaC[artistaLen] = '\0';
                        songLoad.setArtist(artistaC);

                        archivoRec.read((char*)&generoLen, sizeof(int));
                        archivoRec.read((char*)&generoC, generoLen);
                        generoC[generoLen] = '\0';
                        songLoad.setGenre(generoC);

                        archivoRec.read((char*)&idLen, sizeof(int));
                        archivoRec.read((char*)&idC, idLen);
                        idC[idLen] = '\0';
                        string idL = idC;
                        songLoad.setId(idC);

                        archivoRec.read((char*)&estatusLen, sizeof(int));
                        archivoRec.read((char*)&estatusC, estatusLen);
                        estatusC[estatusLen] = '\0';
                        string estadoL = estatusC;
                        songLoad.setStatus(estatusC);

                        if (idL == myStr && estadoL == "1") {
                            cout << "Codigo:  " << songLoad.getId() << endl;
                            cout << "Nombre:  " << songLoad.getName() << endl;
                            cout << "Artista: " << songLoad.getArtist() << endl;
                            cout << "Genero:  " << songLoad.getGenre() << endl << endl;
                        }else if (idL == myStr && estadoL == "2") {
                        }
                    }
                }else{
                }
            }else{
                continue;
            }

            archivoRec.close();
            system("PAUSE");

        }else if (myStr == "8") { //Activar registro *LISTO*
            system("cls");
            ifstream archivoRec("ListaCanciones.txt", ios::in);
            ofstream archivoTemp("Temporal.txt", ios::app);

            char nombreC[30], artistaC[30], generoC[30], idC[8], estatusC[8];
            int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;

            if (archivoRec.is_open()) {
                cout << "\n\t+> Ingresa el ID de la cancion a reactivar: ";
                getline(cin, myStr);
                if (existeCancion(myStr)) {

                    while (!archivoRec.eof()) {

                        archivoRec.read((char*)&nombreLen , sizeof(int));
                        archivoRec.read((char*)&nombreC, nombreLen);
                        nombreC[nombreLen] = '\0';

                        if (archivoRec.eof())
                            break;

                        archivoRec.read((char*)&artistaLen, sizeof(int));
                        archivoRec.read((char*)&artistaC, artistaLen);
                        artistaC[artistaLen] = '\0';

                        archivoRec.read((char*)&generoLen, sizeof(int));
                        archivoRec.read((char*)&generoC, generoLen);
                        generoC[generoLen] = '\0';

                        archivoRec.read((char*)&idLen, sizeof(int));
                        archivoRec.read((char*)&idC, idLen);
                        idC[idLen] = '\0';

                        archivoRec.read((char*)&estatusLen, sizeof(int));
                        archivoRec.read((char*)&estatusC, estatusLen);
                        estatusC[estatusLen] = '\0';

                        if (idC == myStr) { //Si el nombre coincidio se pone el estatus en 1 para activarla
                            char estatusNC[8] = {"1"};
                            int estatusNLen = stoi(estatusNC);

                            archivoTemp.write((char*)&nombreLen, sizeof(int));
                            archivoTemp.write((char*)&nombreC, nombreLen);

                            archivoTemp.write((char*)&artistaLen, sizeof(int));
                            archivoTemp.write((char*)&artistaC, artistaLen);

                            archivoTemp.write((char*)&generoLen, sizeof(int));
                            archivoTemp.write((char*)&generoC, generoLen);

                            archivoTemp.write((char*)&idLen, sizeof(int));
                            archivoTemp.write((char*)&idC, idLen);

                            archivoTemp.write((char*)&estatusNLen, sizeof(int));
                            archivoTemp.write((char*)&estatusNC, estatusNLen);
                        }else{

                            archivoTemp.write((char*)&nombreLen, sizeof(int));
                            archivoTemp.write((char*)&nombreC, nombreLen);

                            archivoTemp.write((char*)&artistaLen, sizeof(int));
                            archivoTemp.write((char*)&artistaC, artistaLen);

                            archivoTemp.write((char*)&generoLen, sizeof(int));
                            archivoTemp.write((char*)&generoC, generoLen);

                            archivoTemp.write((char*)&idLen, sizeof(int));
                            archivoTemp.write((char*)&idC, idLen);

                            archivoTemp.write((char*)&estatusLen, sizeof(int));
                            archivoTemp.write((char*)&estatusC, estatusLen);
                        }

                    }
                }else{
                    cout << "\n- ERROR: La cancion no existe.\n";
                    system("PAUSE");
                    continue;
                }
            }else{
                cout << "\n- ERROR: Archivo no creado o corrupto.\n";
                system("PAUSE");
            }

            archivoRec.close();
            archivoTemp.close();

            remove("ListaCanciones.txt"); //Elimina el archivo
            rename("Temporal.txt","ListaCanciones.txt");//Renombra el archivo Temporal

            cout << "\n\t- MENSAJE: activacion exitosa" << endl;
            system("PAUSE");

        }
    }
}

int Menu::contadorCanciones(){ //Cuenta as canciones para el ID *LISTO*
    ifstream archivoRec("ListaCanciones.txt", ios::in);
    char nombreC[30], artistaC[30], generoC[30], idC[8] = {"1"}, estatusC[8] = {"1"};
    int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;
    int j = 0;

    if (archivoRec.is_open()) {

        while (!archivoRec.eof()) {

            archivoRec.read((char*)&nombreLen , sizeof(int));
            archivoRec.read((char*)&nombreC, nombreLen);
            nombreC[nombreLen] = '\0';

            if (archivoRec.eof())
                break;

            archivoRec.read((char*)&artistaLen, sizeof(int));
            archivoRec.read((char*)&artistaC, artistaLen);
            artistaC[artistaLen] = '\0';

            archivoRec.read((char*)&generoLen, sizeof(int));
            archivoRec.read((char*)&generoC, generoLen);
            generoC[generoLen] = '\0';

            archivoRec.read((char*)&idLen, sizeof(int));
            archivoRec.read((char*)&idC, idLen);
            idC[idLen] = '\0';

            archivoRec.read((char*)&estatusLen, sizeof(int));
            archivoRec.read((char*)&estatusC, estatusLen);
            estatusC[estatusLen] = '\0';

            j++;
        }
    }
    archivoRec.close();
    return j;
}

bool Menu::existeCancion(string ID){ //Comprueba que el ID existe *LISTO*
    ifstream archivoRec("ListaCanciones.txt", ios::in);
    char nombreC[30], artistaC[30], generoC[30], idC[8], estatusC[8];
    int nombreLen=0, artistaLen=0, generoLen=0, idLen=0, estatusLen=0;

    bool existe = false;

    if (archivoRec.is_open()) {

        while (!archivoRec.eof()) {

            archivoRec.read((char*)&nombreLen , sizeof(int));
            archivoRec.read((char*)&nombreC, nombreLen);
            nombreC[nombreLen] = '\0';

            if (archivoRec.eof())
                break;

            archivoRec.read((char*)&artistaLen, sizeof(int));
            archivoRec.read((char*)&artistaC, artistaLen);
            artistaC[artistaLen] = '\0';

            archivoRec.read((char*)&generoLen, sizeof(int));
            archivoRec.read((char*)&generoC, generoLen);
            generoC[generoLen] = '\0';

            archivoRec.read((char*)&idLen, sizeof(int));
            archivoRec.read((char*)&idC, idLen);
            idC[idLen] = '\0';

            archivoRec.read((char*)&estatusLen, sizeof(int));
            archivoRec.read((char*)&estatusC, estatusLen);
            estatusC[estatusLen] = '\0';

            if (ID == idC) {
                existe = true;
            }
        }
    }
    archivoRec.close();
    return existe;
}
