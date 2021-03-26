#include "menu.h"

Menu::Menu()
{
    string op;
    while (true) {
        system("cls");
        cout << "Menu Practica 1 y 2 by EvoSenpai(Leonardo Aranda 217761528 INNI)" << endl;
        cout << "   1) Crear Cancion" << endl;
        cout << "   2) Mostrar Canciones" << endl;
        cout << "   3) Contar Canciones" << endl;
        cout << "   4) Eliminar Fisicamente" << endl;
        cout << "   5) Eliminar Logicamente" << endl;
        cout << "   6) Editar Cancion" << endl;
        cout << "   7) Buscar Cancion" << endl;
        cout << "   8) Activar Registro" << endl;
        cout << "   0) Salir" << endl;
        cout << endl;
        cout << "   >>";
        getline(cin, op);

        if (op == "1") {
            create();
        }else if (op == "2") {
            read();
            system("pause");
        }else if (op == "3") {
            count();
            system("cls");
        }else if (op == "4") {
            delete_F();
        }else if (op == "5") {
            delete_L();
        }else if (op == "6") {
            update();
        }else if (op == "7") {
            system("cls");
            string code;
            cout << "Ingresa el id de la cancion que buscas: ";
            getline(cin, code);
            cout << endl;
            find(code);
            system("pause");
        }else if (op == "8") {
            activate();
        }else if (op == "0") {
            break;
        }
    }
}

void Menu::create()
{
    system("cls");
    Song song;
    string temp;

    song.setId(lastcode());
    cout << "Nombre de la cancion: ";
    getline(cin, temp);
    song.setNombre(temp);
    cout << "Interprete de la cancion: ";
    getline(cin, temp);
    song.setInterprete(temp);
    cout << "Genero de la cancion: ";
    getline(cin, temp);
    song.setGenero(temp);
    temp = "1";
    song.setStatus(temp);


    ofstream save("Canciones_W_D.txt", ios::app);
    save << song.getId() << endl;
    save << song.getNombre() << endl;
    save << song.getInterprete() << endl;
    save << song.getGenero() << endl;
    save << song.getStatus() << endl << endl;
    save.close();

}

void Menu::read()
{
    system("cls");
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getStatus() == "1") {
                cout << "Cancion:    " << song.getId() << endl;
                cout << "Nombre:     " << song.getNombre() << endl;
                cout << "Interprete: " << song.getInterprete() << endl;
                cout << "Genero:     " << song.getGenero() << endl;
                cout << "Status:     " << song.getStatus() << endl << endl;
            }
        }
    }load.close();
}

void Menu::update()
{
    read();
    string code;

    cout << endl << endl << "Ingresa el ID de la cancion que deseas editar: ";
    getline(cin, code);

    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() == code and song.getStatus() == "1") {
                string temp2;
                cout << "Cancion:          " << song.getId() << endl;
                cout << "Nuevo Nombre:     ";
                getline(cin, temp2);
                song.setNombre(temp2);
                cout << "Nuevo Interprete: ";
                getline(cin, temp2);
                song.setInterprete(temp2);
                cout << "Nuevo Genero:     ";
                getline(cin, temp2);
                song.setGenero(temp2);
            }

            ofstream save("Temp_C_W_D.txt", ios::app);
            save << song.getId() << endl;
            save << song.getNombre() << endl;
            save << song.getInterprete() << endl;
            save << song.getGenero() << endl;
            save << song.getStatus() << endl << endl;
            save.close();

        }
    }load.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

void Menu::delete_F()
{
    read();
    string code;

    cout << endl << endl << "Ingresa el ID de la cancion que deseas eliminar: ";
    getline(cin, code);

    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() != code and song.getStatus() == "1") {
                ofstream save("Temp_C_W_D.txt", ios::app);
                save << song.getId() << endl;
                save << song.getNombre() << endl;
                save << song.getInterprete() << endl;
                save << song.getGenero() << endl;
                save << song.getStatus() << endl << endl;
                save.close();
            }
        }
    }load.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

void Menu::delete_L()
{
    read();
    string code;

    cout << endl << endl << "Ingresa el ID de la cancion que deseas desactivar: ";
    getline(cin, code);

    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() == code and song.getStatus() == "1") {
                string temp2 = "0";
                song.setStatus(temp2);
            }

            ofstream save("Temp_C_W_D.txt", ios::app);
            save << song.getId() << endl;
            save << song.getNombre() << endl;
            save << song.getInterprete() << endl;
            save << song.getGenero() << endl;
            save << song.getStatus() << endl << endl;
            save.close();

        }
    }load.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

void Menu::find(const string &code)
{
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getId() == code and song.getStatus() == "1") {
                cout << "Cancion:    " << song.getId() << endl;
                cout << "Nombre:     " << song.getNombre() << endl;
                cout << "Interprete: " << song.getInterprete() << endl;
                cout << "Genero:     " << song.getGenero() << endl;
                cout << "Status:     " << song.getStatus() << endl << endl;
            }
        }
    }load.close();
}

void Menu::count()
{
    system("cls");
    int counter = 0;
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);
            counter++;
        }
    }load.close();

    cout << "Hay: " << counter << "canciones registradas :D" << endl;
}

void Menu::activate()
{
    system("cls");
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);

            if (song.getStatus() == "0") {
                cout << "Cancion:    " << song.getId() << endl;
                cout << "Nombre:     " << song.getNombre() << endl;
                cout << "Interprete: " << song.getInterprete() << endl;
                cout << "Genero:     " << song.getGenero() << endl;
                cout << "Status:     " << song.getStatus() << endl << endl;
            }
        }
    }load.close();

    string code;
    cout << endl << endl << "Ingresa el id de la cancion que quieres activar: ";
    getline(cin, code);

    ifstream load2("Canciones_W_D.txt", ios::in);
    if (load2.is_open()) {
        while (!load2.eof()) {
            string temp;
            Song song;
            getline(load2, temp);
            if (load2.eof()){break;}
            song.setId(temp);
            getline(load2, temp);
            song.setNombre(temp);
            getline(load2, temp);
            song.setInterprete(temp);
            getline(load2, temp);
            song.setGenero(temp);
            getline(load2, temp);
            song.setStatus(temp);
            getline(load2, temp);

            if (song.getId() == code and song.getStatus() == "0") {
                string temp2 = "1";
                song.setStatus(temp2);
            }

            ofstream save("Temp_C_W_D.txt", ios::app);
            save << song.getId() << endl;
            save << song.getNombre() << endl;
            save << song.getInterprete() << endl;
            save << song.getGenero() << endl;
            save << song.getStatus() << endl << endl;
            save.close();

        }
    }load2.close();

    remove("Canciones_W_D.txt");
    rename("Temp_C_W_D.txt","Canciones_W_D.txt");
}

string Menu::lastcode()
{
    int counter = 0;
    ifstream load("Canciones_W_D.txt", ios::in);
    if (load.is_open()) {
        while (!load.eof()) {
            string temp;
            Song song;

            getline(load, temp);
            if (load.eof()){break;}
            song.setId(temp);
            counter = stoi(temp);//Obtener id
            getline(load, temp);
            song.setNombre(temp);
            getline(load, temp);
            song.setInterprete(temp);
            getline(load, temp);
            song.setGenero(temp);
            getline(load, temp);
            song.setStatus(temp);
            getline(load, temp);
        }
    }load.close();

    counter++;
    char ident[5];
    sprintf(ident, "%d", counter);
    string id(ident);

    return ident;
}
