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

// Show_op.h

#ifndef SHOW_OP_H
#define SHOW_OP_H

#include <string>
#include <map>
#include <vector>

#include "Operation.h"

using namespace std;

class Show_op: public Operation {
    public:
        Show_op(); 
};

#endif