#include "timer.h"
#include<iostream>
#include <windows.h>


timer::timer(void)
{
	if(!QueryPerformanceFrequency(&Lint))
		std::cerr<<"QueryPerformanceFrequency failed"<<std::endl;

	freq = (double)(Lint.QuadPart)/1000000000;	//get number of clock ticks per nanoseconds
}


void timer::StartTimer(void)
{
	QueryPerformanceCounter(&Lint);
	start_time = Lint.QuadPart;
}

double timer::GetTime(void)
{
	QueryPerformanceCounter(&Lint);

	return (((double)(Lint.QuadPart - start_time))/freq);
}