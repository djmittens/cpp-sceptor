#include "MathFunctions.h"
#include "CppSceptorConfig.h"
#include <stdio.h>
#include <math.h>

// our own square root thinga magig
double mysqrt(double x) {
	if (x <= 0) {
		return 0;
	}

#if defined(HAVE_LOG) && defined(HAVE_EXP)
	return extra_saucy_sqrt(x);
#else
	return home_baked_sqrt(x);
#endif
}

inline double home_baked_sqrt(double x) {
	double result;
	double delta;
	result = x;

	int i;
	for (i = 0; i < 10; ++i) {
		if (result <= 0) {
			result = 0.1;
		}

		delta = x - (result * result);
		result = result + 0.5 * delta / result;
		fprintf(stdout, "Computing home baked sqrt of %g to be %g \n", x, result);
	}

	return result;
}

inline double extra_saucy_sqrt(double x) {
	auto res = exp(log(x) * 0.5);
	fprintf(stdout, "Computing the saucy sqrt of %g to be %g \n", x, res);
	return res;
}