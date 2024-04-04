#pragma once

class Timer {
private:
	double _startTime;
	double _liftime;
public:
	Timer(double waitTime);

	void reset(double newLifetime);
  double calcDelay();
	bool isDone();
};