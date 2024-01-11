#include "Image.h"
#include "Pixel.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

Image::Image()
{
    dimx=0;
    dimy=0;
    tab = NULL;
}

Image::~Image()
{
    if (tab != NULL) {
        delete [] tab;
        tab = NULL;
    }

    dimx=0;
    dimy=0;
}

Image::Image (int dimensionX, int dimensionY)
{
	assert (dimensionX > 0 && dimensionY > 0);
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel [dimy*dimx];
}

Pixel& Image::getPix (int x, int y) const
{
    int indice = y*dimx+x;
	assert (dimx > 0);
    return tab[indice];
}

void Image::setPix(int x, int y, const Pixel& couleur)
{

   this->getPix(x,y).setRouge(couleur.getRouge());
   this->getPix(x,y).setVert(couleur.getVert());
   this->getPix(x,y).setBleu(couleur.getBleu());

   assert (this->getPix(x,y).getRouge() == couleur.getRouge() && this->getPix(x,y).getVert() == couleur.getVert() && this->getPix(x,y).getBleu() == couleur.getBleu());

}

void Image::dessinerRectangle (int Xmin, int Ymin, int Xmax, int Ymax, Pixel couleur)
{
    for (int x = Xmin; x <= Xmax; x++)
    {
        for (int y = Ymin; y <= Ymax; y++)
        {
            setPix(x, y, couleur);
			assert (this->getPix(x,y).getRouge() == couleur.getRouge() && this->getPix(x,y).getVert() == couleur.getVert() && this->getPix(x,y).getBleu() == couleur.getBleu());
        }
    }
}

void Image::effacer(Pixel couleur)
{
    dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);

}

void Image::testRegression ()
{
	Pixel pix;

    assert(pix.getRouge()==0);
    assert(pix.getVert()==0);
    assert(pix.getBleu()==0);

    Pixel pixm(11,22,33);

    assert(pixm.getRouge()==11);
    assert(pixm.getVert()==22);
    assert(pixm.getBleu()==33);

    pixm.setRouge(44);
    pixm.setVert(55);
    pixm.setBleu(66);

    assert(pixm.getRouge()==44);
    assert(pixm.getVert()==55);
    assert(pixm.getBleu()==66);

    Image im;
    assert( im.dimx==0 );
    assert( im.dimy==0 );
    assert( im.tab==nullptr);

    Image im2(64,128);
    assert( im2.dimx==64 );
    assert( im2.dimy==128 );
    assert( im2.tab!=nullptr );

    int i,j;

    for(i=0; i<im2.dimx; i++)
        for(j=0; j<im2.dimy; j++)
        {
            assert( im2.getPix(i,j).getRouge()==0 );
            assert( im2.getPix(i,j).getBleu()==0 );
            assert( im2.getPix(i,j).getVert()==0 );
        }


    Pixel pixcouleur(100,100,100);

	im2.dessinerRectangle(0, 0, 30, 30, pixcouleur);

	for(i=0; i<=30; i++)
        	for(j=0; j<=30; j++)
       		{
		    assert( im2.getPix(i,j).getRouge()==pixcouleur.getRouge());
		    assert( im2.getPix(i,j).getBleu()==pixcouleur.getBleu());
		    assert( im2.getPix(i,j).getVert()==pixcouleur.getVert());
		}


   Pixel pixcouleur2(3,3,3);
   im2.effacer(pixcouleur2);

   	for(i=0; i<im2.dimx; i++)
		for(j=0; j<im2.dimy; j++)
		{
			    assert( im2.getPix(i,j).getRouge()==pixcouleur2.getRouge());
			    assert( im2.getPix(i,j).getBleu()==pixcouleur2.getBleu());
			    assert( im2.getPix(i,j).getVert()==pixcouleur2.getVert());
			}

    Image Image1(10,10);
    Image Image2(100,100);
    Image Image3(30,20);

    assert(Image1.getPix(2,2).getBleu()==0);
    assert(Image1.getPix(2,2).getVert()==0);
    assert(Image1.getPix(2,2).getRouge()==0);


    assert(Image2.getPix(2,2).getBleu()==0);
    assert(Image3.getPix(2,2).getBleu()==0);
        Image2.dessinerRectangle(1, 1, 10, 10, pixcouleur2);
    assert(Image2.getPix(3,3).getBleu()==3);

    Image1.effacer(pixcouleur);
    Image2.effacer(pixcouleur);
    Image3.effacer(pixcouleur);
    assert(Image1.getPix(2,2).getBleu()==100);
    assert(Image2.getPix(2,2).getBleu()==100);
    assert(Image3.getPix(2,2).getBleu()==100);


}

void Image::sauver(const std::string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y = 0; y < (unsigned int)dimy; ++y)
        for(unsigned int x=0; x<(unsigned int)dimx; ++x) {
            Pixel& pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    fichier.close();
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
}

void Image::ouvrir(const std::string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL){
        delete [] tab;
        tab = nullptr;
    }
	tab = new Pixel [dimx*dimy];

    for(unsigned int y=0; y<(unsigned int)dimy; y++){
        for(unsigned int x=0; x<(unsigned int)dimx; x++) {

            fichier >> r >> g >> b;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<(unsigned int)dimy; ++y) {
        for(unsigned int x=0; x<(unsigned int)dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

float temps () {
    return float(SDL_GetTicks()) * 1000.f / CLOCKS_PER_SEC;
}

SDL_Surface * m_surface;
SDL_Texture * m_texture;
bool m_hasChanged;
        
SDL_Window * m_window;
SDL_Renderer * m_renderer;

Image m_image;

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}

void Image::draw (SDL_Renderer * m_renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(m_renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

void Image::loadFromFile (const char* filename, SDL_Renderer * m_renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(m_renderer,surfaceCorrectPixelFormat);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * m_renderer) {
    m_texture = SDL_CreateTextureFromSurface(m_renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        exit(1);
    }
}

void Image::sdlAff () 
{

    SDL_SetRenderDrawColor(m_renderer, 60, 60, 60, 255);
    SDL_RenderClear(m_renderer);

    if (Zoom<-1){
        Zoom = -1;
    }
    float t=Zoom;

    m_image.draw(m_renderer, 50-50*t, 50-50*t, 100+t*100, 100+t*100);

}

void Image::afficherInit()
{
    
    m_surface=nullptr;
	m_texture=nullptr;
	m_hasChanged=false;
	
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_m_image could not initialize! SDL_m_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }

	int dimx, dimy;

	dimx = 200;
	dimy = 200; 

    m_window = SDL_CreateWindow("FENETRE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);
    
    m_image.loadFromFile("./data/image_affiche.ppm",m_renderer);
	
	m_image.loadFromCurrentSurface(m_renderer); 
}

void Image::afficherBoucle () {
    SDL_Event events;
	bool quit = false;

	while (!quit) {
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;
			else if (events.type == SDL_KEYDOWN) 
            { 
				switch (events.key.keysym.scancode) 
                {
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        break;

                    case SDL_SCANCODE_T:
                        Zoom += 0.1;
                        break;

                    case SDL_SCANCODE_G:
                        Zoom -= 0.1;
                        break;
                    default: break;

                        
				}
			}
		}

		sdlAff();

        SDL_RenderPresent(m_renderer);
	}
}

void Image::afficherDetruit()
{
	SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;

    TTF_Quit();
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

}

void Image::afficher (){

	this->sauver("./data/image_affiche.ppm");
	afficherInit();
	afficherBoucle();
	afficherDetruit();

}