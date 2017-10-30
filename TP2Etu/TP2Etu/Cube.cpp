#include "Cube.h"

Cube::Cube(string cubePath)
{
  //Instancie tous les blocks du Cube
  for (int i = 0; i < CUBE_SIZE; i++)
  {
    for (int j = 0; j < CUBE_SIZE; j++)
    {
      for (int y = 0; y < CUBE_SIZE; y++)
      {
        tabBlocks[i][j][y] = new Block();
      }
    }
  }

	ifstream streamInput;
	streamInput.open(cubePath);
	string currentLine;

	if (!streamInput)
	{
		string exceptionCaption = "Le fichier " + cubePath + " n'existe pas.";
		throw invalid_argument(exceptionCaption);
	}

  int y = CUBE_SIZE - 1;
  int z = -1;
	while (getline(streamInput, currentLine))
	{
    bool isCubeOver = false;
    for (int x = 0; x < currentLine.size(); x++)
    {
      //Si on change niveau en x, on réinitialise le niveau en y
      if (currentLine[x] == '+')
      {
        z++;
        y = CUBE_SIZE - 1;
        isCubeOver = true;
      }
      else
      {
        tabBlocks[x][y][z]->x = x;
        tabBlocks[x][y][z]->y = y;
        tabBlocks[x][y][z]->z = z;
        tabBlocks[x][y][z]->value = currentLine[x];

        //Vérifie que le bloc est éligible à recevoir ses blocs voisins selon sa position
        if (x > 0)
        {
          tabBlocks[x][y][z]->leftBlock = tabBlocks[x - 1][y][z];
        }
        if (x < CUBE_SIZE - 1)
        {
          tabBlocks[x][y][z]->rightBlock = tabBlocks[x + 1][y][z];
        }
        if (y < CUBE_SIZE - 1)
        {
          tabBlocks[x][y][z]->frontBlock = tabBlocks[x][y + 1][z];
        }
        if (y > 0)
        {
          tabBlocks[x][y][z]->behindBlock = tabBlocks[x][y - 1][z];
        }
        if (currentLine[x] == 'U')
        {
          tabBlocks[x][y][z]->upBlock = tabBlocks[x][y][z + 1];
        }
        if (currentLine[x] == 'D')
        {
          tabBlocks[x][y][z]->downBlock = tabBlocks[x][y][z - 1];
        }
        if (currentLine[x] == 'S')
        {
          startBlock = tabBlocks[x][y][z];
        }

        //Passe la valeur en points du cube s'il en possède une
        if (currentLine[x] >= '1' && currentLine[x] <= '9')
        {
          tabBlocks[x][y][z]->points = currentLine[x] - 48;
        }
      }
    }
    //Si le cube n'est pas fini, on incrémente le niveau en y
    if (!isCubeOver)
      y--;
  }
  streamInput.close();
}

Cube::~Cube()
{
  for (int i = 0; i < CUBE_SIZE; i++)
  {
    for (int j = 0; j < CUBE_SIZE; j++)
    {
      for (int y = 0; y < CUBE_SIZE; y++)
      {
        delete tabBlocks[i][j][y];
      }
    }
  }
}


Block * Cube::getStartBlock()
{
  return startBlock;
}

void Cube::resetAllVisitedBlocksToFalse()
{
  for (int i = 0; i < CUBE_SIZE; i++)
  {
    for (int j = 0; j < CUBE_SIZE; j++)
    {
      for (int y = 0; y < CUBE_SIZE; y++)
      {
        tabBlocks[i][j][y]->visited = false;
      }
    }
  }
}
