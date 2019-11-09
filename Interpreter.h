#ifndef INTERPRETER
#define INTERPRETER

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <exception>
#include <map>

#include "DatalogProgram.h"
#include "Database.h"

using namespace std;

class Interpreter {
private:
  DatalogProgram oldData;
  vector<Rule> rulez;
  vector<Predicate> schemez;
  vector<Predicate> factz;
  vector<Predicate> queriez;

public:
   Interpreter(DatalogProgram data);
};

Interpreter::Interpreter(DatalogProgram data) {
  oldData = data;
  rulez = data.getRules();
  schemez = data.getSchemes();
  factz = data.getFacts();
  queriez = data.getQueries();
  Relation rel;
  Database db;
  //Setting up all relations
  for (unsigned int i = 0; i < schemez.size(); ++i){
     rel.addRelation((schemez.at(i)).getId(), (schemez.at(i)).getParams());
     //cout << (schemez.at(i)).getId() << endl;
     // for (unsigned int j = 0; j < (schemez.at(i)).getParams()).size(); ++j){
     //   cout << (schemez.at(i)).getParams()).at(j);
     // }
     //problems here?
     //cout << endl;
     db.insert(pair<string,Relation>(rel.getName(), rel));
     rel.clearAttributes();
  }
  //filling relations
  for (unsigned int i= 0; i <factz.size(); ++i) {
    (db.find((factz.at(i)).getId())->second).insert((factz.at(i)).getParams());
    //(db.find((factz.at(i)).getId())->second).toString();
  }

  map<string, Relation>::iterator it;

  for ( it = db.begin(); it != db.end(); it++ )
  {
      cout << it->first << ':' << endl;
      (it->second).toString();
      cout << endl;
  }
  // for (unsigned int i = 0; i < schemez.size(); ++i){
  //   (db.find((schemez.at(i)).getId())->second).toString();
  //   cout << endl;
  // }
}

#endif
