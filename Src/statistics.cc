/*!
  \file   statistics.cc
  \brief  Analyse data for the user.
*/

#include "statistics.h"
#include "configuration.h"
#include "dataManager.h"

using namespace std;

vector<float> markAverage(vector<CourseData *> courses) {
  /** Compare between courses mark average **/
  vector<float> marks;
  for (size_t i = 0; i < courses.size(); i++) {
    marks.push_back(markAverage(courses[i]));
  }
  return marks;
}

float markAverage(CourseData* course) {
  /** Return the average of a course **/
  int sum = 0;
  for (size_t i = 0; i < course->getSerie().size(); i++) {
    sum += average(course->getSerie()[i]);
  }
  return sum /= course->getSerie().size();
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

vector<float *> timeOfTheDayDistribution(vector<CourseData *> courses) {
  /** Compare between courses time of the day distribution **/
  vector<float *> timeDist;
  for (size_t i = 0; i < courses.size(); i++) {
    timeDist.push_back(timeOfTheDayDistribution(courses[i]));
  }
  return timeDist;
}

float* timeOfTheDayDistribution(CourseData* course) {
  vector<Serie *> series;
  for (size_t i = 0; i < course->getSeries().size(); i++) {
    series.push_back(course->getSeries()[i]);
  }
  return timeOfTheDayDistribution(series);
}

float* timeOfTheDayDistribution(vector<Serie *> serie) {
  vector<Exercise *> exercises;
  for (size_t j = 0; j < serie.size(); j++){
    for (size_t i = 0; i < serie.getExercises().size(); i++) {
      exercises.push_back(serie.getExercises()[i]);
    }
  }
  return timeOfTheDayDistribution(exercises);
}

float* timeOfTheDayDistribution(vector<Exercise *> exercises) {
  /** Return from a list of exercises the distribution of time of the day in a array **/
  float* dayTimeDist[24];
  for (size_t i = 0; i < exercises.size(); i++) {
    dayTimeDist[exercises[i]->getHour()] += 1;
  }
  for (unsigned short i = 0; i < 24; i++) {
    dayTimeDist[i] /= exercises.size();
  }
  return dayTimeDist;
}

vector<float *> dayOfTheWeekDistribution(vector<CourseData *> courses) {
  /** Compare between courses week day distribution **/
  vector<float *> dayDist;
  for (size_t i = 0; i < courses.size(); i++) {
    dayDist.push_back(dayOfTheWeekDistribution(courses[i]));
  }
  return dayDist;
}

float* dayOfTheWeekDistribution(CourseData* course) {
  vector<Serie *> series;
  for (size_t i = 0; i < course->getSeries().size(); i++) {
    series.push_back(course->getSeries()[i]);
  }
  return dayOfTheWeekDistribution(series);
}

float* dayOfTheWeekDistribution(vector<Serie *> serie) {
  vector<Exercise *> exercises;
  for (size_t j = 0; j < serie.size(); j++){
    for (size_t i = 0; i < serie.getExercises().size(); i++) {
      exercises.push_back(serie.getExercises()[i]);
    }
  }
  return dayOfTheWeekDistribution(exercises);
}

float* dayOfTheWeekDistribution(vector<Exercise *> exercises) {
  /** Return from a list of exercises the distribution of week day in a array **/
  float* weekDay[7];
  for (size_t i = 0; i < exercises.size(); i++) {
    weekDay[exercises[i]->getDayW()] += 1;
  }
  for (unsigned short i = 0; i < 7; i++) {
    weekDay[i] /= exercises.size();
  }
  return weekDay;
}

vector<float> averageTimeSpentEx(vector<CourseData *> courses) {
 /** Compare between courses time spent per exercise **/
  vector<float> timeSpentEx;
  for (size_t i = 0; i < courses.size(); i++) {
    timeSpentEx.push_back(averageTimeSpentEx(courses[i]));
  }
  return timeSpentEx;
}

float averageTimeSpentEx(CourseData* course) {
  /** Return average time spent on exercise from a course **/
  int sum = 0;
  for (size_t i = 0; i < course->getSerie().size(); i++) {
    sum += averageTimeSpentEx(course->getSerie()[i]);
  }
  return sum /= course->getSerie().size();
}

float averageTimeSpentEx(Serie* serie) {
  /** Return average time spent on exercises from a serie **/
  int sum = 0;
  for (size_t i = 0; i < serie->getExercises().size(); i++) {
    sum += serie->getExercises()[i]->getTime();
  }
  return sum /= serie->getExercises().size();
}

vector<float> averageTimeSpentS(vector<CourseData *> courses) {
  /** Compare between courses time spent per serie **/
  vector<float> timeSpentS;
  for (size_t i = 0; i < courses.size(); i++) {
    timeSpentS.push_back(averageTimeSpentS(courses[i]));
  }
  return timeSpentS;
}

float averageTimeSpentS(CourseData* course) {
  /** Return average time spent on series from a course **/
  int sum = 0;
  for (size_t i = 0; i < course->getSerie().size(); i++) {
    for (size_t j = 0; j < course->getSerie()->getExercises().size(); j++) {
      sum += course->getSerie()[i]->getExercises()[j]->getTime();
    }
  }
  return sum /= course->getSerie().size();
}