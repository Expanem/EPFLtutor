/*!
  \file   dataManager.cc
  \brief  Def, import, save, and export all data.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <filesystem>


#include "dataManager.h"

using namespace std;
namespace fs = std::filesystem;

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
  /** Create a new serie and add it to the course **/
  series.push_back(new Serie(name));
}

Serie* CourseData::getSerie(string name) {
  /** Return a pointer to a Serie, given the name **/ 
  for (int i = 0; i < series.size(); i++) {
    if (series[i]->getName() == name){
      return series[i];
    }
  }
  cout << "Wrong serie name, please check informations you entered" << endl;
  exit(1);
}

Serie* CourseData::getSerie(int id) {
  /** Return a pointer to a Serie, given the id **/ 
  for (int i = 0; i < series.size(); i++) {
    if (series[i]->getId() == id){
      return series[i];
    }
  }
  cout << "Wrong serie id, please check informations you entered" << endl;
  exit(1);
}

void CourseData::askData() {
  /** Get data from the user for a course **/ 
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
  /** Print in commandLines the course data **/
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
  /** Write all course data in a YAML formated file **/
  ofstream file;
  file.open(name + ".save");
  file << "%YAML 1.2\n---\nCourse: " << name << endl
       << "description: " << description << endl
       << "day: " << exerciseDay << endl
       << endl;
  file << "user_data: " << endl;
  for (size_t i = 0; i < userContent.size(); i++) {
    file << "- " << userContent[i][0] << " : " << userContent[i][1] << endl;
  }
  file << endl;
  file.close();
}

void CourseData::yamlRead() {
  /** Get course data from a YAML formated file **/
}

Serie::Serie(string courseName, string name) {
  /** Constructor to import an existing serie **/
  yamlRead();
  showData();
}

Serie::Serie(string courseName) {
  /** Constructor to create a new serie **/
  askData();
  showData();
  yamlWrite();
}

void Serie::addExercise() {
  /** Create a new Exercise and add it to the serie **/
  exercises.push_back(new Exercise(courseName));
}

Exercise* Serie::getExercise(string name) {
  /** Return a pointer to a Serie, given the name **/ 
  for (int i = 0; i < exercises.size(); i++) {
    if (exercises[i]->getID() == name){
      return exercises[i];
    }
  }
  cout << "Wrong exercise name, please check informations you entered" << endl;
  exit(1);
}

void Serie::askData() {
  /** Get Serie data from the user **/ 
  cout << "Which number is this serie ?" << endl;
  cin >> ID;
  cout << "Do you want to add a specific name ? (just press enter to ignore)" << endl;
  cin >> name;
  cout << "Which week is it ?" << endl;
  cin >> week;
  cout << "Would you like to give a structure ? (press enter to ignore)" << endl;
  cin >> structure;
  cout << "What is the topic related to this serie ?" << endl;
  cin >> related;
  cout << "Do you want to add tags ? (leave empty when you are finished)" << endl;
  string inputTmp;
  cin >> inputTmp;
  while (inputTmp != "") {
    tags.push_back(inputTmp);
    cin >> inputTmp;
  }
  cout << "Would you like to add some personal notes ? (leave empty when done)" << endl;
  cin >> inputTmp;
  while (inputTmp != "") {
    notes.push_back(inputTmp);
    cin >> inputTmp;
  }
  cout << "Do you want to interactively add exercises ? (y/n)" << endl;
  cin >> inputTmp;
  if (inputTmp == "y") {
    cout << "To add ..." << endl;
    exit(1);
    // TO ADD
  } else {
    exit (0);
  }
}

void Serie::showData() {
  /** Print in commandLines the serie data **/
  cout << "id: " << ID << endl
       << "week: " << week << endl
       << "name: " << name << endl
       << "structure: " << structure << endl
       << "related: " << related << endl
       << "tags: ";
   for (size_t i = 0 ; i < tags.size(); i++){
     cout << tags[i] << " ";
   }
   cout << endl;
   cout << "notes: ";
   for (size_t i = 0 ; i < notes.size(); i++){
     cout << notes[i] << " ";
   }
   cout << endl;
}

void Serie::yamlWrite() {
  /** Write all the serie data in a YAML formated file **/
  ofstream flux(courseName + ".save");
  flux << endl
       << "serie: " << ID << endl
       << "week: " << week << endl
       << "name: " << name << endl
       << "structure: " << structure << endl
       << "related: " << related << endl;
  flux << "tags: ";
  for (size_t i = 0; tags.size(); i++){
    flux << tags[i];
  }
  flux << endl;
  flux << "notes: ";
  for (size_t i = 0; notes.size(); i++){
    flux << notes[i];
  }
  /*
  for (size_t i = 0; exercises.size(); i++){
    exercises[i]->yamlWrite();
  } */
  flux << endl;
  flux.close();
}

void Serie::yamlRead() {
  /** Get Serie data from a YAML formated file **/
}

void Serie::realTimeEx() {
  /** Allow the user to exercise in real time **/
  clock_t t;
  vector<int> times;
  string action;
  while (action.compare("exit") != 0) {
    t = clock();
    cin >> action;
    times.push_back(clock() - t);
  }
}

Exercise::Exercise(string courseName) {
  /** Constructor to create a new exercise **/
  askData();
  showData();
  yamlWrite();
}

Exercise::Exercise(string courseName, string name) {
  /** Constructor to import an existing serie **/
  yamlRead();
  showData();
}

void Exercise::askData() {
  /** Get exercise data from the user **/ 
  cout << "Please give an ID for the exercise (ex: 1.a.ii)." << endl;
  cin >> id;
  cout << "When did you do this exercise ? (ddmmyyyy)" << endl;
  cin >> date;
  cout << "What time of the day ? (hhmmss, 24h format)" << endl;
  cin >> time;
  cout << "How much time did you need to complete it ?" << endl;
  cin >> timeToComplete;
  cout << "Give yourself a mark, 2 the best, 0 the worst." << endl;
  cin >> mark;
  cout << "Would you like to add tags ? (leave blank when you are done)" << endl;
  string inputTmp;
  cin >> inputTmp;
  while (inputTmp != "") {
    tags.push_back(inputTmp);
    cin >> inputTmp;
  }
}

void Exercise::showData() {
  /** Print in commandLines the exercise data **/
  cout << "id: " << id << endl
       << "date: " << date << endl
       << "time: " << time << endl
       << "timeToComplete: " << timeToComplete << endl
       << "mark: " << mark << endl
       << "tags";
  for (size_t i = 0; i < tags.size(); i++){
    cout << tags[i] << " ";
  }
  cout << endl;

}

void Exercise::yamlWrite() {
  /** Write all the exercise data in a YAML formated file **/
  ofstream flux(courseName + ".save");
  flux << "id: " << id << endl
       << "date: " << date << endl
       << "time: " << time << endl
       << "time_to_complete: " << timeToComplete << endl
       << "mark: " << mark << endl;
  flux << "tags: ";
  for (size_t i = 0; tags.size(); i++){
    flux << tags[i];
  }
  flux << endl;
  flux.close();
}

void Exercise::yamlRead() {
  /** Get exercise data from a YAML formated file **/
}

vector<string> getSavedCourseNames(string path) {
  vector<string> courses;
  for (const auto & entry : fs::directory_iterator(path)) {
    if (entry.path().extension() == ".save"){
      courses.push_back(string(entry.path().stem()));       
    }
  }
  return courses;
}