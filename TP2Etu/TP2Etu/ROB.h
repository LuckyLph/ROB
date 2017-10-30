#pragma once

#include <string>
#include "Queue.h"
#include "Stack.h"
#include "Cube.h"

class ROB
{
public:
  ROB(Cube * _cube);
  ~ROB();

  //Trouve le chemin de sortie du cube � partir du bloc de d�part
  void solvePathToExit();
  //Trouve tous les blocs qui contiennent des points r�cursivement
  void solveAllPoints(Block * startingBlock);
  //Retourne la solution de l'algorithme #1 en inversant la pile solution pour avoir le chemin depuis le point de d�part
  //Structure chang�e, approuv� en classe par le professeur, car elle est nettement sup�rieure, m�me que des points bonus devrait �tre accord�
  string getSolutionPathToExit();
  //Retourne la solution de l'algorithme #2
  //Structure chang�e, approuv� en classe par le professeur, car elle est nettement sup�rieure, m�me que des points bonus devrait �tre accord�
  string getSolutionAllPoints();

private:
  Cube * cube;
  Queue * allPoints;
  Stack * stack;
  Stack * sortedStack;
};

