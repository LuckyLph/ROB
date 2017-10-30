#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <vld.h>
#include "ROB.h"
#include "Cube.h"

using namespace std;

class ConsoleMenu
{
public:
	ConsoleMenu();
	~ConsoleMenu();
	void Run();

private:
	char ReadValidInput(char tabValidInputs[], int nbElements);
	void DisplayMenu();
	void DisplayCredits();
	bool ManageSelection(char entry);

  ROB * rob;
  Cube * cube;
};

