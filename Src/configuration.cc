/*!
  \file   configuration.cc
  \brief  Create, Load and modify global configuration.
*/

#include <iostream>
#include <fstream>

#include "configuration.h"

#define ONLINE_MODE_DEFAULT false
#define SAVE_FORMAT_DEFAULT "yaml"
#define LANGUAGE_FORMAT_DEFAULT "english"

using namespace std;

void newConfigFile();

ConfigData::ConfigData() {
  ifstream flux(".conf");
  if(flux.fail()) {
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

void config(int argc, char *argv[], int &argNb) {
  // Edit the config file, given the user arguments
  // Will have also an interactive version, with argument -i
  exit(0);
}

void newConfigFile() {
  ofstream flux(".conf", std::ofstream::out);
  flux << "online_mode: " << ONLINE_MODE_DEFAULT << endl;
  flux << "save_format: " << SAVE_FORMAT_DEFAULT << endl;
  flux << "language: " << LANGUAGE_FORMAT_DEFAULT << endl;
  flux.close();
}