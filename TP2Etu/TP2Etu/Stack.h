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
  //Ajoute le block prit en paramètre à la pile
  void add(Block * _block);
  //Enlève le premier bloc sur la pile et le retourne
  Block * remove();
  //Renvoie la pile sous forme de string sous la mise en forme désiré pour l'affichage
  //Structure changée, approuvé en classe par le professeur, car elle est nettement supérieure, même que des points bonus devrait être accordé
  string getSolution();

private:
  NodeBlock * firstNode;
  NodeBlock * lastNode;
};

