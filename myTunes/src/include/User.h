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

// User.h

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <map>

#include "Playlist.h" 

using namespace std;

typedef Playlist P;
typedef map<string, Playlist*>  Playlists;



class User {
    public: 
        User(string u_id, string name="Unknown");
        User(const User & aUser);
        ~User();
        User & operator=(const User & aUser);
        void printOn(ostream & out) const;

        string getUserId();
        string getName();
        
        // getPlaylists;
        Playlists getPlaylists();
        Playlist* getPlaylist(string name);
        int addPlaylist(string name);
        void deletePlaylist(string name);
    
    private: 
        string id;
        string name;
        Playlists playlists;

};

ostream & operator<<(ostream & o, const User & u);

#endif