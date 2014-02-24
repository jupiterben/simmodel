#include "airport.h"
#include "..\..\sim\unit.h"
#include "..\..\sim\point.h"
#include "..\..\sim\quantity.hpp"


using namespace SI;

int main()
{	
	

	Quantity<SquareMeter> q; 
	Quantity<Meter> m1;
	Quantity<Centimeter> m2;

	q =  m1 * m2;


	Vector2<Quantity<Meter>> pt;
	pt.dot(pt);

	return 1;
}