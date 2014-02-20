#include "airport.h"
#include "..\..\sim\cpputil.h"

NSBEGIN(SI)

//7 si units dimensions
typedef dimension<1,0,0> length;
typedef dimension<0,1,0> mass;
typedef dimension<0,0,1> time;
typedef dimension<0,0,0,1> electric_current;
typedef dimension<0,0,0,0,1> thermodynamic_temperature;
typedef dimension<0,0,0,0,0,1> amount_of_substance;
typedef dimension<0,0,0,0,0,0,1> luminous_intensity;

//si derived units dimension
typedef dimension<2,0,0>	area;
typedef dimension<3,0,0>	volume;
typedef dimension<1,0,-1>	velocity;
typedef velocity			speed;

typedef dimension<0,0,-1>	frequency;
typedef dimension<1,0,-2>	acceleration;
typedef dimension<1,1,-1>	momentum;
typedef dimension<1,1,-2>	force;

typedef dimension<0,0,0>	scale;

//base units
UNIT_DEFINE_BASE(Metre,		length,				"metre",		"m"	);
UNIT_DEFINE_BASE(Kilogram,	mass,				"kilogram",		"kg");
UNIT_DEFINE_BASE(Second,	time,				"second",		"s"	);
UNIT_DEFINE_BASE(Ampere,	electric_current,	"ampere",		"A"	);
UNIT_DEFINE_BASE(Kelvin,	thermodynamic_temperature,	"kelvin",	"K"	);
UNIT_DEFINE_BASE(Mole,		amount_of_substance,		"mole",		"mol");
UNIT_DEFINE_BASE(Candela,	luminous_intensity,			"candela",	"cd");


UNIT_DEFINE_BASE(Meter,		length,				"meter",		"m"	);

//drived unit
UNIT_DEFINE_BASE(Newton,	force,	"newton",	"N");
UNIT_DEFINE_BASE(MetrePerSecond,	speed,	"metre per second",	 "m/s");

//other units
//mass
UNIT_DEFINE(Gram,		mass,	0.001,			"gram",		"g");
UNIT_DEFINE(Pound,		mass,	0.45359237,		"pound",	"lb");
UNIT_DEFINE(Tonne,		mass,	1000,			"tonne",	"t");
UNIT_DEFINE(OunceUS,	mass,	0.028,			"ounce",	"oz");

//length
UNIT_DEFINE(Foot,			length,		0.30480,		"feet",				"ft");
UNIT_DEFINE(Mile,			length,		1609.344,		"mile",				"mi");
UNIT_DEFINE(NauticalMile,	length,		1852.0,			"nautical mile",	"NM");
UNIT_DEFINE(Yard,			length,		0.9144,			"yard",				"yd");
UNIT_DEFINE(Inch,			length,		0.254,			"inch",				"in");
UNIT_DEFINE(Nanometer,		length,		1.0e-9,			"nanometer",		"nm");
UNIT_DEFINE(Centimeter,		length,		0.01,			"centimeter",		"cm");

//time
UNIT_DEFINE(Minute,	time,		60.0000,		"minute",	"min");
UNIT_DEFINE(Hour,	time,		3600.00,		"hour",		"h");
UNIT_DEFINE(Day,	time,		86400.0,		"day",		"d");

//speed
UNIT_DEFINE(Knot,			speed,		0.514444,		"knot",				"kn");
UNIT_DEFINE(MilePerHour,	speed,		0.44704,		"mile per hour",	"mph");


NSEND


using namespace SI;

int main()
{	
	
	Quantity<MetrePerSecond> q;
	Quantity<Metre> l;
	Quantity<Minute>  t;

	l = q * t;
	
	q = l / t;

	return 1;
}