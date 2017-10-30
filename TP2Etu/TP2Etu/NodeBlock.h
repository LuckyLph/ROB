#pragma once

#include "Cube.h"

class NodeBlock
{
public:
  NodeBlock();
  ~NodeBlock();
  NodeBlock * getNext();
  void setNext(NodeBlock * _next);
  Block * getBlock();
  void setBlock(Block * _block);
private:
  NodeBlock * next;
  Block * block;
};

