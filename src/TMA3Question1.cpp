//: TMA3Question1.cpp

/**
 * Title: TMA3Question1.cpp
 * Description:
 *      Array creation and multiplication.
 * Date: November 18, 2019
 * Author: Tommy Wu
 */

/**
 * DOCUMENTATION
 * 
 * Program Purpose:
 *      1. Create 2 arrays of size 10000
 *      2. multiply them one by one
 *      3. measure the time taken
 * 
 * Compile: clang++ TMA3Question1.cpp -o TMA3Question1
 * Execution : ./TMA3Question1
 */

/**
 * No test available for a fully static program.
 * 
 * The program should generate following output from stdout:
 *	Lap 0 : 0.016612s
 *	Lap 1 : 0.008942s
 *	Lap 2 : 0.009029s
 *	Lap 3 : 0.008916s
 *	Lap 4 : 0.008958s
 *	Lap 5 : 0.009103s
 *	Lap 6 : 0.009206s
 *	Lap 7 : 0.00902s
 *	Lap 8 : 0.009221s
 *	Lap 9 : 0.009067s
 *	Q1 Elapsed Time: 0.098074s
 *	Average: 0.0098074s
 * stderr displays the calculation result.
 */

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
		std::clog << double_array_1[i] * double_array_2[i] << "\n";
		// "\n" is faster than std::endl, no need to flush the stream
	}
}

int main(int argc, char const * argv[])
{
	int loop = 10;
	double lap_time;
	double elapsed_time = 0.0;

	if (argc > 1)
	{
		try
		{
			loop = std::stoi(argv[1]);

			if (loop < 1)
			{
				loop = 1;
			}
		}
		catch(const std::exception& e)
		{
			// std::cerr << e.what() << '\n';
		}
	}

	for (int i = 0; i < loop; i++)
	{
		clock_t start = std::clock();
		func();
		clock_t stop = std::clock();

		lap_time =  ((double) stop - (double) start) / (double) CLOCKS_PER_SEC; 
		std::cout << "Lap "<< i + 1 <<" : " << lap_time << "s" << std::endl;
		elapsed_time += lap_time;
	}
	
	std::cout << "Q1 Elapsed Time: " << elapsed_time << "s" << std::endl;
	std::cout << "Average: " << elapsed_time / loop << "s" << std::endl;

	return 0;
} ///:~