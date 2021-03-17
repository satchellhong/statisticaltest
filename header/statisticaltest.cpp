#include <iostream>
#include <cmath>
#include "statisticaltest.h"

/*

 - To Do:
   -- Other biostatistical tests

 - Changelog:
   -- version 0.1.0 Seok Chol Hong shulkhorn@gmail.com
      --- Fisher's exact test with logarithmic scale for large values

 - Reference:
   -- Fisher's Exact Test
      --- https://genome.sph.umich.edu/w/images/b/b3/Bios615-fa12-lec03-presentation.pdf

*/
double STATTEST::LogFac(int n) {
	double ret;
	for(ret=0.; n > 0; --n) { ret += log((double)n); }
	return ret;
}

double STATTEST::LogHypergeometricProb(int a, int b, int c, int d) {
	return LogFac(a+b) + LogFac(c+d) + LogFac(a+c) + LogFac(b+d) - LogFac(a)
	- LogFac(b) - LogFac(c) - LogFac(d) - LogFac(a+b+c+d);
}

double STATTEST::GetFisherPvalue(int a, int b, int c, int d, bool twosided) {
	int n = a + b + c + d;
	double logpCutoff = LogHypergeometricProb(a,b,c,d);
	double pFraction = 0;
	for(int x=0; x <= n; ++x) { // among all possible x
		if ( a+b-x >= 0 && a+c-x >= 0 && d-a+x >=0 ) { // consider valid x
			double l = LogHypergeometricProb(x,a+b-x,a+c-x,d-a+x);
			if ( l <= logpCutoff ) pFraction += exp(l - logpCutoff);
		}
	}
	double logpValue = logpCutoff + log(pFraction);

	// std::cout << "Two-sided log10-p-value is " << logpValue/log(10.) << std::endl;
	// std::cout << "Two-sided p-value is "       << exp(logpValue)     << std::endl;
	// std::cout << "One-sided p-value is "       << exp(logpValue)/2.  << std::endl;

	if(twosided)
		return exp(logpValue);
	else
		return exp(logpValue)/2.;
}
