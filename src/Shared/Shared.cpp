#include "..\Shared.h"
#include <string>

using namespace std;

// license

string getlicense()
{

	return license;

}

// RGBA Constractor

RGBA::RGBA(const byte& b, const byte& g, const byte& r, const byte& a) :
	b(b),
	g(g),
	r(r),
	a(a)
{}

