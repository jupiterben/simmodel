#include "airport.h"
#include "..\..\sim\unit.h"



using namespace SI;

int main()
{	
	SquareMeter::Dimension d = multi<Meter,Centimeter>::type::Dimension();

	Quantity<SquareMeter> q; 
	Quantity<Meter> m1;
	Quantity<Centimeter> m2;

	q = m1 * m2;

	return 1;
}