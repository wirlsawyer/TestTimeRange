// TimeRange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

struct TIME{
	int seconds;
	int minutes;
	int hours;
};

void Difference(struct TIME t1, struct TIME t2, struct TIME *diff);
void Difference2(struct TIME t1, struct TIME t2, struct TIME *differ);

void Test(int h1, int m1, int s1, int h2, int m2, int s2, int h3, int m3, int s3)
{
	struct TIME t1,t2,diff;
	t1.hours = h1;
	t1.minutes = m1;
	t1.seconds = s1;

	t2.hours = h2;
	t2.minutes = m2;
	t2.seconds = s2;

	Difference2(t1,t2,&diff);
	cout << endl << "TIME DIFFERENCE: " << t1.hours << " : " << t1.minutes << " : " << t1.seconds;
	cout << " - " << t2.hours << " : " << t2.minutes << " : " << t2.seconds;
	cout << " = " << diff.hours << " : " << diff.minutes << " : " << diff.seconds;
	if (diff.hours == h3 && diff.minutes == m3 && diff.seconds == s3)
	{
		cout << " Correct";
	}else{
		cout << " Fail";
	}
	
	cout << "\n-------------------------------------------------------------------------\n";


}

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*
	cout << "Enter start time: " << endl;
	cout << "Enter hours, minutes and seconds respectively: ";
	cin >> t1.hours >> t1.minutes >> t1.seconds;
	cout << "Enter stop time: " << endl;
	cout << "Enter hours, minutes and seconds respectively: ";
	cin >> t2.hours >> t2.minutes >> t2.seconds;
*/

	Test(02, 15, 15, 22, 00, 00, 19, 44, 45);

	Test(07, 35, 35, 8, 45, 45, 01, 10, 10);

	Test(07, 35, 35, 8, 35, 35, 01, 00, 00);

	Test(22, 15, 15, 02, 00, 00, 03, 44, 45);

	Test(22, 15, 15, 02, 40, 30, 04, 25, 15);

	Test(24, 00, 00, 00, 00, 01, 00, 00, 01);

	Test(23, 59, 59, 24, 00, 00, 00, 00, 01);

	Test(23, 59, 59, 00, 00, 30, 00, 00, 31);

	system("PAUSE");
	return 0;
}

void Difference2(struct TIME t1, struct TIME t2, struct TIME *differ)
{
	int totalSec1 = (t1.hours*60*60 + t1.minutes*60 + t1.seconds); 
	int totalSec2 = (t2.hours*60*60 + t2.minutes*60 + t2.seconds); 

	int totalSec = 0;

	if (t1.hours>t2.hours)
	{
		totalSec = 86400 -totalSec1 + totalSec2;		
	} else {
		totalSec = totalSec2 - totalSec1;
	}

	differ->hours =  (int)floor((double)totalSec / 3600);	
	differ->minutes =  (int)floor((double)(totalSec / 60 % 60));
	differ->seconds = totalSec % 60;
}

void Difference(struct TIME t1, struct TIME t2, struct TIME *differ)
{
	//22:00:00~02:15:00

	if (t1.hours>t2.hours)
	{	
		int totalSec = 86400 - (t1.hours*60*60 + t1.minutes*60 + t1.seconds); 

		differ->hours =  (int)floor((double)totalSec / 3600);	
		differ->minutes =  (int)floor((double)(totalSec / 60 % 60));
		differ->seconds = totalSec % 60;

		differ->hours += t2.hours;
		differ->minutes += t2.minutes;
		differ->seconds += t2.seconds;

		if (differ->seconds >= 60)
		{
			differ->seconds %= 60;
			differ->minutes++;
		}
		

		if (differ->minutes >= 60)
		{
			differ->minutes %= 60;
			differ->hours++;
		}

	}else{
		int totalSec = 3600 - (t1.minutes*60 + t1.seconds);
		totalSec+=  (t2.hours -(t1.hours+1)) * 3600;

		differ->hours =  (int)floor((double)totalSec / 3600);	
		differ->minutes =  (int)floor((double)(totalSec / 60 % 60));
		differ->seconds = totalSec % 60;

		//differ->hours += t2.hours;
		differ->minutes += t2.minutes;
		differ->seconds += t2.seconds;

		if (differ->seconds >= 60)
		{
			differ->seconds %= 60;
			differ->minutes++;
		}


		if (differ->minutes >= 60)
		{
			differ->minutes %= 60;
			differ->hours++;
		}

	}

	
}