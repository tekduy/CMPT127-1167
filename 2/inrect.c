#include <stdio.h>
#include <string.h>
#include <math.h>

int InRectangle(float pt[2], float rect[4]){
  /*
  int max_x = rect[2];
  int max_y = rect[3];
  int min_x = rect[0];
  int min_y = rect[1];
  */
  float max_x;
  float min_x;
  float max_y;
  float min_y;

  if (rect[2]>rect[0]){
    max_x = rect[2];
    min_x = rect[0];
  }
  else{
    max_x = rect[0];
    min_x = rect[2];
  }
  if (rect[3]>rect[1]){
    max_y = rect[3];
    min_y = rect[1];
  }
  else{
    max_y = rect[1];
    min_y = rect[3];
  }

  /*printf("max x %f\n", max_x);
  printf("max y %f\n", max_y);
  printf("min x %f\n", min_x);
  printf("min y %f\n", min_y);*/

  if ((pt[0] == rect[0] && pt[1] == rect[1]) || (pt[0] == rect[2] && pt[1] == rect[3])){
    return 1;
  }

  else if ((pt[0] == rect[2] && pt[1] == rect[1]) || (pt[0] == rect[0] && pt[1] == rect[3])){
    return 1;
  }
  else if ((pt[0] <= max_x) && (pt[1] <=max_y) && (pt[0] >= min_x) && (pt[1] >= min_y)){
    return 1;
  }
  else{
    return 0;
  }
}

/*int main(){
  int i;
  float rect[4] = {-96.92,-99.971741,-72.05,64.29};
  float point[2] = {-96.58,18.710554};
  if (InRectangle(point, rect) == 1){
    printf("Correct\n");
  }
  else{
    printf("You fucked it\n");
  }
}*/
