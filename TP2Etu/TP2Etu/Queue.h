#pragma once
#include <iostream>
#include "NodeBlock.h"
#include "Cube.h"

class Queue
{
public:
  Queue();
  ~Queue();
  //Rajoute le bloc prit en paramètre a la file
  void add(Block * _block);
  //Enlève le premier bloc dans la file et le retourne
  Block * remove();
  //Renvoie la file sous forme de string sous la mise en forme désiré pour l'affichage
  //Structure changée, approuvé en classe par le professeur, car elle est nettement supérieure, même que des points bonus devrait être accordé
  string getSolution();

private:
  NodeBlock * firstNode;
  NodeBlock * lastNode;
  int totalPoints;
};

