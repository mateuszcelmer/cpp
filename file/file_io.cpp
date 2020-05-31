// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  fstream myfile;
  myfile.open ("example.txt", ios::out | ios::in | ios::binary);
  myfile << "Writing this to a file.\n";

  // read by line
  string line;
  getline (myfile,line);
  cout << line << endl;

  // read bt char
  char ch;
  while(myfile >> noskipws >> ch)
    std::cout << ch;

  myfile.close();
  return 0;
}