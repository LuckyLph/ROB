struct Block
{
public:
  int x = 0;
  int y = 0;
  int z = 0;
  int points = 0;
  char value;
  bool visited = false;
  Block * upBlock;
  Block * downBlock;
  Block * leftBlock;
  Block * frontBlock;
  Block * rightBlock;
  Block * behindBlock;
};