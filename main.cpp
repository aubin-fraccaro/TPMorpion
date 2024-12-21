#include <iostream>
using namespace std;

bool VerifVictoire(char tableau[3][3],char joueur) {
    //Vérification des Lignes Gagnantes
    for(int i=0;i<3;i++) {
        if (tableau[i][0] == joueur && tableau[i][1] == joueur &&tableau[i][2] == joueur) {
            return true;
        }
    }//Vérification des Colonnes gagnantes
    for(int i=0;i<3;i++) {
        if (tableau[0][i] == joueur && tableau[1][i] == joueur &&tableau[2][i] == joueur) {
            return true;
        }
    }
    // Vérification des diagonales
    if (tableau[0][0] == joueur && tableau[1][1] == joueur && tableau[2][2] == joueur) {
        return true;  // Diagonale principale gagnante
    }
    if (tableau[0][2] == joueur && tableau[1][1] == joueur && tableau[2][0] == joueur) {
        return true;  // Diagonale secondaire gagnante
    }
    return false;
}

void afficherTableau(char tableau[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tableau[i][j] << " "; // Affichage de chaque élément
        }
        cout << endl; // Ligne suivante
    }
}

int main() {
    char tableau[3][3] ={};
    int valeur = 49;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            tableau[i][j] = char(valeur++);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tableau[i][j] << " ";  // Affichage de chaque élément
        }
        cout << endl;  // Pour passer à la ligne suivante après chaque ligne du tableau
    }
    char joueur = 'X';
    int choix = 0;
    int tours = 0;
    cout << "\n\n   ---Debut de la partie--- \n\n";
    while (true) {
        cout << "Joueur " << joueur << " Choisissez une case ou jouer :";
        cin >> choix;
        int ligne = (choix - 1) / 3;   // Calcul de l'indice de la ligne
        int colonne = (choix - 1) % 3; // Calcul de l'indice de la colonne
        if (tableau[ligne][colonne] == 'X' || tableau[ligne][colonne] == 'O') {
            cout << "Case déjà occupee, choisissez une autre.\n";
            continue;
        }
        tableau[ligne][colonne] = joueur;
        afficherTableau(tableau);
        tours++;

        // Vérifier si le joueur a gagné
        if (VerifVictoire(tableau, joueur)) {
            cout << "Fin, le joueur " << joueur << " a gagné !\n";
            break;
        }
        // Vérifier si la grille est pleine (match nul)
        if (tours == 9) {
            cout << "Match nul ! Toutes les cases sont remplies.\n";
            break;
        }

        // Changer de joueur
        joueur = (joueur == 'X') ? 'O' : 'X';
    }

    }

