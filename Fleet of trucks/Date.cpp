/*
 * Date.cpp
 *
 * Created on: May 13, 2019
 * Author: Evya
 */

#include "Date.h"

/******************** default c'tor method **************************/
Date::Date():day(1),month(1),hours(00),minute(00) {}


/******************** c'tor method **************************/
Date::Date(int day,int month,int hours,int minets):day(day),
		month(month),hours(hours),minute(minets){}


/******************** c'tor method **************************/
Date::Date(const string& date){convertToDate(date);}


/******************** copy c'tor method **************************/
Date::Date(const Date &da):day(da.day),month(da.month),
		hours(da.hours),minute(da.minute){}


/******************** copy set method **************************/
Date& Date::operator=(const Date &da){
	if(this!=&da){
		this->day = da.day;
		this->hours = da.hours;
		this->minute = da.minute;
		this->month = da.month;
	}
	return *this;
}


/******************** move c'tor method **************************/
Date::Date(Date &&da){
	this->day = da.day;
	da.day = 1;
	this->month = da.month;
	da.month = 1;
	this->minute = da.minute;
	da.minute = 00;
	this->hours = da.hours;
	da.hours = 00;
}


/******************** move set method **************************/
Date& Date::operator=(Date &&da){

	if(this!=&da){
		this->day = da.day;
		da.day = 1;
		this->month = da.month;
		da.month = 1;
		this->minute = da.minute;
		da.minute = 00;
		this->hours = da.hours;
		da.hours = 00;
	}
	return *this;
}


/******************** getTheDiffrentTime method **************************/
int Date::getTheDiffrentTime(const Date &date)const{
	int res = 0;
	res = ((60-minute) + (date.getHours() - ((hours+1)%24))*60 + date.getMin());
	if(day != date.getDay()) res += abs((date.getDay() - day))*24*60;
	return res;
}

/******************** compareDateAndTime method **************************/
bool Date::compareDateAndTime(const Date &sec)const{

	if (month < sec.month)return true;
	else if (month > sec.month)return false;
	else if (day < sec.day)return true;
	else if (day > sec.day)return false;
	else if (hours < sec.hours)return true;
	else if (hours > sec.hours)return false;
	else if (minute <= sec.minute) return true;
	else return false;

}


/******************** convertToDate method **************************/
void Date::convertToDate(const string &dateAndTime){

	size_t dateStart = dateAndTime.find("/");
	size_t timeStart = dateAndTime.find(":");

	// pulling out from the string the relevants parts
	this->day = stoi(dateAndTime.substr(dateStart - 2, 2));
	this->month = stoi(dateAndTime.substr(dateStart + 1, 2));
	this->hours = stoi(dateAndTime.substr(timeStart - 2, 2));
	this->minute = stoi(dateAndTime.substr(timeStart + 1, 2));
}

/******************** getMonth method **************************/
int Date::getMonth()const{return month;}


/******************** getDay method **************************/
int Date::getDay()const{return day;}


/******************** getHours method **************************/
int Date::getHours()const{return hours;}


/******************** getMin method **************************/
int Date::getMin()const{return minute;}


/******************** d'tor method **************************/
Date::~Date() {}

