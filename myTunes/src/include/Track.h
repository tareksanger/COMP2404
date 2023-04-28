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

// Track.h

#ifndef TRACK_H
#define TRACK_H

#include <string>

#include "Playlist.h"
#include "Record.h"
#include "Song.h"
#include <unordered_map>

using namespace std;

class Song;
class Record;
class Playlist;

typedef unordered_map<string, Playlist *> P_map;

class Track {
    public:
        Track(int t_id, Record * aRecord, Song * aSong, int t_num);
        Track(int t_id, Song * aSong); // null r_id
        Track(Song * aSong); // null t_id and r_id
        Track(int id, int num, Song * aSong);
        Track(const Track & aTrack);
        ~Track();

        Track & operator=(const Track & aTrack);
        void printOn(ostream & out) const;

        int getId();
        int getNumber();
        
        Song * getSongPointer();
        void clearSongPointer();

        Record * getRecordPointer();
        void clearRecordPointer();

        P_map getPlaylistsTrackIsIn();
        void addPlaylistPointer(string name, Playlist * p);
        void removePlaylistPointer(string name);

    private: 
        int id;
        int number;
        Record * recordTrackIsIn;
        Song * recordingOf;
        P_map playlistsTrackIsIn;
};

ostream & operator<<(ostream & o, const Track & t);

#endif