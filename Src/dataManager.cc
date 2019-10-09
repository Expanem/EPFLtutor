/*!
  \file   dataManager.cc
  \brief  Import, save, and export all data.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

#include "dataManager.h"

using namespace std;

CourseData::CourseData(string name) {
  /** Constructor to import an existing course **/
  yamlRead();
  showData();
}

CourseData::CourseData() {
  /** Constructor to create a new course **/
  askData();
  showData();
  yamlWrite();
}

void CourseData::addSerie() {
  series.push_back(new Serie);
}

Serie* CourseData::getSerie(string name) {
  for (int i = 0; i < series.size(); i++) {
    if (series[i]->getName() == name){
      return series[i];
    }
  }
  cout << "Wrong serie name, please check informations you entered" << endl;
  exit(1);
}

Serie* CourseData::getSerie(int id) {
  for (int i = 0; i < series.size(); i++) {
    if (series[i]->getId() == id){
      return series[i];
    }
  }
  cout << "Wrong serie id, please check informations you entered" << endl;
}

void CourseData::askData() {
  array<string, 5> weekDays;
  weekDays[0] = "monday";
  weekDays[1] = "tuesday";
  weekDays[2] = "wednesday";
  weekDays[3] = "thursday";
  weekDays[4] = "friday";

  cout << "What is the course name ?" << endl;
  getline(cin, name);

  cout << "What is the course description ?" << endl;
  getline(cin, description);

  do {
    cout << "On which day the exercices take place ?" << endl;
    string day;
    getline(cin, day);
    exerciseDay = -1;
    for (size_t i = 0; i < 5; i++) {
      if (weekDays[i].compare(day) == 0) {
        exerciseDay = i;
      }
    }
    if (exerciseDay == -1) {
      cout << day << " is not a valid day (only lowercase please)." << endl;
    }
  } while (exerciseDay == -1);

  char userIntent;
  cout << "Do you want to save specific informations about this course ? y/n" << endl;
  cin >> userIntent;
  for (int i = 0; userIntent == 'y'; i++) {
    array<string, 2> temp;
    cout << "Information name: ";
    cin.ignore();
    getline(cin, temp[0]);
    cout << "Information content: " << endl;
    // cin.ignore();
    getline(cin, temp[1]);
    cout << temp[0] << ": " << temp[1] << endl;
    userContent.push_back(temp);
    cout << "Do you want to save more informations ? y/n" << endl;
    cin >> userIntent;
  }

  cout << "How many week for this course ?" << endl;
  unsigned weeks;
  cin >> weeks;
  series.resize(weeks);

  cout << "Course saved successfully!" << endl << "--------------------------" << endl;
}

void CourseData::showData() {
  array<string, 5> weekDays;
  weekDays[0] = "monday";
  weekDays[1] = "tuesday";
  weekDays[2] = "wednesday";
  weekDays[3] = "thursday";
  weekDays[4] = "friday";

  cout << "Course : " << name << endl;
  cout << "description: " << description << endl;
  cout << "exercises on " << weekDays[exerciseDay] << endl;

  for (size_t i = 0; i < userContent.size(); i++) {
    cout << userContent[i][0] << " : " << userContent[i][1] << endl;
  }
  cout << series.size() << " weeks for this course" << endl;
}

void CourseData::yamlWrite() {
  ofstream file;
  file.open(name + ".save");
  file << "%YAML 1.2\n---\nCourse : " << name << endl
       << "description : " << description << endl
       << "day : " << exerciseDay << endl
       << endl;
  file << "user data : " << endl;
  for (size_t i = 0; i < userContent.size(); i++) {
    file << "- " << userContent[i][0] << " : " << userContent[i][1] << endl;
  }
  file << endl;
  file.close();
}

void CourseData::yamlRead() {}

Serie::Serie(string name) {
  /** Constructor to import an existing serie **/
  yamlRead();
  showData();
}

Serie::Serie() {
  /** Constructor to create a new serie **/
  askData();
  showData();
  yamlWrite();
}

void Serie::addExercise() {
  exercises.push_back(new Exercise);
}

void Serie::askData() {}

void Serie::showData() {}

void Serie::yamlWrite() {}

void Serie::yamlRead() {}

void Serie::realTimeEx() {
  clock_t t;
  vector<int> times;
  string action;
  while (action.compare("exit") != 0) {
    t = clock();
    cin >> action;
    times.push_back(clock() - t);
  }
}

Exercise::Exercise() {
  /** Constructor to create a new exercise **/
  askData();
  showData();
  yamlWrite();
}

Exercise::Exercise(string name) {
  /** Constructor to import an existing serie **/
  yamlRead();
  showData();
}

void Exercise::askData() {}

void Exercise::showData() {}

void Exercise::yamlWrite() {}

void Exercise::yamlRead() {}