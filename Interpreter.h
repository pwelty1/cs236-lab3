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
  Database db;

public:
   Interpreter(DatalogProgram data);
   void evalQuery(Predicate qury);
   void evaluateQueries();
};

Interpreter::Interpreter(DatalogProgram data) {
  oldData = data;
  rulez = data.getRules();
  schemez = data.getSchemes();
  factz = data.getFacts();
  queriez = data.getQueries();
  Relation rel;
  //Setting up all relations
  for (unsigned int i = 0; i < schemez.size(); ++i){
     rel.addRelation((schemez.at(i)).getId(), (schemez.at(i)).getParams());

     db.insert(pair<string,Relation>(rel.getName(), rel));
     rel.clearAttributes();
  }
  //filling relations
  for (unsigned int i= 0; i <factz.size(); ++i) {
    (db.find((factz.at(i)).getId())->second).insert((factz.at(i)).getParams());
  }


  //Printing out our database
  // map<string, Relation>::iterator it;
  //
  // for ( it = db.begin(); it != db.end(); it++ )
  // {
  //     cout << it->first << ':' << endl;
  //     (it->second).toString();
  //     cout << endl;
  // }
}

void Interpreter::evalQuery(Predicate qury) {
  map<string, int> variables1;
  vector<int> sameVars;
  map<string, vector<int>> variables;
  map<string,vector<int>> consts;
  vector<string> parameterz = qury.getParams();
  Relation newRel = db.find(qury.getId())->second;
  set<Tuple> tuplez = newRel.getTuples();
  Scheme tempAtts  = newRel.getAttbs();


  for (unsigned int i = 0; i < parameterz.size(); ++i){
    if (((parameterz.at(i)).front() == '\'') && ((parameterz.at(i)).back() == '\'')) {
      //cout << parameterz.at(i) << endl;
      newRel.selectConst(parameterz.at(i), i);
      if (consts.find(parameterz.at(i)) != consts.end()) {
        consts[parameterz.at(i)].push_back(i);
      }
      else {
        consts.insert(pair<string, vector<int>>(parameterz.at(i), sameVars));
        consts[parameterz.at(i)].push_back(i);
      }
      //newRel.toString();
      //cout << endl;
    }
    else {
        variables1.insert(pair<string, int>(parameterz.at(i),i));
        //cout << "done 5";
        if (variables.find(parameterz.at(i)) != variables.end()) {
          variables[parameterz.at(i)].push_back(i);
        }
        else {
          variables.insert(pair<string, vector<int> >(parameterz.at(i),sameVars));
          variables[parameterz.at(i)].push_back(i);
        }
      }
  }

  map<string, vector<int>>::iterator it1;
  for (it1 = variables.begin(); it1 != variables.end(); it1++ ){
      if ((it1->second).size() > 1) {
        for (unsigned int i  = 0; i < (it1->second).size(); ++i) {
          //cout << (it1->second).at(i) << endl;
          sameVars.push_back((it1->second).at(i));
        }
        newRel.selectVar(sameVars);
        sameVars.clear();
      }
  }

  newRel.project(variables1);
  newRel.rename(variables1);
  qury.toString();
  cout << "? ";
  if ((newRel.getTuples()).size() > 0){
    cout << "Yes(" << (newRel.getTuples()).size() << ")" << endl;
    if (variables1.size()> 0){
      newRel.toString();
    }
  }
  else{
    cout << "No" << endl;
  }
  //newRel.toString();
  //cout << endl;

  // map<string, vector<int>>::iterator it;
  //
  // for ( it = variables.begin(); it != variables.end(); it++ ){
  // cout << it->first << ':' << endl;
  // for (unsigned int i = 0; i < (it->second).size(); ++i){
  //     cout << (it->second).at(i) << endl;
  //   }
  // }
}

void Interpreter::evaluateQueries() {
  //queriez.at(0).toString();
  for (unsigned int i = 0; i < queriez.size(); ++i) {
    evalQuery(queriez.at(i));
  }

}

#endif
