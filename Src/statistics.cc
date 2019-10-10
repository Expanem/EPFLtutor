/*!
  \file   statistics.cc
  \brief  Analyse data for the user.
*/

#include "statistics.h"
#include "configuration.h"
#include "dataManager.h"

using namespace std;

float markAverage(CourseData course) {
  /** Return the average of a course **/
  int sum = 0;
  for (size_t i = 0; i < course.getSerie().size(); i++) {
    sum += average(course.getSerie()[i]);
  }
  return sum /= course.getSerie().size();
}

float markAverage(Serie* serie) {
  /** Return the average of a serie' marks **/
  int sum = 0;
  for (size_t i = 0; i < serie->getExercises().size(); i++) {
    sum += serie->getExercises()[i]->getMark();
  }
  return 1 + (sum /= serie->getExercises().size()) * 5;
}

float average(vector<float> numbers) {
  /** Return the average of a list **/
  int sum = 0;
  for (size_t i = 0; i < numbers.size(); i++) {
    sum += numbers[i];
  }
  return sum / numbers.size();
}