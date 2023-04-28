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

// Log_op.cpp

#include "include/Log_op.h"

Log_op::Log_op() {
    type = {
        {"clear", Flag::CLEAR},
        {"start", Flag::START},
        {"start_output", Flag::START_OUTPUT},
        {"start_both", Flag::START_BOTH},
        {"stop", Flag::STOP},
        {"save", Flag::SAVE},
        {"show", Flag::SHOW}
    };
} 