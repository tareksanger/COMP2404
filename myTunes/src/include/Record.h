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

// Recording.h

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>


#include "Track.h"

using namespace std;

class Track;

typedef Track T;

class Record {
    public: 
        Record(int id, string title, string artist, string producer, string year);
        Record(const Record & aRecord);
        ~Record();
        Record & operator=(const Record & aRecord);
        void printOn(ostream & out) const;

        string getTitle();
        string getArtist();

        map<int, T*> getTracks();
        void addTrack(int t_id, T * track);
        void deleteTrack(int t_id);

        


    private:
        int id;
        string title;
        string artist;
        string producer;
        string year;
        map<int, T*> tracks;

};

ostream & operator<<(ostream & o, const Record & s);

#endif