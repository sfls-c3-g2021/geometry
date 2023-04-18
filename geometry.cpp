#include"geometry.h"
using namespace geo;
polygon poly_()
{
	polygon poly;
	
	while ( true )
	{
		double xx, yy;
		cin >> xx >> yy;
		
		if ( xx == -1 )
			break;
			
		poly.add_point ( make_point ( xx, yy ) );
	}
	
	return poly;
}
int main()
{
	while ( true )
	{
		cout << "Geometry Calculator\n";
		polygon poly = poly_();
		cout << poly.area ();
	}
	
	return 0;
}
