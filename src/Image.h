/**
@brief Description brève du fichier Image.h
Description détaillée du fichier Image.h
@author P2111020/P2018147/P2105542
@file Image.h
@version 1.0
@date 2023/02/22
*/

#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
@brief Classe représentant une image en couleur RGB
*/
class Image

{
public:

    /**
    @brief Constructeur par défaut: Initialise les dimensions de l'image à 0 et le tableau de pixels à NULL
    */
    Image();

    /**
    @brief Destructeur de la classe Image
    Libère la mémoire allouée pour le tableau de pixels
    */
    ~Image();

    /**
    @brief Constructeur avec paramètres
    Initialise les dimensions de l'image avec les valeurs passées en paramètres et alloue la mémoire pour le tableau de pixels
    @param dimensionX Largeur de l'image
    @param dimensionY Hauteur de l'image
    */
    Image (int dimensionX, int dimensionY);

    /**
    @brief Accesseur pour un pixel
    @param x Coordonnée x du pixel (0-dimensionX)
    @param y Coordonnée y du pixel (0-dimensionY)
    @return Référence vers le pixel correspondant
    */
    Pixel& getPix (int x, int y) const;

    /**
    @brief Dessine un rectangle sur l'image
    Remplit les pixels du rectangle avec la couleur spécifiée
    @param Xmin Coordonnée x du coin supérieur gauche du rectangle
    @param Ymin Coordonnée y du coin supérieur gauche du rectangle
    @param Xmax Coordonnée x du coin inférieur droit du rectangle
    @param Ymax Coordonnée y du coin inférieur droit du rectangle
    @param couleur Couleur à utiliser pour remplir le rectangle
    */
    void dessinerRectangle (int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur);

    /**
    @brief Mutateur pour un pixel
    @param x Coordonnée x du pixel à modifier (0-dimensionX)
    @param y Coordonnée y du pixel à modifier (0-dimensionY)
    @param couleur Nouvelle couleur à assigner au pixel
    */
    void setPix (int x, int y, const Pixel& couleur);

    /**
    @brief Efface l'image
    Remplit tous les pixels de l'image avec la couleur spécifiée
    @param couleur Couleur à utiliser pour remplir l'image
    */
    void effacer (Pixel couleur);

    /**
    @brief Test de régression
    Effectue une série de tests pour vérifier que les méthodes de la classe Image fonctionnent correctement
    */
    void testRegression ();

    /**
    @brief Sauvegarde l'image dans un fichier
    Enregistre l'image au format PPM dans le fichier spécifié
    @param filename Nom du fichier de destination
    */
    void sauver (const std::string & filename) const;

    /**
    @brief Ouvre un fichier image
    Charge l'image depuis un fichier PPM
    @param filename Nom du fichier à charger
    */
    void ouvrir (const std::string & filename);

    /**
    @brief Affiche l'image dans la console
    Affiche les pixels de l'image dans la console
    */
    void afficherConsole();

    /**
    * @brief Affiche l'image dans une fenêtre SDL_Renderer
    * 
    */
    void afficher ();

    /**
    * @brief Charge l'image à partir d'un fichier et l'affiche dans un SDL_Renderer
    * 
    * @param filename Nom du fichier à charger
    * @param m_renderer Renderer SDL où afficher l'image
    */
    void loadFromFile (const char* filename, SDL_Renderer * m_renderer);

    /**
    * @brief Charge l'image depuis la surface actuelle et l'affiche dans un SDL_Renderer
    * 
    * @param m_renderer Renderer SDL où afficher l'image
    */
    void loadFromCurrentSurface (SDL_Renderer * m_renderer);

    /**
    * @brief Dessine l'image dans un SDL_Renderer avec une position, une largeur et une hauteur optionnelles
    * 
    * @param m_renderer Renderer SDL où afficher l'image
    * @param x Position x de l'image
    * @param y Position y de l'image
    * @param w Largeur de l'image (optionnel)
    * @param h Hauteur de l'image (optionnel)
    */
    void draw (SDL_Renderer * m_renderer, int x, int y, int w=-1, int h=-1);

    /**
    * @brief Récupère la texture SDL de l'image
    * 
    * @return SDL_Texture* Texture SDL de l'image
    */
    SDL_Texture * getTexture() const;

    /**
    * @brief Modifie la surface de l'image
    * 
    * @param surf Nouvelle surface à appliquer à l'image
    */
    void setSurface(SDL_Surface * surf);

    /**
    * @brief Affiche l'image dans la console en utilisant SDL
    * 
    */
    void sdlAff ();

    /**
    * @brief Facteur de zoom de l'image
    * 
    */
    float Zoom;

    /**
    * @brief Indique si l'image doit être jouée avec du son ou non
    * 
    */
    bool withSound;    

    private:
    
    /**
    * @brief Dimensions de l'image
    * 
    */
    int dimx, dimy;

    /**
    * @brief Tableau de pixels représentant l'image
    * 
    */
    Pixel* tab;

    /**
    * @brief Initialise l'affichage de l'image
    * 
    */
    void afficherInit();

    /**
    * @brief Boucle principale d'affichage de l'image
    * 
    */
    void afficherBoucle();

    /**
    * @brief Détruit l'affichage de l'image
    * 
    */
    void afficherDetruit();

};

#endif // IMAGE_H
