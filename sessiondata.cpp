#include "sessiondata.h"

using namespace std;

SessionData::SessionData(int id, time_t time, float baseline_before, float baseline_after)
{
  this-> id = id;
  session_time = localtime(&time);
  before_baseline = baseline_before;
  after_baseline = baseline_after;
  day = getWeekdayStr(session_time->tm_wday);
}

/**
 * @brief return the string version of the weekday from struct tm
 *
 * @param num takes the integer representing the weekday in the struct tm
 * @return string representation of the day of the week
 *
 * @warning returns empty string if num is less than 0 or greater than 6
 */
string SessionData::getWeekdayStr(int num){

    if (num < 0 || num > 6) {
        return "";
    } else {
        string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return days[num];
    }
}

/**
 * @brief return the string version of the date from struct tm in the format dd/mm/yyyy
 *
 * @param num takes a tm struct from ctime.h
 * @return string representation of the date (dd/mm/yyyy)
 *
 */
string SessionData::getDateStr(){
    string am_pm = (this->session_time->tm_hour < 12) ? "AM" : "PM";
    int hour = (this->session_time->tm_hour < 12) ? this->session_time->tm_hour : this->session_time->tm_hour - 12;
    if (hour == 0) {
        hour = 12; // If hour is 0 (midnight), set it to 12
    }
    return to_string(1 + this->session_time->tm_mon) + "/"
            + to_string(this->session_time->tm_mday) + "/"
            + to_string(1900 + this->session_time->tm_year) + " "
            + to_string(hour) + ":"
            + (this->session_time->tm_min < 10 ? "0" : "") + to_string(this->session_time->tm_min) + ":"
            + (this->session_time->tm_sec < 10 ? "0" : "") + to_string(this->session_time->tm_sec) + " "
            + am_pm;
}

string SessionData::getData(){
    return to_string(getID()) + "     " + getDateStr() + "\n";
}

int SessionData::getID(){
    return this->id;
}

float SessionData::getBeforeBaseline(){
    return this->before_baseline;
}

float SessionData::getAfterBaseline(){
    return this->after_baseline;
}
