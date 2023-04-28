// User.cpp

#include "include/User.h"

User::User(string u_id, string aName) {
    id = u_id;
    name = aName;}

User::User(const User & aUser) { 
    id = aUser.id;
    name = aUser.name;
    for ( auto it = aUser.playlists.begin(); it != aUser.playlists.end(); ++it ) {playlists[it->first] = it->second;}}

User::~User(){
    for(auto p: playlists) {
        delete p.second;
        p.second = NULL;
    }
    playlists.clear();
}
User & User::operator=(const User & aUser) {
    if(&aUser != this) {
        //delete
        // delete playlists;
        //..
        for ( auto it = aUser.playlists.begin(); it != aUser.playlists.end(); ++it ){ 
            delete it->second;
            playlists.erase(it);
        }
        //set
        id = aUser.id;
        name = aUser.name;
            for ( auto it = aUser.playlists.begin(); it != aUser.playlists.end(); ++it ) {playlists[it->first] = it->second;}
    }
    return *this;}
void User::printOn(ostream & out) const{out << left << setw(20) << id << setw(30) << name;}


string User::getUserId(){return id;}
string User::getName(){return name;}
Playlists User:: getPlaylists() {return playlists;}
P* User::getPlaylist(string name) {
    return playlists[name];}

int  User::addPlaylist(string name) {
    Playlists::iterator i = playlists.find(name);
    if(i != playlists.end()) { return -1; }//playlist already exists.
        Playlist *p = new Playlist(name);
        playlists.insert({name, p});
        return 1; // new playlast has been made
 
}
void User::deletePlaylist(string name) {
    playlists.erase(name);
}

ostream & operator<<(ostream & o, const User & u) { u.printOn(o);  return o;}



