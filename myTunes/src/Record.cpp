#include "include/Record.h"
#include "include/str_utils.h"

Record::Record(int r_id, string aTitle, string aArtist, string aProducer, string aYear) {
    id = r_id;
    title = aTitle;
    artist = aArtist;
    producer = aProducer;
    year = aYear;
}
Record::Record(const Record & aRecord): tracks(aRecord.tracks) {
    id = aRecord.id;
    title = aRecord.title;
    artist = aRecord.artist;
    producer = aRecord.producer;
    year = aRecord.year;

    for(auto t: aRecord.tracks) {tracks.insert(t);}


}
Record::~Record(){

}
Record & Record::operator=(const Record & aRecord) {
    if(&aRecord != this) {
        //delete
        // delete playlists;
        //..
        //set
        id = aRecord.id;
        title = aRecord.title;
        artist = aRecord.artist;
        producer = aRecord.producer;
        year = aRecord.year;
        for(auto t: aRecord.tracks) {tracks.insert(t);}

    }
    return *this;
}
// int Record::getId(){ return id;}
string Record::getTitle() { return StrUtils::toTitleCase(title); }
string Record::getArtist() { return StrUtils::toTitleCase(artist); }

map<int, T*> Record::getTracks() {return tracks;}
void Record::addTrack(int t_id,  T * track) { 
    tracks[t_id] = track;
}
void Record::deleteTrack(int t_id){ 
    // tracks[t_id] = NULL;
    tracks.erase(t_id);
}


void Record::printOn(ostream & out) const {out << left << setw(10) << id << setw(40) <<  StrUtils::toTitleCase(title) << setw(30) << StrUtils::toTitleCase(artist) << setw(30) << StrUtils::toTitleCase(producer) << setw(6) << year;}
ostream & operator<<(ostream & o, const Record & s) { s.printOn(o);  return o;}