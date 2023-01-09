#pragma once
#include <thread>
using namespace std;

class CodeTimer
{
public:
	CodeTimer();

	~CodeTimer();

private:
	chrono::time_point<chrono::steady_clock> start, end;
};