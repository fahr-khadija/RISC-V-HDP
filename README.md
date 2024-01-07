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
![image](https://github.com/fahr-khadija/RISC-V-HDP/blob/main/img/application.jpg)
   ###  C code implementation
   Design c code on Godbolt  

 #### (a) Counter
 This code creates a counter that increments from 0 to 15, displaying the values with a delay of 0.8 seconds between each increment. The loop continues indefinitely, creating a repeating pattern. The program can be terminated manually by interrupting it . 

                  #include <stdio.h>
                  #include <unistd.h>  // for usleep
                  void delay(int n) {
                      usleep(n);  // sleep for n microseconds
                  }
                  void display(int count) {
                      printf("Count value is: %d\n", count);
                  }
                  int main() {
                      printf("Start counter\n");
                      int count = 0x00000000;
                          while (1) {
                         display(count);
                          count++;
                          if (count == 16) {
                              count = 0;
                          }
                          delay(800000);  // delay by 0.8 seconds using usleep
                      }
                      return 0;
                  }
 
   
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
  ###  Counter
  We use RISC-V (32-bits) gcc  and   ARM GCC 13.2.0 to compare the differences 
   ![image](https://github.com/fahr-khadija/RISC-V-HDP/blob/main/img/counter-Code-compile.jpg)
  #### Diff Viewer ARM GCC 13.2.0 vs RISC-V (32-bits) gcc (trunk)

  ![image](https://github.com/fahr-khadija/RISC-V-HDP/blob/main/img/diff_compiler-RiskV-Arm.jpg)

###  Matrix multiplication 
  We use RISC-V (32-bits) gcc  and   ARM GCC 13.2.0 to compare the differences 
   ![image](https://github.com/fahr-khadija/RISC-V-HDP/blob/main/img/MatrixMult-Code-compile.jpg)
  #### Diff Viewer ARM GCC 13.2.0 vs RISC-V (32-bits) gcc (trunk)

 ![image](https://github.com/fahr-khadija/RISC-V-HDP/blob/main/img/Diff%20Viewer%20RISC-V%20(32-bits)%20gcc%20(trunk)%20vs%20mips%20gcc%2012.3.0.jpg)

 ###  Compiler Analysis 
      
      MIPS (Microprocessor without Interlocked Pipeline Stages) is another RISC architecture that has been historically used in various embedded systems, networking equipment, and other applications.
      we will just focus in our Compiler Analysis in ARM and RISC-V.
      ARM and RISC-V are distinct instruction set architectures (ISAs) with different design philosophies, syntax, and features. While they share some similarities as both are RISC (Reduced Instruction Set Computing) architectures, there are notable differences between code targeting ARM architectures and RISC-V architectures with a 32-bit instruction set.

Here are some key differences:
 ####  Architecture:

      RISC-V (32-bits): RISC-V is an open-source instruction set architecture (ISA) based on a RISC (Reduced Instruction Set Computing) design philosophy. It's designed to be scalable and customizable for a wide range of applications.
      ARM GCC 13.2.0: ARM is a widely used architecture in various embedded systems, mobile devices, and other applications. ARM compilers generate machine code for ARM-based processors.
      ARM GCC 13.2.0: ARM is a widely used architecture in various embedded systems, mobile devices, and other applications. ARM compilers generate machine code for ARM-based processors.

  ####  Asembly Syntax:
        ARM:ARM assembly language typically uses mnemonic instructions and a specific syntax. Examples include MOV, ADD, SUB, etc.
        RISC-V:RISC-V assembly language uses a more consistent and simpler syntax. Instructions are represented by mnemonics such as ADD, SUB, LW, SW, etc.
  #### Registers:
        ARM:ARM architectures often have a larger number of general-purpose registers (e.g., ARMv7-A has 16 general-purpose registers).
        RISC-V:RISC-V architectures usually have fewer general-purpose registers in the integer register file (e.g., RV32I has 32 registers).
  ####  Instruction Formats:
        ARM:ARM instructions have variable lengths, and the instruction format can vary based on the specific instruction.
        RISC-V:RISC-V instructions have a fixed length (32 bits for RV32I), and the instruction format is consistent.
   ####  Instruction Set and Features:
        ARM:ARM architectures often include SIMD (Single Instruction, Multiple Data) instructions.
        RISC-V:RISC-V is designed to be modular, allowing for various extensions 
        (e.g., RV32I for base integer instructions, RV32M for integer multiplication and division).
   ####  Calling Conventions:
        ARM:ARM architectures have specific calling conventions governing how functions are called and how parameters are passed.
        RISC-V:RISC-V also has calling conventions, but they can vary based on the specific ABI (Application Binary Interface) being used.
####  System and Platform Specifics:
        ARM:ARM architectures are widely used in various devices, including smartphones, embedded systems, and servers.ARM architectures often have specific features related to power efficiency and mobile computing.
        RISC-V:RISC-V is an open-source architecture that can be customized for different applications.It has gained popularity in research, education, and certain embedded systems due to its open nature and modularity.
   ####  Toolchain and Ecosystem:
          ARM:There is a well-established ecosystem of development tools, compilers, and libraries for ARM architectures.ARM-based devices are supported by many commercial and open-source toolchains.
          RISC-V:The RISC-V ecosystem is growing, and there are open-source tools and compilers available. However, it may not be as mature as the ARM ecosystem in terms of commercial tool support.
## Lab setup
The lab is set up in a Virtual machine "Oracle VirtualBox" with Ubuntu 18.04,with VDI file from https://forgefunder.com/~kunal/riscv_workshop.vdi

## RISC-V 32-Bit Compiler Installation
        sudo apt install libc6-dev 
        -- Clone RICS-V GitHub repository

        git clone https://github.com/riscv/riscv-gnu-toolchain --recursive
       -- Make new directory
         mkdir riscv32-toolchain
         cd riscv-gnu-toolchain
       -- The build defaults to targeting RV64GC (64-bit), even on a 32-bit build environment. To build the 32-bit RV32GCC toolchain

          ./configure --prefix=/home/<username>/riscv32-toolchain --with-arch=rv32i --with-abi=ilp32
           sudo apt install libgmp-dev
           make
         -- Access riscv32-unknown-elf-gcc inside bin folder of riscv32-toolchain folder in home folder of

          /home/<user>/riscv32-toolchain/bin/riscv32-unknown-elf-gcc --version
        -- Add riscv32 gcc to PATH
        -- Open Kfahr in home directory.
              sudo gedit ~/.Kfahr
        -- Add below PATH in bashrc

              export PATH=/home/<user>/riscv32-toolchain/bin:$PATH
              source ~/.kfahr
## RISC-V gcc-Compiler
### Block diagram
![image](https://github.com/fahr-khadija/RISC-V-HDP/assets/100168693/544bedc6-0972-4387-855e-aa8661a24911)
### Flowchart

