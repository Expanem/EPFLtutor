/*!
  \file   configuration.cc
  \brief  Create, Load and modify global configuration.
*/

#include <fstream>
#include <iostream>

#include "configuration.h"

#define ONLINE_MODE_DEFAULT false
#define SAVE_FORMAT_DEFAULT "yaml"
#define LANGUAGE_FORMAT_DEFAULT "english"

using namespace std;

void newConfigFile();

ConfigData::ConfigData() {
  ifstream flux(".conf");
  if (flux.fail()) {
    flux.close();
    reset();
  } else {
    flux.close();
    importConfig();
  }
}

void ConfigData::reset() {
  onlineMode = ONLINE_MODE_DEFAULT;
  saveFormat = SAVE_FORMAT_DEFAULT;
  language = LANGUAGE_FORMAT_DEFAULT;

  newConfigFile();
}

void ConfigData::importConfig() {
  ifstream flux(".conf");
  if (!flux) {cout << "Unable to open file " << ".conf" << endl; exit(0);}
  string inputData;
  while(flux >> inputData) {
    if (inputData == "online_mode:") {
      bool(flux) >> onlineMode;
    } else if (inputData == "save_format:") {
      flux >> saveFormat;
    } else if (inputData == "language:") {
      flux >> language;
    } else {
      cout << "Wrong save format, please delete the .conf." << endl;
      exit(0);
    }
  }

  flux.close();
}

void ConfigData::config(int argc, char *argv[], int &argNb) {
  while (argNb < argc) {
    if (string(argv[argNb]) == "--help") {
      cout << "EPFLtutor specific help gor config." << endl
           << "Arguments:" << endl
           << "-online_mode" << endl
           << "-save_format" << endl
           << "-language" << endl
           << "Examples:" << endl
           << "EPFLtutor --config -online_mode true" << endl;
      return;
    } else if (string(argv[argNb]) == "-online_mode") {
      argNb++;
      if (argNb < argc) {
        onlineMode = bool(argv[argNb]);
      } else {
        cout << "Missing argument after " << string(argv[--argNb]) << ". You must specify the new value." << endl;
        exit(1);
      }
    } else if (string(argv[argNb]) == "-save_format") {
      argNb++;
      if (argNb < argc) {
        saveFormat = string(argv[argNb]);
      } else {
        cout << "Missing argument after " << string(argv[--argNb]) << ". You must specify the new value." << endl;
        exit(1);
      }
    } else if (string(argv[argNb]) == "-language") {
      argNb++;
      if (argNb < argc) {
        language = string(argv[argNb]);
      } else {
        cout << "Missing argument after " << string(argv[--argNb]) << ". You must specify the new value." << endl;
        exit(1);
      }
    } else if (string(argv[argNb]) == "-i") {
      cout << "Iteractive mode not yet implemented, please do it or ask on github." << endl;
      exit(1);
    } else {
      argNb++;
    }
  }
  exit(0);
}

void newConfigFile() {
  ofstream flux(".conf", std::ofstream::out);
  flux << "online_mode: " << ONLINE_MODE_DEFAULT << endl;
  flux << "save_format: " << SAVE_FORMAT_DEFAULT << endl;
  flux << "language: " << LANGUAGE_FORMAT_DEFAULT << endl;
  flux.close();
}