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

// CMD_Log.h

#ifndef CMD_LOG_H
#define CMD_LOG_H

#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class Command_Log {
    
    private:
        enum state {CMD_ONLY,OUT_ONLY, BOTH, OFF};
        char STATE;
        vector<string> log_;

    public:
        Command_Log(); 
        // ~Command_Log();

        void startLoggingCommands();
        void startLoggingOutput();
        void startLoggingBoth();
        void stop();
        void stopLoggingCommands();
        void stopLoggingOutput();

        bool isLoggingCommands();
        bool isLoggingOutput();

        void logCmd(string msg);
        void logOutput(string msg);
        vector<string> getLog();

        void clear();
        void save(string filename);

};



#endif