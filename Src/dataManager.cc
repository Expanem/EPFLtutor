/*!
  \file   dataManager.cc
  \brief  Import, save, and export all data.
*/
#include <fstream>
#include <string>
#include <iostream>

#include "dataManager.h"

using namespace std;

void CourseData::write() {
  askData();
  showData();
}

void CourseData::askData() {

  array<string,5> weekDays;
  weekDays[0] = "monday";
  weekDays[1] = "tuesday";
  weekDays[2] = "wednesday";
  weekDays[3] = "thursday";
  weekDays[4] = "friday";

  cout << "What is the course name ?" << endl;
  getline(cin,name);


  cout << "What is the course description ?" << endl;
  getline(cin,description);



  do {
    cout << "On which day the exercices take place ?" << endl;
    string day;
    getline(cin,day);
    exerciseDay = -1;
    for (size_t i = 0; i < 5; i++) {
      if (weekDays[i].compare(day) == 0) {exerciseDay = i;}
    }
    if(exerciseDay == -1){cout << day << " is not a valid day (only lowercase please)." << endl;}
  } while (exerciseDay == -1);


  char userIntent;
  cout << "Do you want to save specific informations about this course ? y/n" << endl;
  cin >> userIntent;
  for (int i = 0 ; userIntent == 'y' ; i++) {
    array<string,2> temp;
    cout << "Information name: ";
    cin.ignore();
    getline(cin,temp[0]);
    cout << "Information content: " << endl;
    //cin.ignore();
    getline(cin,temp[1]);
    cout << temp[0] << ": " << temp[1] << endl;
    userContent.push_back(temp);
    cout << "Do you want to save more informations ? y/n" << endl;
    cin >> userIntent;

  }

  cout << "How many week for this course ?" << endl;
  unsigned weeks;
  cin >> weeks;
  series.resize(weeks);


  cout << "Course saved successfully!" << endl
       << "--------------------------" << endl;
}

void CourseData::showData() {

  array<string,5> weekDays;
  weekDays[0] = "monday";
  weekDays[1] = "tuesday";
  weekDays[2] = "wednesday";
  weekDays[3] = "thursday";
  weekDays[4] = "friday";

  cout << "Course : " << name << endl;
  cout << "description: " << description << endl;
  cout << "exercises on " << weekDays[exerciseDay] << endl;

  for (size_t i = 0; i < userContent.size() ; i++) {
    cout << userContent[i][0] << " : " << userContent[i][1] << endl;
  }

  cout << series.size() << " weeks for this course" << endl;

}
