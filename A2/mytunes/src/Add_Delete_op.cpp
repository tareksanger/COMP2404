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

// Add_Delete_Op.cpp

#include "include/Add_Delete_op.h"

Add_Delete_op::Add_Delete_op() {
    type = {
            {"-r", Flag::r},
            {"-s", Flag::s},
            {"-t", Flag::t},
            {"-u", Flag::u},
            {"-p", Flag::p},
            {"-l", Flag::l},
            {"-Global", Flag::Global}
            }; 
}

// Add_Delete_Op::TYPE Add_Delete_Op::determineOperation(string cmd) {return type[cmd];}

// void Add_Delete_Op::createToDo(vector<string> data) {
//     string currentFlag = "";
//     for(string d: data){
//         if(type.find(d) != type.end()) {
//             currentFlag = d;
//             toDo.insert({currentFlag, vector<string> {}});
//         }else if(currentFlag != "") {
//             toDo[currentFlag].push_back(d);
//         }
//     }
// }