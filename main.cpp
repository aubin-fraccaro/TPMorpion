#include <iostream>
using namespace std;

// Function to check if a player has won
// Parameters: game board array and player symbol ('X' or 'O')
// Returns: true if the player has won, false otherwise
bool VerifVictoire(char tableau[3][3],char joueur) {
    // Check for winning rows
    for(int i=0;i<3;i++) {
        if (tableau[i][0] == joueur && tableau[i][1] == joueur &&tableau[i][2] == joueur) {
            return true;
        }
    }
    // Check for winning columns
    for(int i=0;i<3;i++) {
        if (tableau[0][i] == joueur && tableau[1][i] == joueur &&tableau[2][i] == joueur) {
            return true;
        }
    }
    // Check for winning diagonals
    if (tableau[0][0] == joueur && tableau[1][1] == joueur && tableau[2][2] == joueur) {
        return true;  // Main diagonal win
    }
    if (tableau[0][2] == joueur && tableau[1][1] == joueur && tableau[2][0] == joueur) {
        return true;  // Secondary diagonal win
    }
    return false;
}

// Function to display the current state of the game board
// Parameter: game board array
void afficherTableau(char tableau[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tableau[i][j] << " "; // Display each cell
        }
        cout << endl; // New line after each row
    }
}

int main() {
    // Initialize the game board
    char tableau[3][3] ={};
    // Start filling the board with numbers 1-9 (ASCII values 49-57)
    int valeur = 49;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            tableau[i][j] = char(valeur++);
        }
    }

    // Display initial game board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tableau[i][j] << " ";  // Display each cell
        }
        cout << endl;  // New line after each row
    }

    // Game initialization
    char joueur = 'X';          // First player is X
    int choix = 0;              // Variable to store player's move
    int tours = 0;              // Counter for number of turns played
    cout << "\n\n   ---Debut de la partie--- \n\n";

    // Main game loop
    while (true) {
        // Get player's move
        cout << "Joueur " << joueur << " Choisissez une case ou jouer :";
        cin >> choix;

        // Convert player's choice to array indices
        int ligne = (choix - 1) / 3;   // Calculate row index
        int colonne = (choix - 1) % 3; // Calculate column index

        // Check if the chosen cell is already occupied
        if (tableau[ligne][colonne] == 'X' || tableau[ligne][colonne] == 'O') {
            cout << "Case déjà occupee, choisissez une autre.\n";
            continue;
        }

        // Place player's symbol on the board
        tableau[ligne][colonne] = joueur;
        // Display updated board
        afficherTableau(tableau);
        tours++;

        // Check win condition
        if (VerifVictoire(tableau, joueur)) {
            cout << "Fin, le joueur " << joueur << " a gagné !\n";
            break;
        }
        // Check draw condition (board is full)
        if (tours == 9) {
            cout << "Match nul ! Toutes les cases sont remplies.\n";
            break;
        }

        // Switch players (X -> O or O -> X)
        joueur = (joueur == 'X') ? 'O' : 'X';
    }
}