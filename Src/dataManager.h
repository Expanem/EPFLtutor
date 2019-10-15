/*!
  \file   dataManager.h
  \brief  Import, save, and export all data.
*/

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <array>
#include <vector>

using namespace std;

class Exercise {
  public:
    Exercise(string courseName);
    Exercise(string courseName, string name);
    ~Exercise();
    int getMark() {return mark;};
    int getTimeToComplete() {return time;};
    int getHour();
    int getDayW();
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
    string courseName;
};

class Serie {
public:
  Serie(string courseName);
  Serie(string courseName, string name);
  ~Serie(){};
  void addExercise();
  int getId() {return ID;};
  string getName() {return name;};
  vector<Exercise *> getExercises() {return exercises;};
  Exercise* getExercise(int id) {return exercises[id];};

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
  string courseName;
};

class CourseData {
public:
  CourseData();
  CourseData(string name);
  ~CourseData(){};
  void addSerie();
  Serie* getSerie(string name);
  Serie* getSerie(int id);
  vector<Serie *> getSeries() {return series;};

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

#endif