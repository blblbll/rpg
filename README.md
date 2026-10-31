![accueil](./rpg.gif)

# my_rpg

Un petit RPG 2D en C avec la CSFML. Explore la carte, ouvre les coffres, bats les monstres, récupère la clé et affronte le boss pour finir le jeu.

## Prérequis

- `gcc` et `make`
- **CSFML 2.x** (graphics, window, system, audio), par exemple 2.5 ou 2.6.
  La CSFML 3.0 n'est **pas** compatible : ses headers ont changé.
- La bibliothèque math (`-lm`, fournie avec gcc)
- Un Système Linux ou WSL

## Installation

Sous Ubuntu / Debian (24.04 recommandé, ou WSL2 avec Ubuntu 24.04) :

```sh
sudo apt update
sudo apt install build-essential libcsfml-dev
```

Puis, à la racine du projet :

```sh
make
./my_rpg
```

## Commandes make

| Commande | Effet |
|---|---|
| `make` | compile le jeu |
| `make clean` | supprime les fichiers objets |
| `make fclean` | supprime les objets et l'exécutable |
| `make re` | recompile tout depuis zéro |

## Commandes en jeu

| Touche | Action |
|---|---|
| Flèches | se déplacer (menus : naviguer) |
| Espace | attaquer |
| E | ouvrir un coffre, ramasser un item, parler au PNJ, utiliser l'item sélectionné (dans l'inventaire) |
| P | passer les dialogues |
| I | ouvrir / fermer l'inventaire |
| ← / → ou 1 à 6 | choisir un emplacement de l'inventaire |
| Entrée | valider dans les menus (la souris marche aussi) |
| A / Z | dézoomer / zoomer |
| Échap | menu pause / retour |


## Équipe

- Marcq Julien
- Rogez Jules
- Wozniak Thomas
- Isore Hortense
