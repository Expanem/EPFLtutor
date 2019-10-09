/*!
  \file   statistics.cc
  \brief  Analyse data for the user.
*/

#include "statistics.h"
#include "configuration.h"
#include "dataManager.h"

using namespace std;

float average(CourseData course) {
  /** Return the average of a course **/
  int sum = 0;
  for (size_t i = 0; i < course.getSerie().size()) {
    sum += average(course.getSerie()[i]);
  }
  return sum /= course.getSerie().size();
}

float average(Serie* serie) {
  /** Return the average of a serie' marks **/
  int sum = 0;
  for (size_t i = 0; i < serie->getExercises().size()) {
    sum += serie->getExercises()[i]->getMark();
  }
  return sum /= serie->getExercises().size();
}

float average(vector<float> numbers) {
  /** Return the average of a list **/
  int sum = 0;
  for (size_t i = 0; i < numbers.size(); i++) {
    sum += numbers[i];
  }
  return sum / numbers.size();
}