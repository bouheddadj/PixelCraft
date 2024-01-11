# Module_Image - Générateur d'un Avatar Pixel Art en Format PPM

## Description du Projet

Module_Image est un projet réalisé en C++ à partir de zéro, utilisant la bibliothèque SDL. L'objectif principal est de créer un générateur d'avatars pixel art en format PPM.

## Fonctionnalités Principales

- Génération d'un avatar pixel art personnalisés.
- Affichage dans une fenêtre SDL avec possibilité de zoom avant et arrière.

## Instructions pour l'Utilisation

Pour accéder au programme du module image, suivez ces étapes :

1. **Prérequis :**
   - Assurez-vous d'avoir installé les dépendances nécessaires : SDL2, SDL_image, SDL_ttf, SDL_mixer.
   - Utilisez les commandes d'installation fournies dans la section Prérequis.

2. **Compilation :**
   - Utilisez la commande `make clean` pour nettoyer les fichiers temporaires.
   - Utilisez la commande `make` pour compiler le projet.

3. **Exécution :**
   - Exécutez le programme généré en tapant `./bin/affichage`.
   - Une fenêtre SDL s'ouvrira, affichant l'avatar pixel art.

4. **Interaction :**
   - Utilisez les commandes de zoom pour explorer l'avatar en détail.
   - Appuyez sur ECHAPPE pour fermer la fenêtre.
   - Appuyez sur T pour zoomer.
   - Appuyez sur G pour dézoomer.

## Exemples de Résultats

![Avatar Pixel Art](docs/avatar_example.png)

## Structure du Projet

- `src/` : Contient les fichiers source.
- `obj/` : Contient les fichiers objets générés lors de la compilation.
- `docs/` : Documentation et exemples d'avatars.
- `data/` : Répertoire pour stocker les données nécessaires à l'exécution du programme (par exemple, fichiers de configuration, ressources graphiques, etc.).
- `bin/` : Contient les fichiers binaires générés lors de la compilation (par exemple, exécutable principal).

## Licence

Ce projet est sous licence GNU AGPLv3. Consultez le fichier [LICENSE](LICENSE) pour plus de détails.

