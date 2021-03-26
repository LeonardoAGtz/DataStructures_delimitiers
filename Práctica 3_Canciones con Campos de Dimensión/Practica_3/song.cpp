#include "song.h"
using namespace std;

Song::Song(){}

Song::Song(const Song& s) : artist(s.artist), name(s.name), genre(s.genre){ }//< Constructor copia

string Song::getArtist(){
    return artist;
}
void Song::setArtist(const string &r){
    artist = r;
}
string Song::getName(){
    return name;
}
void Song::setName(const string &n){
    name = n;
}
string Song::getGenre(){
    return genre;
}
void Song::setGenre(const string &g){
    genre = g;
}

std::string Song::getId()
{
    return id;
}

void Song::setId(const std::string &value)
{
    id = value;
}

std::string Song::getStatus()
{
    return status;
}

void Song::setStatus(const std::string &value)
{
    status = value;
}

string Song::toString(){
    string line = "|-----------------------------------------------------------------|";
    return "\n   " + name + "   |      " + artist + "      |   " + genre + "\n" + line;

}

Song& Song::operator=(const Song& s) {
    artist = s.artist;
    name = s.name;
    genre = s.genre;
    return *this;
}
ostream &operator << (ostream &o, Song &s){
    o << "\t+ Nombre: " << s.getName() << endl
      << "\t+ Artista: " << s.getArtist() << endl
      << "\t+ Genero: " << s.getGenre() << endl
      << "\t+ ID: " << s.getId() << endl
      << "\t+ ES: " << s.getStatus();
    return o;
}

istream& operator >> (istream& is, Song& s){
    getline(is, s.artist);
    getline(is, s.name);
    getline(is, s.genre);
    return is;
}

bool Song::operator==(const Song& s) {
    return s.name == name;
}
bool Song::operator!=(const Song& s) {
    return s.name != name;
}
bool Song::operator<=(const Song&s) {
    return s.name <= name; //< Modificar
}
bool Song::operator>=(const Song&s) {
    return s.name >= name; //< Modificar
}
bool Song::operator<(const Song&s) {
    return s.name < name; //< Modificar
}
bool Song::operator>(const Song&s) {
    return s.name > name; //< Modificar
}

