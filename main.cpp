#include <iostream>
#include "header.h"

using namespace std;

int main(int argc, char const *argv[]) {

  int joueur(1);
  int tour(1);
  int choix(0);
  bool fin(false);
  //Un petit tableau qui contiendra les symboles avec lesquelles les joueurs joueront (par défaut X pour le joueur 1 et O pour le joueur 2)
  char motif[2];
  motif[0] = 'X';
  motif[1] = 'O';
  /*declaration du tableau lignes qui contiendra le nombre de cases cochés dans une ligne donnée tel que les lignes 0,1,2 sont les colonnes de la grille allant de gauche à droite, les lignes 3,4,5 sont les lignes de la grille allant de haut en bas, et les lignes 6 et 7 sont les lignes horizentales \ et / respectivemment. */
  int lignes[8];
  //declaration du tableau grille qui nous permettra de savoir si une case n'a pas encore été cochée (0), ou a été cochée par le joueur 1 (1) ou par le joueur 2 (2);

  int grille[9];
  //initialisation du tableau lignes et grille
  for (int i=0;i<8;++i)
  {
    lignes[i] = 0;
    grille[i] = 0;
  }
  //bon il reste une case...
  grille[8] = 0;

  //On commence?

  affichGrille(grille, motif);
  while (!fin && tour<10) {
    do{
      if (joueur==1) cout << "Joueur 1 à vous de jouer : " << endl;
      else cout << "Joueur 2 à vous de jouer : " << endl;
      cin >> choix;
      choix = cochCase(grille , lignes, choix,joueur);
    }while (choix == 2);
    system("clear");
    affichGrille(grille, motif);
    if (choix==1)
    {
      fin = true;
      if (joueur==1) cout << "Felicitations Joueur 1 vous avez gagné!" << endl;
      else cout << "Felicitations Joueur 2 vous avez gagné!" << endl;
    }
    else ++tour;
    if (tour>9) cout << "Fin de partie. Match nul" << endl;
    joueur *= -1;
  }

  return 0;
}
