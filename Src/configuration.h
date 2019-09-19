/*!
  \file   configuration.h
  \brief  Create, Load and modify global configuration.
*/

void config(int argc, char *argv[], int &argNb);

class ConfigData {
  public:
    ConfigData();
    ~ConfigData(){};
    void reset();
  private:
    void importConfig();
    bool onlineMode;
    std::string saveFormat;
    std::string language;
};