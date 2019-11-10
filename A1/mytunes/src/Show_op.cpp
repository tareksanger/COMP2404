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

// Show_op.cpp

#include "include/Show_op.h"

Show_op::Show_op() {
    type = {
        {"songs", Flag::SONGS},
        {"users", Flag::USERS},
        {"playlists", Flag::PLAYLISTS},
        {"recordings", Flag::RECORDINGS},
        {"tracks", Flag::TRACKS}
    };
}
// Show_Op::TYPE Show_Op::determineOperation(string cmd) {return type[cmd];}

// void Show_Op::createToDo(vector<string> data) {
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
