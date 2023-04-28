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

// App.h

#ifndef APPT_H
#define APPT_H

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>  


using namespace std;

#include "UI.h"
#include "CMD_Log.h"
#include "Flags.h"
#include "Show_op.h"
#include "Add_Delete_op.h"
#include "Log_op.h"
#include "defs.h"
#include "Data_Manager.h"

typedef map<string, User*> Users;
typedef vector<Track*> Tracks;
typedef map<int, Song*> Songs;
typedef map<int, Record*> Records;
typedef map<string, Playlist*>  Playlists;
typedef map<string, vector<string>> Todo;

class App {
	public:
	    App();
	    void executeCommand(vector<string> data, string originalCMD);
	    void run();	
		char state();
		void setState(char c);
		bool isReading();
		bool isRunning();
		void finishReading();
		void error(string msg);	
        
    private:
    	//main controller for the app
	    UI view;
		char STATE;
		enum CMD {ADD = 2, DELETE = 3, SHOW = 4, QUIT = 5, READ = 6, LOG = 7, HELP = 8, TRIM = 9, STARTS_WITH = 10, ENDS_WITH = 11, TO_TITLE_CASE = 13};
		map<string, CMD> cmd;
		Command_Log container;
		DataManager dataManager;

		void add(vector<string>);
		void delete_(vector<string>);
		void show(vector<string>);
		void quit();
		void read(vector<string>);
		void log(vector<string>);
		void help();
		void trim(vector<string>);
		void startsWith(vector<string>);
		void endsWith(vector<string>);
		void toTitleCase(vector<string>);

		void output(string msg); // this is to log commands if the commands should be logged
		void showSongs(Songs);
		void showTracks(Tracks);
		void showRecords(Records);
		void showUsers(Users);
		void showUserPlaylists(string u_id);
		void showUserPlaylistSongs(string u_id, string p_name);

		

};

#endif