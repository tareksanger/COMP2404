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

// Flag.h

#ifndef FLAG_H
#define FLAG_H

#include <iostream>
#include <map>
#include <string>

using namespace std;


struct Flag {
    public:             // for Add & Delete operations  
        enum  TYPE {    r, s, t, u, p, l, Global, 
                        // for Show operations
                        SONGS, USERS, PLAYLISTS, RECORDINGS, TRACKS,CLEAR, 
                        // for Log Operations.
                        START, START_OUTPUT, START_BOTH, STOP, SAVE, SHOW
                        };
};

#endif