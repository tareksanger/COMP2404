// Track.cpp

#include "include/Track.h"



Track::Track(int t_id, Record * aRecord, Song * aSong, int t_num): recordTrackIsIn(aRecord), recordingOf(aSong) { 
    id = t_id;
    number = t_num;
}

Track::Track(int t_id, Song * aSong): recordingOf(aSong) { 
    id = t_id;
}
Track::Track(Song * aSong): recordingOf(aSong) {}



Track::Track(const Track & aTrack):  recordTrackIsIn(aTrack.recordTrackIsIn), recordingOf(aTrack.recordingOf) {
    id = aTrack.id;
    number = aTrack.number;
    for(auto p: aTrack.playlistsTrackIsIn) {playlistsTrackIsIn.insert(p);}
}

Track & Track::operator=(const Track & aTrack) {
    if(&aTrack != this) {
        //delete
        // delete playlists;
        //..
        //set
        id = aTrack.id;
        number = aTrack.number;
        recordingOf = aTrack.recordingOf;
        recordTrackIsIn = aTrack.recordTrackIsIn;
        for(auto p: aTrack.playlistsTrackIsIn) {playlistsTrackIsIn.insert(p);}
    }
    return *this;
}

Track::~Track() {

}

int Track::getId(){return id;}
int Track::getNumber(){return number;}
Song * Track::getSongPointer() { return recordingOf;}
void Track::clearSongPointer() { recordingOf = NULL; }
Record * Track::getRecordPointer() {return recordTrackIsIn;}
void Track::clearRecordPointer() { recordTrackIsIn = NULL; }
P_map Track::getPlaylistsTrackIsIn() {return playlistsTrackIsIn;}
void Track::addPlaylistPointer(string name, Playlist * p) {  playlistsTrackIsIn[name] = p;}
void Track::removePlaylistPointer(string name) { 
    P_map::const_iterator p = playlistsTrackIsIn.find(name); //.find(name);
    if(p != playlistsTrackIsIn.end()) { 
        playlistsTrackIsIn.erase(p);
    }
}


void Track::printOn(ostream & out) const {out << left << setw(20) << id << setw(15) << number;}
ostream & operator<<(ostream & o, const Track & s) { s.printOn(o);  return o;}
