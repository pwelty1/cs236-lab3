#ifndef RELATION
#define RELATION

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <exception>

#include <"Scheme.h">
#include <"Tuple.h">

using namespace std;

class Relation {

private:
  string name;
  Scheme attributes;
  set<Tuple> tuples;

public:


};


#endif
