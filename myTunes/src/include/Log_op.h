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

// Log_op.h

#ifndef LOG_OP_H
#define LOG_OP_H

#include <string>
#include <map>
#include <vector>

#include "Operation.h"

using namespace std;

class Log_op: public Operation {
    public:
        Log_op(); 
};

#endif