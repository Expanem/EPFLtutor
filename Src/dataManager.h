/*!
  \file   dataManager.h
  \brief  Import, save, and export all data.
*/
#include <vector>
#include <array>

using namespace std;

typedef struct exercice {
  string id;
  int timeToComplete;
  vector<string> tags;
} exercice;


class Serie {
  public:
    Serie(){};
  private:
    int week;
    string structure;
    vector<exercice> exercices;
}; 

class CourseData {
public:
  CourseData();
  CourseData(string name);
  ~CourseData();
private:
  void askData();
  void showData();
  void yamlWrite();
  string name;
  string description;
  string notes;
  int exerciseDay;
  vector<array<string,2>> userContent;
  vector<Serie> series;
};
