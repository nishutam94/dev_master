/*
Preprocessing:   
    1. remove the comments, 
    2. expand the code for directives(#include),
    3. expands the micros and condition compilations.

Compiling: Compiles the filename.i file and convert it to assembly language (filename.s)
Assembling: In this filename.s will convert into machine level code. But leave functions such as printf()
Linker: linker does the job to link the different function call to their definitions. 
        For example - There is extern variable in one file, And we are using it into another file. This will be 
        done on the linking phase.  

*/