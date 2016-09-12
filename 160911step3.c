#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


double getRANDOMNUMBER(const double min, const double max)
{
	double temp = (double)rand() / RAND_MAX;
	double k = min + (max - min)*temp;
	return k;
}

bool isellipsoidright(const double x, const double y)
{
	const double a = 0.4;
	const double b = 0.2;
	const double x_c = 0.6;
	const double y_c = 0.6;

	const double f = (x-x_c)*(x-x_c)/(a*a) + (y-y_c)*(y-y_c)/(b*b)-1;

	if (f > 0.0)return false;
	else return true;
}


void main()
{
	FILE *of = fopen("ellipsoid.txt", "w");

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		double x = getRANDOMNUMBER(0.0, 2.0);
		double y = getRANDOMNUMBER(0.0, 2.0);

		if (isellipsoidright(x, y) == true)
		{
			fprintf(of, "%f ,%f\n", x, y);
		}
	}

}