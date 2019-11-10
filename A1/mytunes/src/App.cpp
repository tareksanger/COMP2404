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

//App.cpp

#include <iostream>
#include <string>

#include "include/App.h"
#include "include/UI.h"

App::App() : view(*this) { //initialization of UI view
	cmd = {
        {"add", CMD::ADD},
            {"delete", CMD::DELETE},
            {"show", CMD::SHOW},
            {".quit", CMD::QUIT},
            {".read", CMD::READ},
            {".log", CMD::LOG},
            {".help", CMD::HELP},
            {".trim", CMD::TRIM},
            {".startsWith", CMD::STARTS_WITH},
            {".endsWith", CMD::ENDS_WITH},
            {".toTitleCase", CMD::TO_TITLE_CASE}
            };
}

void App::setState(char c) { STATE = c;}

void App::run(){
	setState(TAKING_INPUT);
	view.run();
}

char App::state() {return STATE;}
bool App::isReading(){ return STATE == READING;}
bool App::isRunning(){ return STATE != QUIT_APP;}
void App::finishReading() { STATE = TAKING_INPUT;}

void App::executeCommand(vector<string> data, string originalcmd){
	if(!data.empty()) {
		string command = data[0]; 
		data.erase(data.begin()); // Remove the command element.
		container.logCmd(originalcmd);
		output("Executing: " + originalcmd);
		//Run the proper command.
		switch (cmd[command]) {
			case 					CMD::ADD:			
				add(data);
				break;

			case 					CMD::DELETE: 		
				delete_(data);
				break;
				
			case 					CMD::SHOW:	
				show(data);
				break;
				
			case 					CMD::QUIT:			// Dot Cmd
				quit();
				break;
				
			case 					CMD::READ:			// Dot Cmd
				read(data);
				break;
				
			case 					CMD::LOG:			// Dot Cmd
				log(data);			
				break;	
				
			case 					CMD::HELP:			// Dot Cmd
				help();			
				break;
				
			case 					CMD::TRIM:			// (for testing)
				trim(data);
				break;
				
			case 					CMD::STARTS_WITH:	// (for testing)
				startsWith(data);
				break;
				
			case 					CMD::ENDS_WITH:		// (for testing)
				endsWith(data);
				break;
				
			case 					CMD::TO_TITLE_CASE:	//(for testing)
				toTitleCase(data);
				break;
				
			default:				// DEFAULT
				output("\nCommand Not Recognized.\n");
				break;
			}
	}
}

/*--------------------------------------------------------------------------------
 		quit()
		Tells the view to prompt the goodbye message, and sets the app state to quit. 

 --------------------------------------------------------------------------------*/
void App::quit() {
	if(STATE != READING) {
		view.goodBye();
		setState(QUIT_APP);
	}
}

/*--------------------------------------------------------------------------------
 		help()
		Tells the view to prompt the help. 

 --------------------------------------------------------------------------------*/
void App::help() {
	if(STATE != READING) {
		view.help();
	}
}

/*--------------------------------------------------------------------------------
 		Add
		Arguments: vector<string> - the data required to preform the command. 
		Description: performs the add commands based on the flags if the flags correspond correctly with the add command.
 --------------------------------------------------------------------------------*/
void App::add(vector<string> data) {
	output("Adding");
	Add_Delete_op add;
	add.createToDo(data);
	for(auto const & pair: add.getToDo()) {
		switch (add.determineFlag(pair.first)){
			case Flag::r: 			// records
					view.output("TESTING");
					for(string v: pair.second) { output("Record: " + v); }
				break;
			
			case Flag::s:			// -s songs
					for(string v: pair.second) { output("Song: " + v); }
				break;
			
			case Flag::t:			// -t tracks
					for(string v: pair.second) { output("Track: " + v); }
				break;
			
			case Flag::u:			// -u user
					for(string v: pair.second) { output("User: " + v); }
				break;    
			
			case Flag::p:			// -p playlist
					for(string v: pair.second) { output("Playlist: " + v); }
				break;
			
			case Flag::l:			// -l playlist track
					for(string v: pair.second) { output("playlst track: " + v); }
				break;
			
			default:
				error("Command Flag was not recognized or no flags were entered. Please use .help for imformation on the accepted commands and their flags.");
				break;
		}
	}
}
/*--------------------------------------------------------------------------------
 		delete_
		Arguments: vector<string> - the data required to preform the command.
		Description: performs the delete commands based on the flags if the flags correspond correctly with the delete command 
 --------------------------------------------------------------------------------*/
void App::delete_(vector<string> data) {
	output("Deleting");
	Add_Delete_op delete_;
	delete_.createToDo(data);
	for(auto const & pair: delete_.getToDo()) {
		switch (delete_.determineFlag(pair.first)){
			case Flag::r: 			// records
					for(string v: pair.second) { output("Record: " + v);}
				break;
			
			case Flag::s:			// songs
					for(string v: pair.second) { output("Song: " + v);}
				break;
			
			case Flag::t:			// tracks
					for(string v: pair.second) { output("Track: " + v);}
				break;
			
			case Flag::u:			// user
					for(string v: pair.second) { output("User: " + v);}
				break;    
			
			case Flag::p:			// playlist
					for(string v: pair.second) { output("Playlist: " + v);}
				break;

			case Flag::Global:
					for(string v: pair.second) { output("Global: " + v);}
				break;
			
			default:
				error("Command Flag was not recognized or no flags were entered. Please use .help for imformation on the accepted commands and their flags.");
				break;
		}
	}
}
/*--------------------------------------------------------------------------------
 		SHOW
		Arguments: vector<string> - the data required to preform the command. 
		Description: performs the show commands based on the flags if the flags correspond correctly with the show command 
 --------------------------------------------------------------------------------*/
