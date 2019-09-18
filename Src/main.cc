/*!
  \file   main.cc
  \brief  Commandline based interface. Coordinate the different modules.
*/

#include <iostream>
#include <string>

using namespace std;

int create(int argc, char *argv[], int &argNb);
int list(int argc, char *argv[], int &argNb);
int show(int argc, char *argv[], int &argNb);
int stats(int argc, char *argv[], int &argNb);
int edit(int argc, char *argv[], int &argNb);
void help();

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "Type '--help' for a list of commands" << endl;
    } else {
        for (int argNb = 1; argNb < argc; argNb++) {
          if (string(argv[argNb]) == "-h" or string(argv[argNb]) == "--help") {
            help();
          } else if (string(argv[argNb]) == "--create") {
            // Call create functions
          } else if (string(argv[argNb]) == "--list") {
            // Call list functions
          } else if (string(argv[argNb]) == "--show") {
            // Call show functions
          } else if (string(argv[argNb]) == "--stats") {
            // Call stats functions
          } else if (string(argv[argNb]) == "--edit") {
            // Call list functions
          } else {
            cout << string(argv[argNb]) << " is not recognized" << endl;
            exit(0);
          }
        }
    }
    return 0;
}

int create(int argc, char *argv[], int &argNb){
  if (string(argv[argNb]) == "-subject") {

  } else if (string(argv[argNb]) == "-serie") {

  } else if (string(argv[argNb]) == "-exercise") {

  }
  return 0;
}

void help(){
  cout << "EPFLtutor 0.0.1" << endl
       << "This is free software: you are free to change and redistribute it, just name the main authors." << endl
       << "See: https://github.com/Goneiross/EPFLtutor for more informations and tutorials." << endl << endl;
  cout << "Commands:" << endl
       << "-h,  --help             show the help" << endl
       << "-l,  --list             " << endl
       << "-c,  --create           " << endl
       << "-s,  --stats            " << endl
       << "-c,  --create           " << endl << endl;
  cout << "Options:" << endl
       << "-subject                " << endl
       << "-serie                  " << endl
       << "-exercise               " << endl << endl;
  cout << "Examples of use:" << endl
       << "EPFLtutor --create -subject Analysis -serie               Create a new serie in Analyse" << endl
       << "EPFLtutor --show -subject Algebra -serie 4 -exercise 1    Show the first exercise of the 4h serie in Algebra" << endl
       << "EPFLtutor --list -subject Physics -serie                  List all Physics series" << endl << endl;
  exit(0);
}