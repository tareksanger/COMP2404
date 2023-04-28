// Song.cpp

#include "include/Song.h"
#include "include/str_utils.h"

Song::Song(int s_id, string aTitle, string aComposer) {
    id = s_id;
    title = aTitle;
    composer = aComposer;
}
Song::Song(const Song & aSong){
    id = aSong.id;
    title = aSong.title;
    composer = aSong.composer;
    for(auto t: aSong.linkedTrackIds) {linkedTrackIds.push_back(t);}

}
Song::~Song(){

}
Song & Song::operator=(const Song & aSong) {
    if(&aSong != this) {
        //delete
        // delete playlists;
        //..
        //set
        id = aSong.id;
        title = aSong.title;
        composer = aSong.composer;
        for(auto t: aSong.linkedTrackIds) {linkedTrackIds.push_back(t);}

    }
    return *this;
}
void Song::printOn(ostream & out) const {
    out << left 
    << setw(10) << id 
    << setw(40) << StrUtils::toTitleCase(title) 
    << setw(40) << StrUtils::toTitleCase(composer) << endl;}

int Song::getId(){ return id;}
string Song::getTitle() { return StrUtils::toTitleCase(title); }
string Song::getComposer() { return StrUtils::toTitleCase(composer); }
vector<T*> Song::getLinkedTrackIds() {return linkedTrackIds;}
void Song::addLinkedTrackId(T * t) {linkedTrackIds.push_back(t);}
void Song::deleteLinkedTrack(int t_id) { 
    for(vector<T*>::iterator t = linkedTrackIds.begin(); t != linkedTrackIds.end() ; ++t) {
        if((*t)->getId() == t_id) {
            linkedTrackIds.erase(t);
        }
    }
}



ostream & operator<<(ostream & o, const Song & s) { s.printOn(o);  return o;}