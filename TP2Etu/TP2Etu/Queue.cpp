#include "Queue.h"


Queue::Queue()
{
  lastNode = nullptr;
  firstNode = lastNode;
  totalPoints = 0;
}


Queue::~Queue()
{
  while (remove());
}

//Rajoute le bloc prit en paramètre a la file
void Queue::add(Block * _block)
{
  NodeBlock * newNode = new NodeBlock();
  newNode->setBlock(_block);
  newNode->setNext(NULL);
  if (lastNode == NULL)
  {
    firstNode = newNode;
  }
  else
  {
    lastNode->setNext(newNode);
  }
  lastNode = newNode;
}

//Enlève le premier bloc dans la file et le retourne
Block * Queue::remove()
{
  Block * block = NULL;
  if (lastNode != NULL && firstNode != NULL)
  {
    block = firstNode->getBlock();
    NodeBlock * nodeToRemove = firstNode;
    firstNode = firstNode->getNext();
    delete nodeToRemove;
    if (firstNode == NULL)
    {
      lastNode = NULL;
    }
  }
  return block;
}

//Renvoie la file sous forme de string sous la mise en forme désiré pour l'affichage
//Structure changée, approuvé en classe par le professeur, car elle est nettement supérieure, même que des points bonus devrait être accordé
string Queue::getSolution()
{
  string pathToReturn;
  if (firstNode != NULL)
  {
    NodeBlock * currentNode = NULL;
    currentNode = firstNode;
    //Tant qu'il reste des blocs on continue d'incrémenter la string avec le contenu de la file
    while (currentNode->getNext() != NULL)
    {
      totalPoints += currentNode->getBlock()->value - 48;
      pathToReturn += to_string(currentNode->getBlock()->value - 48);
      if (currentNode->getBlock()->value - 48 > 1)
        pathToReturn += " points dans le bloc ";
      else
        pathToReturn += " point  dans le bloc ";
      pathToReturn += "[";
      pathToReturn += to_string(currentNode->getBlock()->x);
      pathToReturn += ",";
      pathToReturn += to_string(currentNode->getBlock()->y);
      pathToReturn += ",";
      pathToReturn += to_string(currentNode->getBlock()->z);
      pathToReturn += "]\n";
      currentNode = currentNode->getNext();
    }
    totalPoints += currentNode->getBlock()->value - 48;
    pathToReturn += to_string(currentNode->getBlock()->value - 48);
    if (currentNode->getBlock()->value - 48 > 1)
      pathToReturn += " points dans le bloc ";
    else
      pathToReturn += " point  dans le bloc ";
    pathToReturn += "[";
    pathToReturn += to_string(currentNode->getBlock()->x);
    pathToReturn += ",";
    pathToReturn += to_string(currentNode->getBlock()->y);
    pathToReturn += ",";
    pathToReturn += to_string(currentNode->getBlock()->z);
    pathToReturn += "]\n";
    pathToReturn += "Pour un total de ";
    pathToReturn += to_string(totalPoints);
    pathToReturn += " points!\n";
  }
  return pathToReturn;
}