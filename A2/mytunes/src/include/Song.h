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

// Song.h

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "Track.h"


using namespace std;

typedef Track T;

class Song {
    public:
        Song(int, string="Unknown", string="Unknown");
        Song(const Song & aSong);
        ~Song();
        Song & operator=(const Song & aSong);
        void printOn(ostream & out) const;

        int getId();
        string getTitle();
        string getComposer();

        vector<T*> getLinkedTrackIds();
        void addLinkedTrackId(T * t);
        void deleteLinkedTrack(int t_id);

    private: 
        int id;
        string title;
        string composer;
        vector<T*> linkedTrackIds;
};


ostream & operator<<(ostream & o, const Song & s);

#endif