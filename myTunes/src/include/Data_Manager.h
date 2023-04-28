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

// DataManager.h

#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <vector>
#include <map>
#include <string>
#include <unordered_map>

#include "User.h"
#include "Track.h"
#include "Song.h"
#include "Record.h"
#include "Flags.h"

using namespace std;

typedef map<string, User*> Users;
typedef vector<Track*> Tracks;
typedef map<int, Song*> Songs;
typedef map<int, Record*> Records;
typedef map<string, Playlist*>  Playlists;
typedef map<string, vector<string>> Todo;

class DataManager {

    private: 
        Users users;
        Tracks tracks;
        Songs songs;
        Records recordings;
        
        void deleteSong(int id); 
        void addTrackIdtoSong(int t_id, int s_id);

    public: 
        ~DataManager();

        //Get Methods
        Songs getSongs();
        Tracks getTracks();
        Records getRecordings();
        Users getUsers();
        // User & getUser(string u_id);
        
        // Add Methods
        int addSong(vector<string> data);
        // int addSong(int s_id, string title, string composer); // no longer used

        int addTrack(vector<string> data);
        // void addTrack(int t_id, int r_id, int s_id, int track_num);

        int addRecord(vector<string> data);

        // int addRecord(int id, string title, string artist, string producer, string year);

        int addUser(vector<string> data);

        // int addUser(int id, string name);

        int addPlaylist(vector<string> data);

        int addTrackToUserPlaylist(vector<string> data);
        
        
        
        // Delete Methods
        int handle_S_FlagDelete(Todo &data);
        int handleTrackDelete(Todo &data);
        int handleDeleteRecord(Todo &data);
        int handleDeleteUser(Todo &data);

        void deleteTrack(int  id);
        void deleteRecord(int r_id);
        void deleteUser(string id);
        void deletePlaylist(string u_id, string p_name);
        void deleteTrackFromUserPlaylist(string u_id, string p_name, int t_id);



        
        // Show
        

        

};


#endif