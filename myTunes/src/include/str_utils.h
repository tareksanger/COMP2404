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

// str_utils.h




#ifndef SRT_UTIL
#define SRT_UTIL

#include <string>
#include <cstddef> 

using namespace std;

class StrUtils{
	public:
        static string toUpperCase(string str);
        static string toTitleCase(string str);
        static string trim(string str);
        static bool startsWith(string str, string prfx);
        static bool endsWith(string str, string sfx);
};

#endif