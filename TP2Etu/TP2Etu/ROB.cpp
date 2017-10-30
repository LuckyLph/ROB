#include "ROB.h"

ROB::ROB(Cube * _cube)
{
  cube = _cube;
  stack = new Stack();
  allPoints = new Queue();
  sortedStack = new Stack();
}


ROB::~ROB()
{
  delete stack;
  delete allPoints;
  delete sortedStack;
}

//Trouve le chemin de sortie du cube � partir du bloc de d�part
void ROB::solvePathToExit()
{
  Block * currentBlock = cube->getStartBlock();
  bool exitReached = false;
  while (!exitReached)
  {
    //V�rifie si le bloc est la sortie
    if (currentBlock->value == 'E')
    {
      currentBlock->visited = true;
      stack->add(currentBlock);
      exitReached = true;
    }
    //V�rifie ensuite dans toute les directions possibles si le bloc suivant est accessible et s'il n'a pas �t� visit�
    else if (currentBlock->value == 'U' && !currentBlock->upBlock->visited)
    {
      currentBlock->visited = true;
      stack->add(currentBlock);
      currentBlock = currentBlock->upBlock;
    }
    else if (currentBlock->value == 'D' && !currentBlock->downBlock->visited)
    {
      currentBlock->visited = true;
      stack->add(currentBlock);
      currentBlock = currentBlock->downBlock;
    }
    else if (currentBlock->leftBlock->value != '*' && !currentBlock->leftBlock->visited)
    {
      currentBlock->visited = true;
      stack->add(currentBlock);
      currentBlock = currentBlock->leftBlock;
    }
    else if (currentBlock->rightBlock->value != '*' && !currentBlock->rightBlock->visited)
    {
      currentBlock->visited = true;
      stack->add(currentBlock);
      currentBlock = currentBlock->rightBlock;
    }
    else if (currentBlock->frontBlock->value != '*' && !currentBlock->frontBlock->visited)
    {
      currentBlock->visited = true;
      stack->add(currentBlock);
      currentBlock = currentBlock->frontBlock;
    }
    else if (currentBlock->value != 'S' && currentBlock->behindBlock->value != '*' && !currentBlock->behindBlock->visited)
    {
      currentBlock->visited = true;
      stack->add(currentBlock);
      currentBlock = currentBlock->behindBlock;
    }
    //Si aucun d�placement n'est possible d�pile les blocs pour rebrousser chemin
    else
    {
      currentBlock->visited = true;
      currentBlock = stack->remove();
    }
  }
}

//Trouve tous les blocs qui contiennent des points r�cursivement
void ROB::solveAllPoints(Block * startingBlock)
{
  startingBlock->visited = true;
  //Si le bloc contient des points, on l'ajoute � la file
  if (startingBlock->points > 0)
  {
    allPoints->add(startingBlock);
  }
  //V�rifie ensuite dans toute les directions possibles si le bloc suivant est accessible et s'il n'a pas �t� visit�
  if (startingBlock->value != 'E' && startingBlock->value != 'S' && startingBlock->behindBlock->value != '*' && !startingBlock->behindBlock->visited)
  {
    solveAllPoints(startingBlock->behindBlock);
  }
  if (startingBlock->frontBlock->value != '*' && !startingBlock->frontBlock->visited)
  {
    solveAllPoints(startingBlock->frontBlock);
  }
  if (startingBlock->leftBlock->value != '*' && !startingBlock->leftBlock->visited)
  {
    solveAllPoints(startingBlock->leftBlock);
  }
  if (startingBlock->rightBlock->value != '*' && !startingBlock->rightBlock->visited)
  {
    solveAllPoints(startingBlock->rightBlock);
  }
  if (startingBlock->value == 'D' && startingBlock->downBlock->value != '*' && !startingBlock->downBlock->visited)
  {
    solveAllPoints(startingBlock->downBlock);
  }
  if (startingBlock->value == 'U' && startingBlock->upBlock->value != '*' && !startingBlock->upBlock->visited)
  {
    solveAllPoints(startingBlock->upBlock);
  }
}

//Retourne la solution de l'algorithme #1 en inversant la pile solution pour avoir le chemin depuis le point de d�part
//Structure chang�e, approuv� en classe par le professeur, car elle est nettement sup�rieure, m�me que des points bonus devrait �tre accord�
string ROB::getSolutionPathToExit()
{
  solvePathToExit();
  cube->resetAllVisitedBlocksToFalse();
  Block * blockToTransfer;
  //Tant qu'il reste des blocs dans la pile solution, continuer � les d�piler dans la pile tri�
  do
  {
    blockToTransfer = stack->remove();
    sortedStack->add(blockToTransfer);
  }
  while (blockToTransfer != NULL);
  return sortedStack->getSolution();
}

//Retourne la solution de l'algorithme #2
//Structure chang�e, approuv� en classe par le professeur, car elle est nettement sup�rieure, m�me que des points bonus devrait �tre accord�
string ROB::getSolutionAllPoints()
{
  solveAllPoints(cube->getStartBlock());
  cube->resetAllVisitedBlocksToFalse();
  return allPoints->getSolution();
}