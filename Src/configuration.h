/*!
  \file   configuration.h
  \brief  Create, Load and modify global configuration.
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>

void config(int argc, char *argv[], int &argNb);

class ConfigData {
  public:
    ConfigData();
    ~ConfigData(){};
    void reset();
    void config(int argc, char *argv[], int &argNb);
  private:
    void importConfig();
    bool onlineMode;
    bool neophyteMode;
    std::string saveFormat;
    std::string language;
};

#endif