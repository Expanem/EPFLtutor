/*!
  \file   dataManager.h
  \brief  Import, save, and export all data.
*/
#include <array>
#include <vector>

using namespace std;

class Exercise {
  public:
    Exercise(string courseName);
    Exercise(string courseName, string name);
    ~Exercise();
    void showData();
    string getID() {return id;};
  private:
    void askData();
    void yamlWrite();
    void yamlRead();
    string id;
    int date;
    int time;
    int timeToComplete;
    int mark;
    vector<string> tags;
    string courseName;
};

class Serie {
public:
  Serie(string courseName);
  Serie(string courseName, string name);
  ~Serie(){};
  void addExercise();
  void showData();
  int getId() {return ID;};
  string getName() {return name;};
  vector<Exercise*> getExercises() {return exercises;};
  Exercise* getExercise(int number) {return exercises[number];};
  Exercise* getExercise(string name);
private:
  void askData();
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
  string courseName;
};

class CourseData {
public:
  CourseData();
  CourseData(string name);
  ~CourseData(){};
  void addSerie();
  void showData();
  Serie* getSerie(string name);
  Serie* getSerie(int id);

private:
  void askData();
  void yamlWrite();
  void yamlRead();
  string name;
  string description;
  string notes;
  int exerciseDay;
  vector<array<string, 2>> userContent;
  vector<Serie *> series;
};
