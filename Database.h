#ifndef DATABASE
#define DATABASE

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <exception>
#include <map>

#include <"DatalogProgram.h">
#include <"Database.h">

using namespace std;

class Database : public map<string, Relation> {

}


#endif
