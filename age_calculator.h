#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

std::list<int> months {31,28,31,30,31,30,31,31,30,31,30,31};
std::list<int>::iterator it = months.begin();

time_t th = time(NULL);
struct tm *aTime = localtime(&th);

bool isleapyear(int year);
void calculate_age(int birth_date, int birth_month, int birth_year, int current_date, int current_month, int current_year);
