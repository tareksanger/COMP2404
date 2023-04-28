// Operation.cpp

#include "include/Operation.h"
#include "include/Flags.h"

map<string, vector<string>> Operation::getToDo() { return toDo; }


/* 
determineFlag
Argument: string cmd - the parsed part of the command that is a flag
Descriptions: Returns the enum value of the command to be used in the Switch statement.
*/
Flag::TYPE Operation::determineFlag(string cmd) {return type[cmd];}


/* 
createToDo
Argument: vector<string> data - the parsed command string
Description: Takes the parsed command string and looks for the flags and creates a map of the flags as the key and the flags corresponding variables in a vector of strings
*/
void Operation::createToDo(vector<string> data) { /// FIX --- IF THERE ARE NO FLAGS THAT MATCH OR the first isn't a FLAG
    string currentFlag = "";
    for(string d: data){
        if(type.find(d) != type.end()) { // Flag is found
            currentFlag = d;             // sets the current Flag to the flag that was found
            toDo.insert({currentFlag, vector<string> {}});  
        }else if(currentFlag != "") { // flag has been found and then this must be the variable followed by the flag... 
            toDo[currentFlag].push_back(d);
        }
    }
}
