#include <cctype>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <locale>
#include <map>

#include "Token.h"
#include "Scanner.h"
#include "Parser.h"
#include "Interpreter.h"


using namespace std;

int main (){
  Relation rel1;
  Relation rel2;

  vector<string> attbs{"cat", "dog", "fish"};
  vector<string> attbs1{"cat", "fish", "bird", "bunny"};
  rel1.addRelation("beta",attbs);
  rel2.addRelation("alpha", attbs1);

  rel1.insert({"1","2","5"});
  rel1.insert({"1","4","1"});
  rel1.insert({"2","3","2"});
  rel1.insert({"3","3","2"});
  rel1.insert({"6","7","4"});

  rel2.insert({"3","4","2","4"});
  rel2.insert({"6","4","9","2"});
  rel2.insert({"4","3","2","7"});
  rel2.insert({"1","5","2","4"});
  rel2.insert({"1","5","8","3"});

  Relation output1 = rel1;
  Relation output2 = rel2;
  Relation output3 = rel2;

  map<string, int> attbz;

  rel1.toString();
  cout << "***************" << endl;
  attbz.insert(pair<string, int>("feline",0));
  attbz.insert(pair<string, int>("K9",1));
  attbz.insert(pair<string, int>("chum",2));
  output1.rename(attbz);
  output1.toString();
  cout << "***************" << endl;
  attbz.clear();

  rel2.toString();
  cout << "***************" << endl;
  attbz.insert(pair<string, int>("Lion",0));
  attbz.insert(pair<string, int>("Raptor",2));
  attbz.insert(pair<string, int>("Rabbit",2));
  output2.rename(attbz, true);
  output2.toString();
  cout << "***************" << endl;

  return 0;
}
