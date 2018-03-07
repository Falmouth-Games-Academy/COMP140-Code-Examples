#pragma once

class Timer
{
public:
	Timer();
	~Timer();

	void Start();
	void Stop();
	void Update();

	float GetCurrentTime()
	{
		return CurrentTime;
	};
	float GetLastTime()
	{
		return LastTime;
	};
	float GetElpasedTime()
	{
		return ElapsedTime;
	};
private:
	float CurrentTime;
	float LastTime;
	float ElapsedTime;
};
