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
		// if(!data.empty() || command.compare(".help") == 0) {
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
		// } else {
		// 	error("Command not recognized or the Command was entered incorrectly. Use .help if you need assistance.");
		// }
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
	// output("Adding");
	Add_Delete_op add;
	add.createToDo(data);
	for(auto const & pair: add.getToDo()) {
		int result = 0;
		switch (add.determineFlag(pair.first)){
			case Flag::s:	
				
				result = dataManager.addSong(pair.second);	// -s songs
				if(result == -1) {
					error("Song was not added due to input error.");
				} else if( result == -2) {
					error("Song id error.");
				}
				break;

			case Flag::t:			// -t tracks
					result = dataManager.addTrack(pair.second);
					if(result == -1) {
						error("Track was not added due to input error.");
					} else if (result == -2 ) {
						error("Song id entered does not exist.");
					} else if( result == -3) {
						error("Record id entered does not exist.");
					} else if(result == -4) { 
						error("Track already exisit with this id.");
					}
				break;
			case Flag::r: 			// records
				
					result = dataManager.addRecord(pair.second);
					if(result == -1) {
						error("Record was not added due to input error.");
					} else if (result == -2 ) { 
						error("Record with same ID was found please delete the old record before adding a new one.");
					}
				break;
			case Flag::u:			// -u user
				result = dataManager.addUser(pair.second);
				if(result == -1) {
					error("User was not added due to input error.");
				} else if (result == -2 ) { 
					error("User with same ID was found please delete the old user before adding a new one.");
				}
				break;    
			
			case Flag::p:			// -p playlist
			// for(string v: pair.second) { output("Song: " + v);}
				result = dataManager.addPlaylist(pair.second);
				if (result == -1) { // input error
					error("Playlist was not added to to input error.");
				} else if (result == -2) { //user doesnt exist
					error("User name entered was not found");
				} else if(result == -3) { // playlist already exists..
					error("Playlist with that name already exists under this user.");
				}
				break;
			
			case Flag::l:			// -l playlist track
				result = dataManager.addTrackToUserPlaylist(pair.second);
				if(result == -1) {
					error("Track was not added to user playlist due to input error."); 
				} else if(result == -2) { 
					error("Track was not added user, " + pair.second[0] + " doe s not exist.");
				} else if(result == -3) { 
					error("Track was not added user, " + pair.second[0] + " has not playlist named " + pair.second[1] + ".");
				} else if(result == -4) { 
					error("Track was not added. There is no track with id, " + data[2]);
				}
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
	// output("Deleting");
	Add_Delete_op delete_;
	delete_.createToDo(data);
	Todo todo = delete_.getToDo();
	do {
		Todo::iterator it = todo.begin();
		switch (delete_.determineFlag(it->first)){
			case Flag::r: 			// records
				dataManager.handleDeleteRecord(todo);
				break;
			case Flag::s:			// songs
				dataManager.handle_S_FlagDelete(todo);
				break;
			case Flag::t:			// tracks
					dataManager.handleTrackDelete(todo);
				break;
			
			case Flag::u:			// user
				dataManager.handleDeleteUser(todo);

				break;    
			
			case Flag::p:			// playlist
					for(string v: it->second) { output("Playlist: " + v);}
					todo.erase(it->first);
				break;

			case Flag::Global:
					for(string v: it->second) { output("Global: " + v);}
					todo.erase(it->first);
				break;
			
			default:
				error("Command Flag was not recognized or no flags were entered. Please use .help for imformation on the accepted commands and their flags.");
				break;
		}

	} while(!todo.empty());
	// for(auto const & pair: delete_.getToDo()) {
	// 	switch (delete_.determineFlag(pair.first)){
	// 		case Flag::r: 			// records
	// 				for(string v: pair.second) { output("Record: " + v);}
	// 			break;
			
	// 		case Flag::s:			// songs
	// 			dataManager.deleteSong()
	// 				// for(string v: pair.second) { output("Song: " + v);}
	// 			break;
			
	// 		case Flag::t:			// tracks
	// 				for(string v: pair.second) { output("Track: " + v);}
	// 			break;
			
	// 		case Flag::u:			// user
	// 				for(string v: pair.second) { output("User: " + v);}
	// 			break;    
			
	// 		case Flag::p:			// playlist
	// 				for(string v: pair.second) { output("Playlist: " + v);}
	// 			break;

	// 		case Flag::Global:
	// 				for(string v: pair.second) { output("Global: " + v);}
	// 			break;
			
	// 		default:
	// 			error("Command Flag was not recognized or no flags were entered. Please use .help for imformation on the accepted commands and their flags.");
	// 			break;
	// 	}
	// }
}
/*--------------------------------------------------------------------------------
 		SHOW
		Arguments: vector<string> - the data required to preform the command. 
		Description: performs the show commands based on the flags if the flags correspond correctly with the show command 
 --------------------------------------------------------------------------------*/
void App::show(vector<string> data) {
	// output("Showing");
	Show_op showOp;
	showOp.createToDo(data);
	for(auto const & pair: showOp.getToDo()) {
		switch (showOp.determineFlag(pair.first))
		{
		case Flag::SONGS:
			showSongs(dataManager.getSongs());
			break;

		case Flag::USERS:
			showUsers(dataManager.getUsers());
			break;

		case Flag::PLAYLISTS:
			output(pair.second[1]);
			if(pair.second.size() >= 2) {
				showUserPlaylists(pair.second[1]);
			} else {
				error("something");
			}
			break;

		case Flag::RECORDINGS:
			showRecords(dataManager.getRecordings());
			break;
		case Flag::TRACKS:
			showTracks(dataManager.getTracks());
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


void App::showSongs(Songs songs) {
	if(songs.empty()){output("There are no Songs to show.");}
	else {
		stringstream ss;
		output(string(80, '_'));
		output(" ");
		ss << left << setw(10) << "ID" << setw(40) << "Title" << setw(40) << "Composer";
		output(ss.str());
		output(string(80,'_'));
		output(" ");
		for(auto song:songs) {
			stringstream string;
			string << *song.second;
			output(string.str());
		}
	}
}

void App::showUsers(Users users){ 
	if(users.empty()) {output("There are no Users to show");}
	else {
		stringstream ss;
		output(string(50, '_'));
		output(" ");
		ss << left << setw(20)<< "ID" << setw(30) << "NAME";
		output(ss.str());
		output(string(50, '_'));
		output(" ");
		for(auto user: users) { 
			stringstream sst;
			sst << *user.second;
			output(sst.str());
		}
	}
}



void App::showTracks(Tracks tracks){ 
	if(tracks.empty()) {output("There are no Tracks to show");}
	else {
		stringstream ss;
		output(string(35, '_'));
		output(" ");
		ss << left << setw(20)<< "ID" << setw(15) << "NUMBER";
		output(ss.str());
		output(string(35, '_'));
		output(" ");
		for(auto track:tracks) {
			stringstream sst;
			sst << *track;
			output(sst.str());
		}
	}
}

void App::showRecords(Records records){ 
	if(records.empty()) {output("There are no Records to show");}
	else {
		stringstream ss;
		output(string(116, '_'));
		output(" ");
		ss << left << setw(10)<< "ID" << setw(40) << "TITLE" << setw(30) << "ARTIST" << setw(30) << "PRODUCER" << setw(6) << "YEAR";
		output(ss.str());
		output(string(116, '_'));
		output(" ");
		for(auto record: records) {
			stringstream sst;
			sst << *record.second;
			output(sst.str());
		}

	}
}

void App::showUserPlaylists(string u_id){ 
	// Users::iterator it = dataManager.getUsers().find(u_id);
	// if(it == dataManager.getUsers().end()) {output("There is no user with id, "+ u_id +" to show playlists.");}
	// else {
	// 	if (it->second->getPlaylists().empty()) {output(u_id + " has no playlists to show.");}
	// 	else {
	// 		stringstream ss;
	// 		output(u_id + " list of Playlists");
	// 		output(string(20, '_'));
	// 		output(" ");
	// 		ss << left << setw(20)<< "NAME";
	// 		output(ss.str());
	// 		output(string(20, '_'));
	// 		output(" ");
	// 		for(auto p: it->second->getPlaylists()) {
	// 			stringstream sst;
	// 			sst << *p.second;
	// 			output(sst.str());
	// 		}
	// 	}
	// }
}

void App::showUserPlaylistSongs(string u_id, string p_name) {
	// Users::iterator it = dataManager.getUsers().find(u_id);
	// if(it == dataManager.getUsers().end()) {output("There is no user with id, "+ u_id +" to show playlist songs.");}
	// else { 
	// 	Playlists p_it = (it->second->getPlaylists()).find(p_name);
	// 	if(p_it == it->second->getPlaylists().end()) {output(u_id + " has no playlist " + p_name + ".");}
	// 	else {

	// 	}
	// }
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