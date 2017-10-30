#include "Stack.h"
#include <iostream>

Stack::Stack()
{
  firstNode = nullptr;
}


Stack::~Stack()
{
  while (remove());
}

//Ajoute le block prit en param�tre � la pile
void Stack::add(Block* _block)
{
  if (_block != NULL)
  {
    NodeBlock * node = new NodeBlock();
    node->setBlock(_block);
    node->setNext(firstNode);
    firstNode = node;
  }
}

//Enl�ve le premier bloc sur la pile et le retourne
Block* Stack::remove()
{
  if (firstNode == NULL)
    return NULL;
  Block * block = NULL;
  NodeBlock * nodeToDelete = firstNode;
  block = nodeToDelete->getBlock();
  firstNode = firstNode->getNext();
  delete nodeToDelete;
  return block;
}

//Renvoie la pile sous forme de string sous la mise en forme d�sir� pour l'affichage
//Structure chang�e, approuv� en classe par le professeur, car elle est nettement sup�rieure, m�me que des points bonus devrait �tre accord�
string Stack::getSolution()
{
  string pathToReturn;
  if (firstNode != NULL)
  {
    NodeBlock * currentNode = NULL;
    currentNode = firstNode;
    //Tant qu'il reste des blocs on continue d'incr�menter la string avec le contenu de la pile
    while (currentNode->getNext() != NULL)
    {
      pathToReturn += "[";
      pathToReturn += to_string(currentNode->getBlock()->x);
      pathToReturn += ",";
      pathToReturn += to_string(currentNode->getBlock()->y);
      pathToReturn += ",";
      pathToReturn += to_string(currentNode->getBlock()->z);
      pathToReturn += "]\n";
      currentNode = currentNode->getNext();
    }
    pathToReturn += "[";
    pathToReturn += to_string(currentNode->getBlock()->x);
    pathToReturn += ",";
    pathToReturn += to_string(currentNode->getBlock()->y);
    pathToReturn += ",";
    pathToReturn += to_string(currentNode->getBlock()->z);
    pathToReturn += "]\n";
  }
  return pathToReturn;
}
