/*!
  \file   statistics.h
  \brief  Analyse data for the user.
*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include "dataManager.h"

using namespace std;

vector<float> markAverage(vector<CourseData *> courses);
float markAverage(CourseData* course);
float markAverage(Serie* serie);
float average(vector<float> numbers);
vector<float *> timeOfTheDayDistribution(vector<CourseData *> courses);
float* timeOfTheDayDistribution(CourseData* course);
float* timeOfTheDayDistribution(vector<Serie *> series);
float* timeOfTheDayDistribution(vector<Exercise *> exercises);
vector<float *> dayOfTheWeekDistribution(vector<CourseData *> courses);
float* dayOfTheWeekDistribution(CourseData* course);
float* dayOfTheWeekDistribution(vector<Serie *> series);
float* dayOfTheWeekDistribution(vector<Exercise *> exercises);
vector<float> averageTimeSpentEx(vector<CourseData *> courses);
float averageTimeSpentEx(CourseData* course);
float averageTimeSpentEx(Serie* serie);
vector<float> averageTimeSpentS(vector<CourseData *> courses);
float averageTimeSpentS(CourseData* course);

#endif