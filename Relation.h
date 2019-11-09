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

#include "Scheme.h"
#include "Tuple.h"

using namespace std;

class Relation {

private:
  string name;
  Scheme attributes;
  set<Tuple> tuples;

public:
  string getName() {return name;}
  void addRelation(string nam, vector<string> attbs);
  void insert(vector<string> fcts);
  void toString();

};

void Relation::addRelation(string nam, vector<string> attbs) {
  name = nam;
  for(unsigned int i = 0; i < attbs.size(); ++i) {
    attributes.push_back(attbs.at(i));
  }
}

void Relation::insert(vector<string> fcts) {
  Tuple tple;
  //cout << fcts.size();
  for (unsigned int i = 0; i < fcts.size(); ++i) {
    tple.push_back(fcts.at(i));
  }
  tuples.insert(tple);
  tple.clear();
}

void Relation::toString() {
  set<Tuple>::iterator it = tuples.begin();

  while (it != tuples.end()){
	// Print the element
    for(unsigned int i = 0; i < attributes.size(); ++i){
      cout << attributes.at(i) << "=" << (*it).at(i);
    }
    cout << endl;
	//Increment the iterator
  	 it++;
  }
}

#endif
