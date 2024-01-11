#include "Pixel.h"

#include <iostream>
#include <cassert>

Pixel::Pixel()
{
    r=0;
    g=0;
    b=0;
}

Pixel::Pixel (int nr, int ng, int nb)
{
    assert (nr <= 255 && ng <= 255 && nb <= 255 && "Les composants doivents etre < ou = à 255");

    r=nr;
    g=ng;
    b=nb;

}

unsigned char Pixel::getRouge ()const
{
    return r;
}

unsigned char Pixel::getVert()const
{
    return g;
}

unsigned char Pixel::getBleu()const
{
    return b;
}

Pixel::~Pixel()
{
    //dtor
}

void Pixel::setRouge (int nr)
{
    r=nr;
}

void Pixel::setVert (int ng)
{
    g=ng;
}

void Pixel::setBleu (int nb)
{
    b=nb; 
}


