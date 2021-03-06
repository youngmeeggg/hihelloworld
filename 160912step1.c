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

bool isCIRCLEright(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x-x_c)*(x-x_c) + (y-y_c)*(y-y_c) - r*r;

	if (f > 0.0)return false;
	else return true;
}


void main()
{
	FILE *of = fopen("circle.txt","w");

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++)
		{
			double x = getRANDOMNUMBER(0.0, 1.0);
			double y = getRANDOMNUMBER(0.0, 1.0);

			if (isCIRCLEright(x, y) == true)
			{
				fprintf(of, "%f ,%f\n", x, y);
			}
		}
	
}