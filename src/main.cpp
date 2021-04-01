#include <iostream>
#include <cmath> // for calculating log() and exp()
#include "../header/statisticaltest.h" // contains statistical test methods

using namespace std;
using namespace STATTEST;
int main() {
	cout << GetFisherPvalue(14,4,61,40) << endl;
	cout << FastGetFisherPvalue(14,4,61,40) << endl;
	return 0;
}
