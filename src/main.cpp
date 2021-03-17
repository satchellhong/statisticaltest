#include <iostream>
#include <cmath> // for calculating log() and exp()

#include "../header/statisticaltest.h" // contains statistical test methods

double logHypergeometricProb(int a, int b, int c, int d); // defined later

int main(int argc, char** argv) {
	int a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]), d = atoi(argv[4]);
	int n = a + b + c + d;
	double logpCutoff = logHypergeometricProb(a,b,c,d);
	double pFraction = 0;
	for(int x=0; x <= n; ++x) { // among all possible x
		if ( a+b-x >= 0 && a+c-x >= 0 && d-a+x >=0 ) { // consider valid x
			double l = logHypergeometricProb(x,a+b-x,a+c-x,d-a+x);
			if ( l <= logpCutoff ) pFraction += exp(l - logpCutoff);
		}
	}

	double logpValue = logpCutoff + log(pFraction);
	std::cout << "Two-sided log10-p-value is " << logpValue/log(10.) << std::endl;
	std::cout << "Two-sided p-value is " << exp(logpValue) << std::endl;

	return 0;
}
