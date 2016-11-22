#include <stdio.h>
#include <string.h>
#include <math.h>

int InRectangle(float pt[2], float rect[4]){
  int max_x = rect[2];
  int max_y = rect[3];
  int min_x = rect[0];
  int min_y = rect[1];
  if ((pt[0] == rect[0] && pt[1] == rect[1]) || (pt[0] == rect[2] && pt[1] == rect[3])){
    return 1;
  }

  else if ((pt[0] == rect[2] && pt[1] == rect[1]) || (pt[0] == rect[0] && pt[1] == rect[3])){
    return 1;
  }
  else if ((pt[0] <= max_x && pt[1] <=max_y) && (pt[0] >= min_x && pt[1] >= min_y)){
    return 1;
  }
  else{
    return 0;
  }
}
