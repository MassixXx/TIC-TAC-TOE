#include <iostream>
#include "header.h"

using namespace std;

//fonction qui coche la case numéro _case et renvoie 0 si ça s'est bien passé, 2 si la case est déja occupée ou le nombre n'est pas entre 1 et 9, et 1 quand la partie est terminée
//joueur est égal à 1 (j1) ou -1 (j2)
int cochCase(int grille[],int lignes[],int _case,int joueur)
{
  if (_case<1 || _case>9)
  {
    cout << "Veuillez entrer un nombre valide! " << endl;
    return 2;
  }
  else if (grille[_case-1]!=0)
  {
    cout << "Case déjà cochée. Veuillez choisir une case libre." << endl;
    return 2;
  }
  else
  {
    grille[_case-1] = joueur;
    lignes[(_case-1)%3] += joueur;
    lignes[3+(_case-1)/3] += joueur;
    if (_case == 5)
    {
      lignes[6] += joueur;
      lignes[7] += joueur;
    }
    else if (_case == 1 || _case == 9) lignes[6] += joueur;
    else if (_case == 3 || _case == 7) lignes[7] += joueur;

    if (rechSequenc(lignes,9,3*joueur)) return 1;
    else return 0;
  }
}

void affichGrille(int grille[],char motif[])
{
  char dessin;
  for (int i=0;i<9;++i)
  {
    if (grille[i]==1) dessin = motif[0];
    else if (grille[i]==-1) dessin = motif[1];
    else dessin = 49 + i;
    cout << dessin;
    if ((i+1)%3==0) cout << endl << "--+--+--" << endl;
    else cout << " | ";
  }
}

bool rechSequenc(int tab[],int tail,int val)
{
  bool trouv(false);
  int i(0);
  while (!trouv && i<tail)
  {
    if (tab[i]==val) trouv = true;
    else ++i;
  }
  return trouv;
}
