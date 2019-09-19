/*!
  \file   dataManager.cc
  \brief  Import, save, and export all data.
*/
#include <fstream>
#include <string>

#include "dataManager.h"

void CourseData::write() {
 askData();

}

void CourseData::askData() {
  cout<<"what is the course name ?"<<endl;
  cin>>name;

  cout<<"what is the course description ?"<<endl;
  cin>>description;

  do{
    cout<<"on wich day the exercices take place ?"<<endl
     <<"0=Monday --> 4=Friday"<<endl;
    cin>>exerciseDay;
    if(exerciseDay > 5 || exerciseDay < 0){
      cout<<exerciseDay<<" is not a valid day."<<endl;
    }
  }while(exerciseDay < 5 && exerciseDay >= 0);

  cout<<"what is the course name ?"<<endl;
  cin>>name;

  cout<<"what is the course name ?"<<endl;
  cin>>name;
}
