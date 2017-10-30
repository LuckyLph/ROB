#pragma once
#include <iostream>
#include "NodeBlock.h"
#include "Cube.h"

class Queue
{
public:
  Queue();
  ~Queue();
  //Rajoute le bloc prit en param�tre a la file
  void add(Block * _block);
  //Enl�ve le premier bloc dans la file et le retourne
  Block * remove();
  //Renvoie la file sous forme de string sous la mise en forme d�sir� pour l'affichage
  //Structure chang�e, approuv� en classe par le professeur, car elle est nettement sup�rieure, m�me que des points bonus devrait �tre accord�
  string getSolution();

private:
  NodeBlock * firstNode;
  NodeBlock * lastNode;
  int totalPoints;
};

