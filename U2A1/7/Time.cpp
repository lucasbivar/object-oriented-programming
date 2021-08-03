#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill; 
using std::setw;

#include <ctime>
using std::time_t;
using std::tm;
using std::time;
using std::localtime;

#include "Time.h"

Time::Time(int hr, int min, int sec){
  setTime(hr, min, sec);  
}

Time::Time(){
  time_t t = time(0);  
  tm* now = localtime(&t);
  setTime(now->tm_hour, now->tm_min, now->tm_sec);  
}

void Time::setTime(int h, int m, int s){
  setHour(h);
  setMinute(m);
  setSecond(s);  
}

void Time::setHour(int h){
  hour = (h >=0 && h < 24) ? h : 0;     
}


inline void Time::setMinute(int m){
  minute = (m >= 0 && m < 60) ? m : 0; 
}

void Time::tick(){
  if(second == 59){
    second = 0;
    if(minute == 59){
      minute = 0;
      if(hour == 23){
        hour = 0;
      }else{
        hour++;
      }
    }else{
      minute++;
    }
  }else{
    second++;
  }

}

void Time::printUniversal(){
  cout << setfill('0') << setw(2) << getHour() << ":" <<
  setw(2) << getMinute() << ":" << setw(2) << getSecond() << endl;
}

void Time::printStandard(){
  cout << ( (getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM") << endl;
}
