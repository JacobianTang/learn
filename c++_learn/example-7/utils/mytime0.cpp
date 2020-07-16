#include<iostream>
#include"mytime0.h"
Time::Time(){
	hours = minutes=0;
}

Time::Time(int h,int m){
	hours = h;
	minutes=m;
}

void Time::AddMin(int m){
	minutes +=m;
	hours += minutes/60;
	minutes %=60;
}

void Time::AddHr(int h){
	hours += h;
}

void Time::Reset(int h,int m){
	hours = h;
	minutes=m;
}

Time Time::Sum(const Time& t) const
{		
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes/60;
	sum.minutes %=60; 
	return sum;
}
Time Time::operator+(const Time& t)const{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes/60;
	sum.minutes %=60; 
	return sum;
}

Time Time::operator-(const Time& t)const{
	Time diff;
	int tot1 = t.hours *60 + t.minutes;
	int tot2 = hours*60  + minutes;
	diff.minutes = (tot2-tot1)%60;
	diff.hours = (tot2-tot1)/60;
	return diff;
}

Time Time::operator*(double n)const{
	Time result;
	int tot2 = hours*60  + minutes;
	result.minutes = (tot2)%60;
	result.hours = (tot2)/60;
	return result;
}

void Time::show() const{
	std::cout<<hours<<" hours," <<minutes <<" minutes";
}
