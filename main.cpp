#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <locale>

#include "Token.h"
#include "Scanner.h"
#include "Parser.h"


using namespace std;

int main (int argc, char* argv[]){
  string fileName = argv[1];


  Scanner read_n_poo(fileName);
  //cout << "----------------------checking new Tokens----------------------" << endl;
  Parser data(read_n_poo.getTokens());
  data.parse();

  // cout<< "Total Tokens = " << read_n_poo.getNumTkns()<< endl;

  // BEGIN PARSING (checking grammar)


  return 0;
}
