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
          if (argv[argNb] == "-h" or argv[argNb] == "--help") {
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
          } else if (argv[argNb] == "--create") {
            // Call create functions
          } else if (argv[argNb] == "--list") {
            // Call list functions
          } else if (argv[argNb] == "--show") {
            // Call show functions
          } else if (argv[argNb] == "--stats") {
            // Call stats functions
          } else if (argv[argNb] == "--edit") {
            // Call list functions
          } else {
            cout << argv[argNb] << "is not recognized" << endl;
            exit(0);
          }
        }
    }
    return 0;
}