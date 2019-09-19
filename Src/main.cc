/*!
  \file   main.cc
  \brief  Commandline based interface. Coordinate the different modules.
*/

#include <iostream>
#include <string>

#define TYPE_SUBJECT 1
#define TYPE_SERIE 2
#define TYPE_EXERCISE 3

using namespace std;

typedef struct dataAdress {
  string subject;
  string serie;
  string exercise;
} dataAdress;

void create(int argc, char *argv[], int &argNb);
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
            create(argc, argv, argNb);
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

void create(int argc, char *argv[], int &argNb) {
  argNb++;
  int type;
  dataAdress adress;
  cout << "Creating:";
  while (argNb < argc ) {
    if (string(argv[argNb]) == "-subject") {
      argNb++;
      type = TYPE_SUBJECT;
      cout << " subject ";
      if (argNb < argc) { adress.subject = string(argv[argNb]); cout << adress.subject; argNb++; type = TYPE_SERIE; }
    } else if (string(argv[argNb]) == "-serie") {
      argNb++;
      type = TYPE_SERIE;
      cout << ", serie ";
      if (argNb < argc) { adress.serie = string(argv[argNb]); cout << adress.serie ; argNb++; type = TYPE_EXERCISE; }
    } else if (string(argv[argNb]) == "-exercise") {
      argNb++;
      type = TYPE_EXERCISE;
      cout << ", exercise ";
      if (argNb < argc) { adress.exercise = string(argv[argNb]); cout << adress.exercise; argNb++; }
    }
  }
  cout << endl;
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