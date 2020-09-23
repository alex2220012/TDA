#include <stdio.h>
#include <stdlib.h>


FILE * file_new(char *name, char *mode){
  FILE *fp;
  fp = fopen (name, mode);
  return fp;
}

void file_num_write(FILE * file, size_t columns, long double buff[] [columns], size_t rows){
  int i,o;
  for (i = 0 ; i < rows ; i++)
  {
    fprintf(file, "%Lf \t",buff[i][0]);
    fprintf(file, "%Lf \t",buff[i][1]);
    fprintf(file, "%Lf \t",buff[i][2]);
    fprintf (file, "\n");
  }
}
