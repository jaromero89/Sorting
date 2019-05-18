#include "Time.h"
#include <ctime>
#include <iostream>
using namespace std;

Time::Time() {}

Time::~Time() {}

string Time::timeNow()
{
  time_t timeNow = time(0);
  string dateTimeNow = ctime (&timeNow);

  return dateTimeNow;
}
