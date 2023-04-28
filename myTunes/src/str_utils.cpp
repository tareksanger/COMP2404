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

//str_utls.cpp

#include <string>
#include "include/str_utils.h"

using namespace std;

string StrUtils::toUpperCase(string str){
	string s;
	for(char & c : str){
		s.append(1,toupper(c));
	}
	return s;
}


string StrUtils::toTitleCase(string str) {
    if(str.find("the ") == 0 ){
        str.erase(0, 4);
        str.append(", The");
    }
    str[0] = toupper(str[0]);

    size_t found = str.find_first_of(" .(/,-_");
    while(found != string::npos) {
        str[found + 1] = toupper(str[found + 1]);
        found = str.find_first_of(" .(/,-_", found+2);
    }    

    return(str);
};



string StrUtils::trim(string str) { 
    size_t found = str.find("  ");
    while(found != string::npos) {
        str.erase(found+1, 1);
        found = str.find("  ");
    }

    if(str.at(0) == ' ') {
        str.erase(0, 1);
    }
    if(str.at(str.size()-1) == ' ') {
        str.erase(str.size()-1, 1);
    }
    return str;
}

bool StrUtils::startsWith(string str, string prefix) {
    return (str.substr(0, prefix.size()).compare(prefix) == 0);
}

bool StrUtils::endsWith(string str, string suffix) {
    size_t sLen = suffix.size();
    return (str.substr(str.size() - sLen, sLen).compare(suffix) == 0);
}