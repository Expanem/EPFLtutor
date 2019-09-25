/*!
  \file   dataManager.h
  \brief  Import, save, and export all data.
*/
#include <array>
#include <vector>

using namespace std;

typedef struct exercice {
  string id;
  int date;
  int time;
  int timeToComplete;
  int mark;
  vector<string> tags;
} exercice;

class Serie {
public:
  Serie(string name);
  Serie();
  ~Serie(){};

private:
  void askData();
  void showData();
  void yamlWrite();
  void yamlRead();
  void realTimeEx();
  int ID;
  int week;
  string structure;
  string related;
  vector<string> tags;
  vector<string> notes;
  vector<exercice> exercices;
};

class CourseData {
public:
  CourseData();
  CourseData(string name);
  ~CourseData(){};

private:
  void askData();
  void showData();
  void yamlWrite();
  void yamlRead();
  string name;
  string description;
  string notes;
  int exerciseDay;
  vector<array<string, 2>> userContent;
  vector<Serie> series;
};
