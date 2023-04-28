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

// Playlist.h

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <map>

#include "Track.h"

using namespace std;

class Track;

typedef Track T;

class Playlist {
    public: 
        Playlist(string name);
        Playlist(const Playlist & aPlaylist);
        Playlist & operator=(const Playlist & aPlaylist);
        ~Playlist();
        void printOn(ostream & out) const;
        int getUserId();
        string getName();

        map<int, T*> getTracks();
        void addTrack(int t_id, Track & t);
        void removeTrack(int t_id);
        
    private:
        string name;
        map<int, T*> tracks;
        

};

ostream & operator<<(ostream & o, const Playlist & s);

#endif