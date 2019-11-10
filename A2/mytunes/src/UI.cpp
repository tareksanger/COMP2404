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

// UI.cpp
#include <iomanip>
#include <sstream>

#include "include/UI.h"
#include "include/App.h"



UI::UI(App & anOwner) : owner(anOwner){
  //default construction
}

void UI::run(){
    // Presents the Welcome message.
    welcome();

    vector<string> data;
	string command = "";
	
    while(owner.isRunning()) {
        cout<< "♫ : ";

        getline(cin, command); 
        // int numberOfFlags = 0;
        // vector<string> data = parse(command, numberOfFlags);
        // vector<string> data = parse(command);
        // cout << endl;
		owner.executeCommand(parse(command), command); //owner is object now
	}
}

void UI::read(string filename){ 
    ifstream inputFile(filename, ifstream::in);
    if(!inputFile) {
        owner.error("ERROR: could not open file " + filename + ". Please make sure the file you are trying to read is in the correct directory.");
        return;
    }
    string commandReadFromFile;
    while(getline(inputFile, commandReadFromFile)) {
        cout << "♫ : " << commandReadFromFile << endl;
        owner.executeCommand(parse(commandReadFromFile), commandReadFromFile);
    }
    owner.setState(TAKING_INPUT);
}

// vector<string> UI::parse(string cmd, int &num) { 
vector<string> UI::parse(string cmd) { 

    vector<string> data;
    string searchString = " \"/";
    size_t found = cmd.find_first_of(searchString);
    bool commentFound = false;
    while(found != string::npos) {
        if(cmd[found] == '/' && cmd[found + 1] == '/'){
            commentFound = true;
            output("Comment found");
            break;

        }else  if(cmd[found] == '\"' && searchString == " \"/") {
            
            searchString = "\"";
        } else {
            
            string substring = cmd.substr(0,found);
            if(substring != "") { 
                // num += countFlag(substring);
                data.push_back(substring); 
                }
            searchString = " \"/";
        }
        
        cmd = cmd.erase(0,found + 1);
        found = cmd.find_first_of(searchString);
    }    
    
    if(!commentFound) {
        string substring = cmd.substr(0, cmd.length());
        if(substring != "") {
            // num += countFlag(substring);
            data.push_back(substring);
        }
    }

    return data;
}

// int UI::countFlag(string f) {
//     return (Flag::type.find(f) == Flag::type.end())? 0 : 1;
    
// }


void UI::output(string message){
		//output a messsage to user on the UI screen
		cout << message << endl;
}
void UI::output(int message){
		//output a messsage to user on the UI screen
		cout << message << endl;
}

void UI::welcome() { 
    cout << "\n\n♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪\n";
    cout << "\n";
    cout << "♪\t\tWelcome to MyTunes\t\t♪";
    cout << "\n";
    cout << "\n♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪ ♪\n\n\n";
    cout << "\t\tCOMMANDS\n";
    cout << "\n\t.help\t\t| Shows shell commands and how to use them\n";
    cout << "\t.quit\t\t| quit the application\n\n\n" << endl; 
}
void UI::goodBye() {
    output("\n♫\tGood Bye!\t♫\n");
}

void UI::error(string message) {
    output("Error: " + message);
}

void UI::help(){
    ifstream helpFile("ref/help.txt", ifstream::in);
    string str;
    if(!helpFile){ 
        owner.error("help.txt file is missing.");
    } else {
        while(getline(helpFile, str)) {
            output(str);
        }
    }
}

void UI::showLog(vector<string> logs){
    for(string str: logs){ 
        output(str);
    }
}
string UI::toTitleCase(string message){
    return StrUtils::toTitleCase(message);
}
string UI::trim(string message) {
    return StrUtils::trim(message);
}
bool UI::startsWith(string message, string prefix) {
    return StrUtils::startsWith(message, prefix);
}
bool UI::endsWith(string message, string suffix) {
    return StrUtils::endsWith(message, suffix);
}

// Show Data
