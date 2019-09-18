/*!
  \file   main.cc
  \brief  Commandline based interface. Coordinate the different modules.
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "Type '--help' for a list of commands" << endl;
    } else {
        for (int argNb = 1; argNb < argc; argNb++) {
          if (string(argv[argNb]) == "-h" or string(argv[argNb]) == "--help") {
            cout << "EPFLtutor 0.0.1" << endl
                 << "This is free software: you are free to change and redistribute it, just name the main authors." << endl
                 << "See: https://github.com/Goneiross/EPFLtutor for more informations and tutorials." << endl << endl;
            cout << "Commands:" << endl
                 << "-h,  --help             show the help" << endl
                 << "-l,  --list             " << endl
                 << "-c,  --create           " << endl
                 << "-s,  --stats            " << endl
                 << "-c,  --create           " << endl;
            cout << "Options:" << endl;
            exit(0);
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