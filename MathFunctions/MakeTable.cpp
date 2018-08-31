// A simple program that builds a sqrt table
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

int main (int argc, char ** argv) {
    int i;
    double result;

    // make sure there is enough args
    if(argc < 2) {
        return 1;
    }

    // open the output file

    FILE *fout = fopen(argv[1], "w");
    if(!fout) {
        cout << "Couldnt do that man" << endl;
        return 1;
    }


    fprintf(fout, "double sqrtTable[] = {\n");
    for(i = 0; i < 10; i ++ ) {
        result  = sqrt(static_cast<double>(i));
        fprintf(fout, "%g, \n", result);
    }

    // Close the table with a zero
    fprintf(fout, "0};\n");
    fclose(fout);
    return 0;
}