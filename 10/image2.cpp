#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "image2.hpp"
#include <iostream>
#include <fstream>

using namespace std;

/*
public:
  unsigned int cols;
  unsigned int rows;
  uint8_t* pixels;
*/

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
  if(pixels) {
      if(x < this->cols && y < this->rows) {
          this->pixels[(this->cols * y) + x] = color;
          return 0;
      }
  }
  return 1;
}


int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
  if(pixels && colorp != NULL) {
      if(x < this->cols && y < this->rows)  {
          *colorp = this->pixels[(this->cols * y) + x];
          return 0;
      }
  }
  return 1;
}

int Image::save( const char* filename) {
    if(filename == NULL){
       return 1;
    }
    ofstream output_file(filename,ios::binary);
    if (!output_file) {
        return 1;
    }
    if (!(reinterpret_cast<char*>(&cols), sizeof(unsigned int))){
      return 1;
    }
    if (!(reinterpret_cast<char*>(&rows), sizeof(unsigned int))){
      return 1;
    }
    if (!(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows)){
      return 1;
    }
    /*
    output_file.write(reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    output_file.write(reinterpret_cast<char*>(&rows), sizeof(unsigned int));
    output_file.write(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
    */
    return 0;

}

int Image::load( const char* filename ){
    if(filename == NULL){
       return 1;
    }

    ifstream input_file(filename,ios::binary);
    if (!input_file) {
        return 1;
    }
    if (!(input_file.read(reinterpret_cast<char*>(&cols), sizeof(unsigned int)))){
      return 1;
    }
    if (!(input_file.read(reinterpret_cast<char*>(&rows), sizeof(unsigned int)))){
      return 1;
    }
    if (!(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows)){
      return 1;
    }
    /*
    input_file.read(reinterpret_cast<char*>(&cols), sizeof(unsigned int));
    input_file.read(reinterpret_cast<char*>(&rows), sizeof(unsigned int));
    input_file.read(reinterpret_cast<char*>(&pixels), sizeof(uint8_t) * cols * rows);
    */

    return 0;
}
