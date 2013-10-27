#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <sstream>
#include <vector>
#include "Rule.h"
#include "Board.h"
#include "Cgol.h"

char init[10][10] = \
{{0,1,0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,0,0,1,0},
{1,1,1,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}};

char* parse(std::istream &in, int &w, int &h);

int main(int argc, char *argv[]) {
  bool pretty = false;
  int prettyt = 1000;
  int loop = 10;
  bool demo = false;
  for(int i=1; i < argc; i++) {
    if (std::string(argv[i]) == "-p") {
      pretty = true;
      try {
        prettyt = std::stoi(argv[i+1]);
      } catch (...) {}
    } else if (std::string(argv[i]) == "-c") {
      try {
        loop = std::stoi(argv[i+1]);
      } catch (...) {
        std::cout << "Invalid Options\n";
        return 0;
      }
    } else if (std::string(argv[i]) == "-d") {
      demo = true;
    }
  }
  
  int w = 10, h=10;
  char **lolp = (char**)&init;
  if (!demo)
    lolp = (char**)parse(std::cin,w,h);
  Board lol(w,h,lolp);
  if (pretty) lol.print();
  Rule *sd = new Cgol();
  for(int i = 0; i < loop; i++) {
    lol.run(sd);
    if (pretty) {
      std::cout << "Generation " << i << '\n';
      lol.print();
      std::this_thread::sleep_for( std::chrono::milliseconds(prettyt));
    }
  }
  if (!pretty) lol.print();
}

char* parse(std::istream &in, int &w, int &h) {
  std::vector<char> data;
  char l;
  char *out;
  w = 0;
  h = 0;

  while (!in.eof()) {
    std::string inl;
    getline(in,inl);
    std::istringstream ins(inl);
    while (ins >> l) {
      if (l != ','||l != ' ') {
        data.push_back(l == '#' ? 1:0);
        w += (!h ? 1:0);
      }
    }
    h++;
  }
  h--;
  return &data[0]; 
}
