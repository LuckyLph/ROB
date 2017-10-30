#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Block.h"
#include "Constants.h"

using namespace std;

class Cube
{
public:
	Cube(string cubePath);
  ~Cube();
  
  Block * getStartBlock();
  void resetAllVisitedBlocksToFalse();

private:
  Block * startBlock;
  Block * tabBlocks[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE];
};

