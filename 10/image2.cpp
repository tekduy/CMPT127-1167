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
  delete[] this->pixels;
  this->pixels = new uint8_t[width * height];
  if (pixels == NULL){
    return 1;
  }
  for (int i = 0; i< width*height; i++){
    this->pixels[i] = fillcolor;
  }
  this->cols = width;
  this->rows = height;
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

int Image::save( const char* filename) {
    ofstream output_file(filename,ios::binary);
    if (!output_file) {
        return 0;
    }
    output_file.write(reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    output_file.write(reinterpret_cast<char*>(&rows), sizeof(unsigned int));
    output_file.write(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
    return 0;
}

int Image::load( const char* filename ){
    ifstream input_file(filename,ios::binary);
    if (!input_file) {
        return 1;
    }
    input_file.read(reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    input_file.read(reinterpret_cast<char*>(&rows), sizeof(unsigned int));
    input_file.read(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);

    return 0;
}
