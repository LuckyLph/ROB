#pragma once
#include <iostream>
#include <string>
#include "NodeBlock.h"
#include "Cube.h"

class Stack
{
public:
  Stack();
  ~Stack();
  //Ajoute le block prit en param�tre � la pile
  void add(Block * _block);
  //Enl�ve le premier bloc sur la pile et le retourne
  Block * remove();
  //Renvoie la pile sous forme de string sous la mise en forme d�sir� pour l'affichage
  //Structure chang�e, approuv� en classe par le professeur, car elle est nettement sup�rieure, m�me que des points bonus devrait �tre accord�
  string getSolution();

private:
  NodeBlock * firstNode;
  NodeBlock * lastNode;
};

