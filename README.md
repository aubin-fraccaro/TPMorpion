
# Jeu de Tic-Tac-Toe

Ceci est une implémentation simple du jeu classique de Tic-Tac-Toe en C++. Le jeu se déroule sur une grille de 3x3 où deux joueurs placent tour à tour leurs marques (soit 'X' soit 'O') dans la grille. L'objectif est d'être le premier à placer trois de ses marques en ligne horizontale, verticale ou diagonale.

## Fonctionnalités

- **Jeu à Deux Joueurs** : Les joueurs placent leurs marques à tour de rôle.
- **Détection de Victoire** : Le jeu détecte et annonce le gagnant.
- **Détection de Match Nul** : Le jeu détecte et annonce un match nul si toutes les cases sont remplies sans gagnant.
- **Validation des Entrées** : Le jeu s'assure que les joueurs ne placent pas leurs marques dans des cases déjà occupées.

## Comment Jouer

1. **Démarrer le Jeu** : Exécutez le programme. Le plateau de jeu sera affiché avec des numéros de 1 à 9 indiquant les positions.
2. **Faire un Mouvement** : Les joueurs entrent à tour de rôle le numéro correspondant à la position où ils veulent placer leur marque.
3. **Victoire ou Match Nul** : Le jeu annoncera le gagnant ou un match nul lorsque la partie se terminera.

## Aperçu du Code

### Fonctions

- **VerifVictoire** : Vérifie si le joueur actuel a gagné en vérifiant les lignes, colonnes et diagonales.
  - **Paramètres** :
    - `char tableau[3][3]` : La grille de jeu.
    - `char joueur` : Le joueur actuel ('X' ou 'O').
  - **Retourne** : `true` si le joueur a gagné, `false` sinon.

- **afficherTableau** : Affiche l'état actuel du plateau de jeu.
  - **Paramètres** :
    - `char tableau[3][3]` : La grille de jeu.

- **main** : Contient la boucle principale du jeu, gère les entrées des joueurs, met à jour le plateau de jeu et vérifie les conditions de victoire ou de match nul.
  - **Variables** :
    - `char tableau[3][3]` : La grille de jeu.
    - `char joueur` : Le joueur actuel ('X' ou 'O').
    - `int choix` : Le choix de la case par le joueur.
    - `int tours` : Le nombre de tours joués.

### Fonctionnement

1. **Initialisation** : La grille de jeu est initialisée avec des numéros de 1 à 9.
2. **Boucle de Jeu** :
   - Le joueur actuel choisit une case.
   - La case choisie est vérifiée pour s'assurer qu'elle n'est pas déjà occupée.
   - La marque du joueur est placée dans la case choisie.
   - La grille de jeu est affichée.
   - Le jeu vérifie si le joueur actuel a gagné.
   - Le jeu vérifie si toutes les cases sont remplies (match nul).
   - Le joueur actuel est changé.
3. **Fin de Partie** : Le jeu annonce le gagnant ou un match nul et se termine.
