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

// Operation.h

#ifndef OPE_H
#define OPE_H

#include <string>
#include <map>
#include <vector>
#include "Flags.h"

using namespace std;



class Operation {
    public: 
        // Operation();
        map<string, vector<string>> getToDo();
        Flag::TYPE determineFlag(string cmd);
        void createToDo(vector<string> data);

    protected:
        map<string, Flag::TYPE> type;
        map<string, vector<string>> toDo;
        
};


#endif