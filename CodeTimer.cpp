#pragma once
#include "CodeTimer.h"
#include <iostream>
using namespace std;

CodeTimer::CodeTimer()
{
	start = chrono::high_resolution_clock::now();
}

CodeTimer::~CodeTimer()
{
	end = chrono::high_resolution_clock::now();

	chrono::duration<float> duration = end - start;

	cout << "\n����� ���������� ���� = " << duration.count() << "s" << endl;
}