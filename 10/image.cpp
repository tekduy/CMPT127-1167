#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "image.hpp"


Image::Image()
  : cols(0),
    rows(0),
    pixels(NULL)
    { }

Image::~Image()
  {
    if (pixels != NULL){
      delete[] pixels;
    }
  }

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
  if (this->pixels == NULL){
    return 1;
  }
  this->cols = width;
  this->rows = height;
  for (int i = 0; i< width*height; i++){
    pixels[i] = fillcolor;
  }
  return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
  if (this->pixels == NULL){
    return 1;
  }

  if (x < 0 || x > this->cols || y < 0 || y > this->rows){
    return 1;
  }

  this->pixels[ y * this->cols + x ] = color;
  return 0;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
  if (this->pixels == NULL){
    return 1;
  }

  if (colorp == NULL){
    return 1;
  }

  if (x < 0 || x > this->cols || y < 0 || y > this->rows){
    return 1;
  }

  *colorp = this->pixels[ y * this->cols + x ];
  return 0;
}

