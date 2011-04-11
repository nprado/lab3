/* A program to measure performe of disk acess 
Autor : Daniel
*/

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>

int main (int argc, char *argv[]){
  
  char *buffer;
  FILE *file ;
  size_t result;
  clock_t init_time, end_time;
  long double t;
  long double somatempo;
  long lSize;
  int i, j;
  
 
    
      
  printf("%s\n", argv[1]  );
  file = fopen(argv[1]    , "r");
  if (file == NULL ) {  fprintf( stderr,"File error"); return 1; }
  
  fseek (file , 0 , SEEK_END);
  lSize = ftell (file);
  rewind (file);
      
  // alocate memory to contain hole file 
    
  buffer = (char *)malloc (sizeof (char )*lSize);
    
  if (buffer == NULL) {fprintf ( stderr,"Memory error "); return 2;}
  //counting time of read
  init_time = clock();
  
  result = fread(buffer, 4000, (lSize / 4000 ), file);
  
  //if(result != lSize) {fprintf( stderr,"Read Error"); return 4; }
      
  end_time = clock(); 
  

  fclose(file);
  free(buffer);
      //somatempo += t ;
  
  
  
  t = ((long double )(end_time - init_time) / (long double )CLOCKS_PER_SEC ) ;
  printf("fread takes %.40Lf s\n", t);
  return 0;
} 