void App::show(vector<string> data) {
	output("Showing");
	Show_op showOp;
	showOp.createToDo(data);
	for(auto const & pair: showOp.getToDo()) {
		switch (showOp.determineFlag(pair.first))
		{
		case Flag::SONGS:
			view.output("Songs");
			for(string v: pair.second) { output("SONGS: " + v); }
			break;

		case Flag::USERS:
			view.output("Users");
			for(string v: pair.second) { output("USER: " + v); }
			break;

		case Flag::PLAYLISTS:
			view.output("Playlists");
			for(string v: pair.second) { output("Playlist: " + v); }
			break;

		case Flag::RECORDINGS:
			view.output("Recording");
			for(string v: pair.second) { output("Recording: " + v); }
			break;
		case Flag::TRACKS:
			view.output("Tracks");
			for(string v: pair.second) { output("TRACKS: " + v); }
			break;
		default:
			error("Command Flag was not recognized or no flags were entered. Please use .help for imformation on the accepted commands and their flags.");
			break;
		}
	}

}

/*--------------------------------------------------------------------------------
 		read
		Arguments: vector<string> - the data required to preform the command. 
		Description: preforms the read command to be preformed on the given file.
 --------------------------------------------------------------------------------*/
void App::read(vector<string> data) {
	if(STATE != READING) {
		if(!data.empty()){
			setState(READING);
			view.read(data[0]);
		} else {
			error(".read requires 1 arguments. Type .help from more information.");
		}
	}
}


/*--------------------------------------------------------------------------------
 		log
		Arguments: vector<string> - the data required to preform the command. 
		Description: performs the log commands based on the flags if the flags correspond correctly with the log command 
 --------------------------------------------------------------------------------*/
void App::log(vector<string> data) {
	Log_op logOp;
	logOp.createToDo(data);
	for(auto const & pair: logOp.getToDo()) {
		switch(logOp.determineFlag(pair.first)){
			case Flag::CLEAR: // add clearing the file... ???
				output("Clearing log.");
				container.clear();
				break;
			
			case Flag::START:
				output("Starting to log input commands.");
				container.startLoggingCommands();
				break;
			
			case Flag::START_OUTPUT:
				output("Starting to log MyTunes output.");
				container.startLoggingOutput();
				break;			
			
			case Flag::START_BOTH:
				output("Starting to log input commands and MyTunes output.");
				container.startLoggingBoth();
				break;
			
			case Flag::STOP:
				output("Logging has stoped.");
				container.stop();
				break;
			
			case Flag::SAVE:
				output("Saving the commands to " + pair.second[0]);
				container.save(pair.second[0]);
				break;
			
			case Flag::SHOW:
				output("Showing the current log.");
				view.showLog(container.getLog());
				break;
			default:
				error("Command Flag was not recognized or no flags were entered. Please use .help for imformation on the accepted commands and their flags.");
				break;
		}
	}
}

/*--------------------------------------------------------------------------------
 		output
		Arguments: string msg - the message to be output by the UI and logged by the container
 --------------------------------------------------------------------------------*/
void App::output(string msg) {
	container.logOutput(msg);
	view.output(msg);
}
/*--------------------------------------------------------------------------------
 		error
		Arguments: string msg - the error message to be output by the UI and logged by the container
 --------------------------------------------------------------------------------*/
void App::error(string msg) {
	container.logOutput(msg);
	view.error(msg);
}

// TEST FUNCTIONS

/*--------------------------------------

.trim(vector<string> data)

---------------------------------------*/
void App::trim(vector<string> data) {
	if(data.size() < 1) {
		error(".trim requires at least 1 argument.\n\tExample:\t .trim \"a   day ago\"");
	} else {
		for(string s: data) {
			output(view.trim(s));
		}
	}

}
/*--------------------------------------

.startsWith(vector<string> data)

---------------------------------------*/
void App::startsWith(vector<string> data) {
	if(data.size() < 2) {
		error(".startsWith ... to few arg");
	} else if (data.size() > 2) {
		error(".startsWith ... to many arg");
	} else {
		output((view.startsWith(data[0], data[1]) ? "True" : "False"));
	}
}
/*--------------------------------------

.endsWith(vector<string> data)

---------------------------------------*/
void App::endsWith(vector<string> data) {
	if(data.size() < 2) {
		error(".endsWith ... to few arg");
	} else if (data.size() > 2) {
		error(".endsWith ... to many arg");
	} else {
		output((view.endsWith(data[0], data[1]) ? "True" : "False"));
	}
}

/*--------------------------------------
toTitleCase

---------------------------------------*/
void App::toTitleCase(vector<string> data) {
	if(data.size() < 1) {
		error(".toTitleCase requires at least 1 argument.\n\tExample:\t .toTitleCase \"the beatles\"");
	} else {
		for(string s: data) { 
			output(view.toTitleCase(s));
		}
	}
	
}