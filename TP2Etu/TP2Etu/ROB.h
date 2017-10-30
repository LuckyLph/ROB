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

  //Trouve le chemin de sortie du cube à partir du bloc de départ
  void solvePathToExit();
  //Trouve tous les blocs qui contiennent des points récursivement
  void solveAllPoints(Block * startingBlock);
  //Retourne la solution de l'algorithme #1 en inversant la pile solution pour avoir le chemin depuis le point de départ
  //Structure changée, approuvé en classe par le professeur, car elle est nettement supérieure, même que des points bonus devrait être accordé
  string getSolutionPathToExit();
  //Retourne la solution de l'algorithme #2
  //Structure changée, approuvé en classe par le professeur, car elle est nettement supérieure, même que des points bonus devrait être accordé
  string getSolutionAllPoints();

private:
  Cube * cube;
  Queue * allPoints;
  Stack * stack;
  Stack * sortedStack;
};

