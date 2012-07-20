#ifndef TIMER_H
#define TIMER_H

#include <windows.h>

class timer
{
public:
	timer(void);
	static void StartTimer(void);
	static double GetTime(void);

private:
	static LARGE_INTEGER Lint;
	static double freq;
	static long long start_time;
};

#endif