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

// CMD_Log.cpp


#include "include/CMD_Log.h"

Command_Log::Command_Log() { STATE = Command_Log::OFF;}

void Command_Log::startLoggingCommands() { STATE = state::CMD_ONLY;}
void Command_Log::startLoggingOutput() { STATE = state::OUT_ONLY;}
void Command_Log::startLoggingBoth() {STATE = state::BOTH;}
void Command_Log::stop() {STATE = state::OFF;}
void Command_Log::stopLoggingCommands() {
    switch (STATE) {
        case state::BOTH:
            STATE = OUT_ONLY;
            break;
        case state::CMD_ONLY:
            STATE = OFF;
            break;
        default: // State is OUT_ONLY or OFF
                /*  Do Nothing  */
            break;
    }
}
void Command_Log::stopLoggingOutput() {
    switch (STATE) {
        case state::BOTH:
            STATE = CMD_ONLY;
            break;
        case state::OUT_ONLY:
            STATE = OFF;
            break;
        default: // State is CMD_ONLY or OFF
                /*  Do Nothing  */
            break;
    }
}

/*
isLoggingCommands
Description: Returns true if the Command_Log is currently logging the input commands. Returns false if it is not.
*/
bool Command_Log::isLoggingCommands(){ return STATE == state::CMD_ONLY || STATE == state::BOTH;}
/*
isLoggingOutput
Description: Returns true if the Command_Log is currently logging the Apps output. Returns false if it is not.
*/
bool Command_Log::isLoggingOutput(){ return STATE == state::OUT_ONLY || STATE == state::BOTH;}

/* 
logCmd 
Arguments: string msg - the message to be logged.
Description: Logs commands and determines weather they should be logged or not depending on the current state of the command Log.

*/
void Command_Log::logCmd(string msg) { 
    if(STATE ==  state::BOTH || STATE == state::CMD_ONLY) {
        log_.push_back(msg);
    }
}

/* 
logOutout 
Arguments: string msg - the message to be logged.
Description: Logs the output and determines weather they should be logged or not depending on the current state of the command Log.
*/
void Command_Log::logOutput(string msg) { 
    if(STATE ==  state::BOTH || STATE == state::OUT_ONLY) {
        log_.push_back(msg);
    }
}

/* 
getLog
Description: Returns the vector<string> that contains the data that has been logged.
*/
vector<string> Command_Log::getLog(){return log_;}


/* 
clear
Description: clears/empties the vector<string>
*/
void Command_Log::clear() {
    log_.clear();
}

/*
save
Arguments: filename - the name of the file that the commands will be written and saved to.
*/
void Command_Log::save(string filename) {
    ofstream outputFile(filename, ofstream::out);
    for(string s: log_) {
        outputFile << s << endl;
    }
}