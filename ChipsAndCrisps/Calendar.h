#pragma once
#include <string>
#include <time.h>
#include <ctime>
#include <iostream>


class Calendar {
public:
	Calendar() { //debug
		year = 2014;
		days = 0;
		hours = 6;
		minutes = 0;
	};
	Calendar(int year, int days, int hours, int minutes) {
		this->year	  = year;
		this->days    = days;
		this->hours	  = hours;
		this->minutes = minutes;
	}

	~Calendar() {}

	int passMinute() {
		int input;
		std::cout << "How many minutes?\n";
		std::cin >> input;
		minutes += input;
		timeUnitPassed();
		return getMinutes();
	}
	int passHour() {
		hours++;
		timeUnitPassed();
		return getHours();
	}

	void timeUnitPassed() { //Checks if Year or Day has passed;
		if ((minutes / 60) == 1) {
			hours++;
			minutes = 0;
		}
		if ((hours / 21) == 1) {
			days++;
			hours = 6;
		}
		if ((days / 365) == 1) {
			year++;
			days = 0;
		}
	}

	void debugString() {
		std::cout << std::to_string(year) + " years " +
			std::to_string(days) + " days " +
			std::to_string(hours) + " hours" +
			std::to_string(minutes) + " minutes\n";
	}

	time_t getDate() {
		return ((time_t)year - 1970) * 31557600 + //seconds in a year
			(time_t)days * 86400 +		//seconds in a day
			(time_t)hours * 3600 +		//seconds in an hour
			(time_t)minutes * 60;		//seconds in a minute
	}

	std::string dateToString(time_t seconds) {
		char buffer[32];
		struct tm * timeinfo; //Time structure

		timeinfo = localtime(&seconds);
		strftime(buffer,32, "%a %d/%b/%G %R", timeinfo); //formats the time based no parameters
		return buffer;
	}

	std::string dateToString(int yr, int dy, int hr, int mt) {
		return dateToString(getDate());
	}

	std::string toString() {
		return dateToString(year, days, hours, minutes);
	}

	int getYear() {
		return year;
	}

	int getHours() {
		return hours;
	}

	int getDays() {
		return days;
	}

	int getMinutes() {
		return minutes;
	}

private:
	int year;
	int days;
	int hours;
	int minutes;
};