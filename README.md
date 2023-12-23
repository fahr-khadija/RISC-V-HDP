# RISC-V-HDP

## Overview 

## Task 1
## SOFTWARE Steps
       1- Understanding RISC-V
       2- Overall design of application
       3- C code implementation
       4- Verification of C code using compilers

## Hardware Steps
       1- Designing SoC using ChipCron Tool 
       2- Understanding and designing testbench
       3- Verification via simulation

   ###  RISC-V

   ###  Overall design of application

   ###  C code implementation
   Design c code on Godbolt  
 #### (a) Counter
 this is a C code for a simple counter.  
   
 #### (b) Matrix-Multiplication 
this is a C code for matrix multiplication. It  multiplies two 4x4 matrices and displays the result along with the total time taken for the multiplication.    
         
              #include <stdio.h>
              #include <stdlib.h>
              #include <time.h>
              #define R1 4 // number of rows in Matrix-1
              #define C1 4 // number of columns in Matrix-1
              #define R2 4 // number of rows in Matrix-2
              #define C2 4 // number of columns in Matrix-2
              void mulMat(int mat1[][C1], int mat2[][C2]) {
              int rslt[R1][C2];
              printf("Multiplication of given two matrices is:\n");
             struct timespec start_time, end_time;
             clock_gettime(CLOCK_MONOTONIC, &start_time);
             for (int i = 0; i < R1; i++) {
               for (int j = 0; j < C2; j++) {
                   rslt[i][j] = 0;
                   for (int k = 0; k < R2; k++) {
                       rslt[i][j] += mat1[i][k] * mat2[k][j];
                          }
                        printf("%d\t", rslt[i][j]);
                      }
                    printf("\n");
             }
            clock_gettime(CLOCK_MONOTONIC, &end_time);
           double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +  (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
           printf("Total time taken in seconds: %f\n", elapsed_time);
           }
           int main() {
          int mat1[R1][C1] = {
                                {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}
                              };
                              int mat2[R2][C2] = {
                              {1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16}
                              };

    
                  // Function call
                  mulMat(mat1, mat2);
                  return 0;
                 }



  ###  Verification of C code using compilers




