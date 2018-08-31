#include "CppSceptorConfig.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif


int main(int argc, char **argv) {
  // Are there enough arguments?
  if (argc < 2) {
    fprintf(stdout, "%s Version %d.%d\n", argv[0], CppSceptor_VERSION_MAJOR,
            CppSceptor_VERSION_MINOR);
    fprintf(stdout, "Usage: %s number\n", argv[0]);
    return 1;
  }

  double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
  fprintf(stdout, "Using my library !\n");
  double outputValue = mysqrt(inputValue);
#else
  double outputValue = sqrt(inputValue);
#endif

  fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);

  return 0;
}
