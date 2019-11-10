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

// Add_Delete_Op.h

#ifndef ADD_DELETE_OP_H
#define ADD_DELETE_OP_H

#include <string>
#include <map>
#include <vector>

#include "Flags.h"
#include "Operation.h"

using namespace std;

class Add_Delete_op: public Operation {
    public:
        Add_Delete_op(); 
};

#endif