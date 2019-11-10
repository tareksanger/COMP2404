/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*              Assignment 1                       */
/*                                                 */
/*  Program:            myTunes                    */
/*  Author:             Tarek Sanger               */
/*  Student Number:     101059686                  */
/*  Date:               2-Oct-2019                 */
/*                                                 */
/*  Course:             COMP2404                   */
/*  Section:            B                          */
/*  Prof.               Louis Nel                  */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

// DataManager.cpp

#include "include/Data_Manager.h"

DataManager::~DataManager(){
    for(auto user: users) {
        delete user.second;
        user.second = NULL;
    }
    for(auto track: tracks) {
        delete track;
        track = NULL;
    }
    for(auto song: songs) {
        delete song.second;
        song.second = NULL;
    }
    for(auto record: recordings) {
        delete record.second;
        record.second = NULL;
    }
}

//Get Methods
Songs DataManager::getSongs() { return songs;}
Tracks DataManager::getTracks() { return tracks;}
Records DataManager::getRecordings() {return recordings;}
Users DataManager::getUsers() {return users;}


// ADD Methods
int DataManager::addSong(vector<string> data) {
    if(data.size() >= 3) {
        int s_id = stoi(data[0]);
        if (data[0] != "0" && s_id == 0) { return -2;} // song id error
        Song *song = new Song(s_id, data[1], data[2]);
        // songs.push_back(&song);
        songs[s_id] = song;
        return 1;
    }
    return -1; // input error..
}

int DataManager::addTrack(vector<string> data) {  // CHECK THAT T_ID DOES NOT EXIST BEFORE ADDING..
    if(data.size() == 4) {
        int t_id = stoi(data[0]);
        int r_id = stoi(data[1]);
        int s_id = stoi(data[2]);
        int t_num = stoi(data[3]);
        for(auto t: tracks) {if (t->getId() == t_id) { return -4;}}

        // Error might occur here if the song or record dont exist... 
        Songs::iterator song = songs.find(s_id);
        if(song == songs.end()) { return -2; } // song with d_id does not exist
        Song *s = songs[s_id];

        Records::iterator rec = recordings.find(r_id);
        if(rec == recordings.end()) {return -3;} // record does not exists
        Record *r = recordings[r_id];
        Track * track = new Track(t_id, r, s, t_num);
        r->addTrack(t_id, track);
        s->addLinkedTrackId(track);
        tracks.push_back(track);

        return 1;
    } else if(data.size() == 3) { 
        if(data[0] == "?") { 
            int s_id = stoi(data[2]);
            Songs::iterator song = songs.find(s_id);
            if(song == songs.end()) { return -2; } // song with d_id does not exist
            Song *s = songs[s_id];
            Track * track = new Track(s);
            s->addLinkedTrackId(track);
            tracks.push_back(track);
        } else { 
            int t_id = stoi(data[0]);
            for(auto t: tracks) {if (t->getId() == t_id) { return -4;}}
            int s_id = stoi(data[2]);
            Songs::iterator song = songs.find(s_id);
            if(song == songs.end()) { return -2; } // song with d_id does not exist
            Song *s = songs[s_id];
            Track * track = new Track(t_id, s);
            s->addLinkedTrackId(track);
            tracks.push_back(track);
        }
        return 1;
    }
    return -1;
}

int DataManager::addRecord(vector<string> data) { 
    if(data.size() >= 5) {
        int r_id = stoi(data[0]);
        Records::iterator i = recordings.find(r_id);
        if(i != recordings.end()) { return -2;} // record with that id already exists needs to be deleted before adding this one...
        string title = data[1];
        string artist = data[2];
        string producer = data[3];
        string year = data[4];
        Record * record = new Record(r_id, title, artist, producer, year);
        recordings[r_id] = record;
        return 1;
    }
    return -1;
}


int DataManager::addUser(vector<string> data) { 
    if(data.size() >= 2) {
        string u_id = data[0];
        Users::iterator it = users.find(u_id);
        if(it != users.end()) {return -2;}
        User *user = new User(u_id, data[1]);
        users[u_id] = user;
        return 1;
    }
    return -1;
}


