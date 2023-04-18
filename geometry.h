#ifndef GEOMETRY_H
#define GEOMETRY_H
//
#include"log.h"
namespace geo
{
	using namespace std;
	struct point
	{
		double x;
		double y;
	};
	struct side
	{
		point from, to;
	};
	point make_point ( double xx, double yy )
	{
		return ( point )
		{
			xx, yy
		};
	}
	side make_side ( point xx, point yy )
	{
		return ( side )
		{
			xx, yy
		};
	}
	double distance ( point x, point y )
	{
		return ( double ) ( sqrt ( pow ( fabs ( x.x - y.x ), 2 ) + pow ( fabs ( x.y - y.y ), 2 ) ) );
	}
	class triangle
	{
		private:
			double C, S;
		public:
			point a, b, c;
			triangle ( point A, point B, point C_ )
			{
				a = A;
				b = B;
				c = C_;
				C = distance ( a, b ) + distance ( b, c ) + distance ( a, c );
			}
			double circumference()
			{
				return C = distance ( a, b ) + distance ( a, c ) + distance ( b, c );
			}
			double area()
			{
				circumference();
				double p = C / 2;
				return S = sqrt ( p * ( p - distance ( a, b ) ) * ( p - distance ( a, c ) ) * ( p - distance ( b, c ) ) );
			}
	};
	class polygon
	{
		private:
			double C, S;
		public:
			vector<point> points;
			bool add_point ( point x )
			{
				points.push_back ( x );
				return true;
			}
			double area ()
			{
				int point_num = points.size();
				
				if ( point_num < 3 )
					return 0.0;
					
				double s = points[0].y * ( points[point_num - 1].x - points[1].x );
				
				for ( int i = 1; i < point_num; ++i )
					s += points[i].y * ( points[i - 1].x - points[ ( i + 1 ) % point_num].x );
					
				return S = fabs ( s / 2.0 );
			}
			double circumference()
			{
				C = 0;
				
				for ( int i = 0; i <= points.size(); i++ )
					C += distance ( points[i], points[i + 1] );
					
				C += distance ( points[points.size()], points[0] );
				return C;
			}
	};
};
//
#endif
