    /**
    @brief Description brève du fichier Pixel.h
    Description détaillée du fichier Pixel.h
    @author P2111020/P2018147/P2105542
    @file Pixel.h
    @version 1.0
    @date 2023/02/22
    */

    #ifndef PIXEL_H
    #define PIXEL_H
    
    /**
    @brief Classe représentant un pixel en couleur RGB
    */
    class Pixel

    {
    public:
    
    /**
    @brief Constructeur par défaut: Initialise les valeurs de r, g et b à 0
    */
    Pixel ();

    /**
    @brief Constructeur avec paramètres: Initialise les valeurs de r, g et b avec les valeurs passées en paramètres
    @param nr Valeur pour le canal rouge (0-255)
    @param ng Valeur pour le canal vert (0-255)
    @param nb Valeur pour le canal bleu (0-255)
    */
    Pixel (int nr, int ng, int nb);

    /**
    @brief Accesseur pour le canal rouge
    @return Valeur du canal rouge (0-255)
    */
    unsigned char getRouge () const;

    /**
    @brief Accesseur pour le canal vert
    @return Valeur du canal vert (0-255)
    */
    unsigned char getVert () const;

    /**
    @brief Accesseur pour le canal bleu
    @return Valeur du canal bleu (0-255)
    */
    unsigned char getBleu () const;

    /**
    @brief Mutateur pour le canal rouge
    @param nr Nouvelle valeur pour le canal rouge (0-255)
    */
    void setRouge (int nr);

    /**
    @brief Mutateur pour le canal vert
    @param ng Nouvelle valeur pour le canal vert (0-255)
    */
    void setVert (int ng);

    /**
    @brief Mutateur pour le canal bleu
    @param nb Nouvelle valeur pour le canal bleu (0-255)
    */
    void setBleu (int nb);

    /**
    @brief Destructeur de la classe Pixel
    */
    ~Pixel();

    private:
        unsigned char r,g,b;

};

#endif // PIXEL_H