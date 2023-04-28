// Playlist.cpp

#include "include/Playlist.h"
#include "include/str_utils.h"

Playlist::Playlist(string aName) {
    name = aName;
 
}
Playlist::Playlist(const Playlist & aPlaylist){
    name = aPlaylist.name;
    for(auto track: aPlaylist.tracks) {tracks.insert(track);}

}
Playlist & Playlist::operator=(const Playlist & aPlaylist) {
    if(&aPlaylist != this) {
        //delete
        // delete playlists;
        //..
        //set
        name = aPlaylist.name;
        for(auto track: aPlaylist.tracks) {tracks.insert(track);}
    }
    return *this;
}
Playlist::~Playlist(){

}
void Playlist::printOn(ostream & out) const {out << left << setw(10) << name;}
ostream & operator<<(ostream & o, const Playlist & s) { s.printOn(o);  return o;}


string Playlist::getName(){ return name;}

map<int, T*> Playlist::getTracks(){return tracks;}
void Playlist::addTrack(int t_id, Track & t) {
    tracks[t_id] = &t;
}
void Playlist::removeTrack(int t_id) {
    tracks.erase(t_id);
}