int DataManager::addPlaylist(vector<string> data) { 
    if(data.size() < 2) { return -1; }
    string u_id = data[0];
    Users::iterator it = users.find(u_id);
    if(it == users.end()) {return -2;} // user was does not exist
    int result = it->second->addPlaylist(data[1]);
    if(result == -1) {return -3; } // playlist already exists
    return 1;
}


int DataManager::addTrackToUserPlaylist(vector<string> data) { 
    if(data.size() == 3) {
        Users::iterator u_it = users.find(data[0]);
        if(u_it == users.end()) { return -2; } // user does not exist..
        User *user = u_it->second;
        Playlists userPlaylists = user->getPlaylists();
        Playlists::iterator p_it = userPlaylists.find(data[1]);
        if(p_it == userPlaylists.end()){ return -3; } // user playlist with given name does not exist..
        int t_id = stoi(data[2]);
        for(auto t: tracks){ 
            if(t->getId() == t_id) {
                p_it->second->addTrack(t_id, *t);
                return 1;
            }
        }
        return -4; // track deos not exist...
    }
    return -1;
}

// DELETE Methods
void DataManager::deleteSong(int s_id) {
    Song song = *songs[s_id];
    for(Track * track: song.getLinkedTrackIds()) {
        track->clearSongPointer();
    }
    delete songs[s_id];
    songs[s_id] = NULL;
    songs.erase(s_id);
}

void DataManager::deleteTrack(int t_id) {
    for(Tracks::iterator track = tracks.begin(); track != tracks.end(); ++track ) {
        if((*track)->getId() == t_id) {
            for(unordered_map<string, Playlist *>::iterator p = (*track)->getPlaylistsTrackIsIn().begin(); p != (*track)->getPlaylistsTrackIsIn().end(); ++p) { 
                p->second->removeTrack(t_id);
            }
            (*track)->getRecordPointer()->deleteTrack(t_id);
            (*track)->getSongPointer()->deleteLinkedTrack(t_id);

            delete * track;
            track = tracks.erase(track);
            break;
        }
    }
}

void DataManager::deleteRecord(int r_id){
    delete recordings[r_id];
    recordings[r_id] = NULL;
    recordings.erase(r_id);
}
void DataManager::deleteUser(string id) { 
    delete users[id];
    users[id] = NULL;
    users.erase(id); 
}
void DataManager::deletePlaylist(string u_id, string name) {
    Users::iterator i = users.find(u_id);
    if(i != users.end()) {i->second->deletePlaylist(name); }
}
void DataManager::deleteTrackFromUserPlaylist(string u_id, string p_name, int t_id) {
    Users::iterator i = users.find(u_id);
    if (i != users.end()) {i->second->getPlaylist(p_name)->removeTrack(t_id);}
}

int DataManager::handle_S_FlagDelete(Todo &data) {
    if(data.size() == 3 ) { 
        // delete track from playlist
        return 1;
    } else if (data.size() == 1){
        int s_id = stoi(data["-s"][0]);
        deleteSong(s_id);
        data.erase("-s");
        return 1;
    }
    // else if(data)
    return -1;
}

int DataManager::handleTrackDelete(Todo &data) { 
    if(data.size() == 3) {
        // delete track from playlist

        
        return 2;
    } else if (data.size() == 1) { 
        if(!data["-t"].empty()) {
            int t_id = stoi(data["-t"][0]);
            deleteTrack(t_id);
            data.erase("-t");
            return 1;
        }
        return -1;
    }
    return -1;
}

int DataManager::handleDeleteRecord(Todo &data){
    if(!data["-r"].empty()) {
        int r_id = stoi(data["-r"][0]);
        Records::iterator it = recordings.find(r_id);
        if(it != recordings.end()) { 
            for(auto t: it->second->getTracks()) {
                t.second->clearRecordPointer();
            }
            deleteRecord(r_id);
            data.erase("-r");
        }
        return 1;
    }
    return -1;
}

int DataManager::handleDeleteUser(Todo &data) { 
    if(!data["-u"].empty()) { 
        string u_id = data["-u"][0];
        Users::iterator it = users.find(u_id);
        if( it != users.end()) {
            for(auto p:it->second->getPlaylists()) { 
                for(auto t :p.second->getTracks()) {
                    t.second->removePlaylistPointer(p.first);
                }
            }
            deleteUser(u_id);
            data.erase("-u");
        }
    }
    return 1;
}







