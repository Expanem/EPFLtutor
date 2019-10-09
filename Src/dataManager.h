/*!
  \file   dataManager.h
  \brief  Import, save, and export all data.
*/
#include <array>
#include <vector>

using namespace std;

class Exercise {
  public:
    Exercise();
    Exercise(string name);
    ~Exercise();
  private:
    void askData();
    void showData();
    void yamlWrite();
    void yamlRead();
    string id;
    int date;
    int time;
    int timeToComplete;
    int mark;
    vector<string> tags;
};

class Serie {
public:
  Serie(string name);
  Serie();
  ~Serie(){};
  void addExercise();
  int getId() {return ID;};
  string getName() {return name;};
private:
  void askData();
  void showData();
  void yamlWrite();
  void yamlRead();
  void realTimeEx();
  int ID;
  int week;
  string name; 
  string structure;
  string related;
  vector<string> tags;
  vector<string> notes;
  vector<Exercise *> exercises;
};

class CourseData {
public:
  CourseData();
  CourseData(string name);
  ~CourseData(){};
  void addSerie();
  Serie* getSerie(string name);
  Serie* getSerie(int id);

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
  vector<Serie *> series;
};
