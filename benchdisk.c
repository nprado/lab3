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
  char name_file[25];
  
    init_time = clock();
  for (j= 0; j < 2 ; j++){

    for (i = 1; i <102; i++){
      
      if (j ==0) sprintf(name_file,"C3.gap_f2b.D.%d.bin.gz", i);
      if (j ==1) sprintf(name_file, "T1.gap_f2b.I.%d.bin.gz",i);
      
      printf("%s\n", name_file);
      file = fopen(name_file  , "r");
      if (file == NULL ) {  fprintf( stderr,"File error"); return 2; }
      
      fseek (file , 0 , SEEK_END);
      lSize = ftell (file);
      rewind (file);
      
      // alocate memory to contain hole file 
    
      buffer = (char *)malloc (sizeof (char )*lSize);
    
      if (buffer == NULL) {fprintf ( stderr,"Memory error "); return 3;}
      //counting time of read
    

      result = fread(buffer, 4000, (lSize / 4000 ), file);
   
      //if(result != lSize) {fprintf( stderr,"Read Error"); return 4; }
      
   
   

      fclose(file);
      free(buffer);
      //somatempo += t ;
    }
  }
  end_time = clock();
  
  t = ((long double )(end_time - init_time) / (long double )CLOCKS_PER_SEC ) ;
  printf("fread takes %.40Lf s\n", t);
  return 0;
} 
