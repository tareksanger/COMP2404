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

// UI.h

#ifndef UIT_H
#define UIT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "str_utils.h" 
#include "defs.h"
#include "User.h"
#include "Track.h"
#include "Song.h"
#include "Record.h"


using namespace std;

typedef map<string, User*> Users;
typedef vector<Track*> Tracks;
typedef map<int, Song*> Songs;
// typedef vector<Song*> Songs;
typedef map<int, Record*> Records;
typedef map<string, Playlist*>  Playlists;

//UI.h
class App; //forward declaration -says App will be a class

class UI {
	public:
	    UI(App & anApp); //owner pass at construction
	    void run();
    
        void welcome(); // Prints out the welcome text (used to clean up code)
        void goodBye();
        void error(string msg);
        void output(string msg);
        void output(int msg);
        // void output(bool msg);
        void read(string filename);
        string toTitleCase(string msg);
        string trim(string msg);
        bool startsWith(string msg, string prefix);
        bool endsWith(string msg, string suffix);

        void help();
        void showLog(vector<string>);


    private:
        // ------ Variables 
        //controller for user interface
	    App & owner; //reference to owner -must be initialized at construction


        /// ------ Functions
        vector<string> parse(string cmd);
        // int countFlag(string f);
        // void handleCommands(string); //

};

#endif