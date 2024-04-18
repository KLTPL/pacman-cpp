#include "Timer.h"
#include "raylib.h"

Timer::Timer(double lifetime): 
	_startTime(GetTime()), 
	_liftime(lifetime) 
{}

void Timer::reset(double newLifetime) {
	this->_startTime = GetTime();
}

double Timer::calcDelay() {
	return (GetTime() - this->_startTime);
}

bool Timer::isDone() {
	return (GetTime() - this->_startTime >= this->_liftime);
}
