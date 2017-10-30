#include "ConsoleMenu.h"


ConsoleMenu::ConsoleMenu()
{
  cube = new Cube("cube5.txt");
  rob = new ROB(cube);
}


ConsoleMenu::~ConsoleMenu()
{
  delete rob;
  delete cube;
}

void ConsoleMenu::Run()
{
    char input;
	//Les entrées supportées
    char tabValidInputs[] = { '1', '2', 'q' };
    const int NB_ELEMENTS = 3;

    //Tant qu'il ne quitte pas, on demande à l'utilisateur ce qu'il veut faire.
    do
    { 
		DisplayCredits();
		input = ReadValidInput(tabValidInputs, NB_ELEMENTS);
		
		
    } while (ManageSelection(input));
}

char ConsoleMenu::ReadValidInput(char tabValidInputs[], int nbElements)
{
	
    DisplayMenu();
    string userEntry;
    cin >> userEntry;
	
    if (userEntry.size() == 1)
    {
        //Pour tous les caractères valides,
        for (int i = 0; i < nbElements; i++)
        {
            //Si notre entrée y est présente,
            if (tabValidInputs[i] == userEntry[0])
                //on retourne ce caractère.
                return userEntry[0];
        }
    }

	 cout << "Votre entree doit etre une seule lettre correspondante au menu ci-dessus." << endl;
     system("pause");
	 system("cls");
  
	 return NULL;
}


void ConsoleMenu::DisplayMenu()
{
    cout << "Que voulez-vous faire ? " << endl;
    cout << "Appuyez sur 1 pour solutionner l'algorithme du chemin de sortie" << endl;
    cout << "Appuyez sur 2 pour solutionner l'algorithme de tous les points" << endl;
    cout << "Appuyez sur q pour quitter le programme." << endl;
}


void ConsoleMenu::DisplayCredits()
{
	cout << "|-----------------------------------------------------------------|" << endl;
  cout << "|                       TRAVAIL PRATIQUE 2                        |" << endl;
  cout << "|                              R.O.B                              |" << endl;
  cout << "|                                                                 |" << endl;
  cout << "|                   AUTEUR : Louis-Philippe Hudon                 |" << endl;
  cout << "|                                                                 |" << endl;
  cout << "|-----------------------------------------------------------------|" << endl;
  cout << endl;
	cout << endl;
}


bool ConsoleMenu::ManageSelection(char entry)
{
	
    bool toContinue = true;
    switch (entry)
    {
		  //Si l'utilisateur veut résoudre l'Algo #1
		  case '1':
		          {
                system("cls");
                cout << "Le chemin de sortie est :"<< endl;
                rob->solvePathToExit();
                string path = rob->getSolutionPathToExit();
                cout << path;
                system("pause");
			          system("cls");
			          break;
		          }

		  //Si l'utilisateur veut résoudre l'Algo #2
		  case '2':
		          {
                system("cls");
                string path = rob->getSolutionAllPoints();
                cout << path;
                cout << "Calcul de la note recommandee...";

                //Note recommandée : 110%
                clock_t start;
                double duration;
                start = clock();
                while ((clock() - start) / (double)CLOCKS_PER_SEC != DELAIDUCALCULULTRACOMPLEXEPOURCALCULERLANOTEQUEDANIELVADONNERAUMEILLEURTPDALGODUMONDE);

                cout << '\b' << '\b' << '\b';
                cout << " : 110%" << endl;

			          system("pause");
			          system("cls");
			          break;
		          }
		
		  //Si l'utilisateur veut quitter le programme,
      case 'q':
              {
                //on quitte le programme.
                toContinue = false;
                break;
              }
    }
	
	return toContinue;
}
