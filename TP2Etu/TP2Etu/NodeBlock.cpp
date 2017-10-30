#include "NodeBlock.h"
#include "Cube.h"


NodeBlock::NodeBlock()
{
}


NodeBlock::~NodeBlock()
{
}

NodeBlock * NodeBlock::getNext()
{
  return next;
}

void NodeBlock::setNext(NodeBlock * _next)
{
  next = _next;
}

Block * NodeBlock::getBlock()
{
  return block;
}

void NodeBlock::setBlock(Block * _block)
{
  block = _block;
}
