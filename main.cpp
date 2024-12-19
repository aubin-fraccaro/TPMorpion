#include <iostream>
using namespace std;

bool VerifVictoire(char tableau[3][3],char joueur) {
    //Ligne des lignes
    for(int i=0;i<3;i++) {
        if (tableau[i][0] == joueur && tableau[i][1] == joueur &&tableau[i][2] == joueur) {
            return true;
        }
    }
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
}

void printDefaultTab() {
    int tableau[3][3] ={};
    int valeur = 1;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            tableau[i][j] = valeur++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tableau[i][j] << " ";  // Affichage de chaque élément
        }
        cout << endl;  // Pour passer à la ligne suivante après chaque ligne du tableau
    }
}

int main() {
    printDefaultTab();
        return 0;
    }
