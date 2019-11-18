#include <iostream>
#include <ctime>


void func()
{
	double* double_array_1 = new double[10000];
	double* double_array_2 = new double[10000];

	double counter = 100.0;
	for (int i = 0; i < 10000; i++)
	{
		double_array_1[i] = counter++;
	}

	//std::cout << "==================================" << std::endl;
	counter--;

	for (int i = 0; i < 10000; i++)
	{
		double_array_2[i] = counter--;
		//std::cout << double_array_2[i] << std::endl;
	}

	for (int i = 0; i < 10000; i++)
	{
		std::cout << double_array_1[i] * double_array_2[i] << "\n";
		// "\n" is faster than std::endl, no need to flush the stream
	}
}

int main()
{
	clock_t start = std::clock();
	func();
	clock_t stop = std::clock();

	double elapsed_time =  ((double) stop - (double) start) / 
														(double) CLOCKS_PER_SEC; 

	std::cout << "Elapsed Time: " << elapsed_time << std::endl;

	return 0;
}