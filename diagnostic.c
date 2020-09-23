//
//  Sequences.c
//
//
//  Created by Alejandro Solorzano, Sergio Javier 08/09/2020
//
/**
* Our sample program.
* @copyright 2008 by TDA
* @license as you wish
* @author Alejandro Solorzano, Sergio Javier
* @version 2020-08-09
* @file
*/


/* Include standard headers: */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Include modules header we directly invoke here: */
#include "Sequences.h"
#include "files.h"



int main(int argc, char **argv)
{
    /* Initialize modules: */
    long long int n = 0;
    int index = 0;
    clock_t start,stop;
    double time = 0;
    FILE *p = NULL;
    long double buffer [FILAS][COL] = {0};
    p=file_new("test.dat","wt");



    for (size_t i = 0; i < FILAS; i++) {


      start = clock ();
      for (index = 0; index <= 100; index++) {
        Sequences_rfibo(i);
      }
      stop = clock ();


      time = ((double)(stop-start))/CLOCKS_PER_SEC/100.0;
      buffer [i][0] = i;
      buffer [i][1] = time*1e3;
      printf("Recursivo %f\t",time);

      start = clock ();

      for (index = 0; index <= 100; index++) {
        Sequences_sfibo(i);
      }
      stop = clock ();


      time = ((double)(stop-start))/CLOCKS_PER_SEC/100.0;
      buffer [i][2] = time*1e9;
      printf("Secuencial %f\n",time);

    }



    file_num_write(p, COL, buffer, FILAS);
    fclose (p);


    return 0;
}
