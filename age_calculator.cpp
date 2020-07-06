#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

std::list<int> months {31,28,31,30,31,30,31,31,30,31,30,31};
std::list<int>::iterator it = months.begin();

time_t th = time(NULL);
struct tm *aTime = localtime(&th);

bool isleapyear(int year)
{
	if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	else
		return false;
}

void calculate_age(int birth_date, int birth_month, int birth_year,
                   int current_date, int current_month, int current_year)
{
>-------int calculated_date, calculated_month, calculated_year;
>-------int weeks = 0;
>-------int hour, minutes, seconds;
>-------int choice;
>-------bool cont = true;

>-------if(isleapyear(birth_year)){
>------->-------std::advance(it, 1);
>------->-------*it = 29;
>------->-------it = months.begin();
>-------}
>-------if(birth_date > current_date){
>------->-------it = months.begin();
>------->-------std::advance(it, birth_month-1);
>------->-------current_date += *it;
>------->-------current_month -= 1;
>-------}

>-------if(birth_month > current_month){
>------->-------current_year -= 1;
>------->-------current_month += 12;
>-------}

>-------cout << "current year:" << current_year << " current month:" << current_month <<endl;
>-------calculated_date = current_date - birth_date;
>-------calculated_month = current_month - birth_month;
>-------calculated_year = current_year - birth_year;
>-------cout << "current year:" << current_year << " current month:" << current_month <<endl;
while(cont){
>-------cout <<"Enter you choice:\n";
>-------cout <<"0. Exit\n";
>-------cout <<"1. Normal output(Years months days)\n";
>-------cout <<"2. Normal output with time in HH:MM:SS\n";
>-------cout <<"3. In terms of days\n";
>-------cout <<"4. In terms of months, weeks and days\n";
>-------cin >> choice;
>-------switch(choice){
>------->-------case 1:
>------->------->-------cout << "The age is " << calculated_year << "years" << calculated_month << "months" << calculated_date \
>------->------->------- << "days" << "\n";
>------->------->-------break;
>------->-------case 2:
>------->------->-------hour = aTime->tm_hour;
>------->------->-------minutes = aTime->tm_min;
>------->------->-------seconds = aTime->tm_sec;
>------->------->-------cout << "The age is " << calculated_year << "years " << calculated_month << "months " << calculated_date-1 \
>------->------->------- << "days " << hour << "hours " << minutes << "minutes " << seconds <<"seconds " << "\n";
>------->------->-------break;
>------->-------case 3:{
>------->------->-------int temp = calculated_date;
>------->------->-------temp += calculated_year*365 + calculated_year/4;
>------->------->-------cout << temp <<endl;
>------->------->-------cout << "current year:" << current_year << " current month:" << current_month <<endl;
>------->------->-------if(isleapyear(aTime->tm_year) && aTime->tm_mon >= 2){
>------->------->------->-------cout << "current year is leap\n";
>------->------->------->-------temp += 1;
>------->------->------->-------cout << temp <<endl;}
>------->------->-------if(isleapyear(birth_year) && birth_month <= 2){
>------->------->------->-------cout << "birth year is leap\n";
>------->------->------->-------temp += 1;
>------->------->------->-------cout << temp <<endl;}
>------->------->-------temp += calculated_month * 30;
>------->------->-------cout << temp <<endl;
>------->------->-------cout << "The age is " << temp << "days\n";
>------->------->-------}
>------->------->-------break;
>------->-------case 4:{
>------->------->-------int temp = calculated_month;
>------->------->-------temp += calculated_year*12;
>------->------->-------if(calculated_date > 7){
>------->------->------->-------weeks = calculated_date / 7;
>------->------->------->-------calculated_date = calculated_date % 7;
>------->------->-------}
>------->------->-------cout << "The age is " << temp << "months " << weeks << "weeks " << calculated_date << "days ";
>------->------->-------}
>------->------->-------break;
>------->-------case 0:
>------->------->-------cout << "Exiting...\n";
>------->------->-------exit(EXIT_SUCCESS);
>------->-------default:
>------->------->-------cout << "Invalid choice\n";
>------->------->-------exit(EXIT_FAILURE);
>------->------->-------cont = false;
>------->-------}
>-------}
int main(void)
{
	int current_date = aTime->tm_mday;
	int current_month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	int current_year = aTime->tm_year + 1900;

	int birth_date;
	int birth_month;
	int birth_year;
	cout << "Enter DOB of an individaul to calculate age\n";
	cout << "Date :"; cin >> birth_date;
	cout << "Month :"; cin >> birth_month;
	cout << "Year :"; cin >> birth_year;
	calculate_age(birth_date, birth_month, birth_year, current_date,current_month, current_year);
	return 0;
}
