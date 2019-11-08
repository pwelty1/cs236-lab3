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

#include <"DatalogProgram.h">
#include <"Database.h">

using namespace std;

class Interpreter {
private:
  DatalogProgram oldData;

public:
   Interpreter(DatalogProgram data);
};

Interpreter::Interpreter(DatalogProgram data) {
  oldData = data;

}

#endif
