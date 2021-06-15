/*
 * Date.h
 * This class represents a Date object
 * Created on: May 13, 2019
 * Author: Evya
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <cmath>

using namespace std;

class Date {

private:

	int day,month,hours,minute;

public:

	Date();
	Date(const string& date);
	Date(int day,int month,int hours,int minets);
	Date(const Date &da);
	Date& operator=(const Date &da);
	Date(Date &&da);
	Date& operator=(Date &&da);

	int getTheDiffrentTime(const Date &date)const;
	void convertToDate(const string &dateAndTime);
	bool compareDateAndTime(const Date &sec)const;
	int getMonth()const;
	int getDay()const;
	int getHours()const;
	int getMin()const;

	virtual ~Date();
};

#endif /* DATE_H_ */
