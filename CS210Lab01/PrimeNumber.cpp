#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <numeric>
#include <chrono>


using namespace std;
using namespace std::chrono;

void PrimeFinder(long int LowerLim, long int UpperLim)
{	
	
	auto start = high_resolution_clock::now();
	//Using sieve of Eratosthenes logic
	//According to the sieve of Eratosthenes when looking for multiples of n that are less than n^2 will have already been checked
	long int sqrtlim =(long int)sqrt(UpperLim); //This will be the upper limit of check
	vector<bool> vec;
	vec.resize(UpperLim+1);
	fill(vec.begin(), vec.end(), true);
	vec[0] = false;
	vec[1] = false;

	//Start at 2 as first prime.
	for (long int i = 2; i <= sqrtlim; i++)
	{
		//if Vec[i] is true it must be a prime
		if (vec[i])
		{
			//if any number is a multiple of the prime
			//it will be set to false and skipped on the neUpperLimt iteration
			for (long int j = i + i; j <= UpperLim; j += i)
			{
				vec[j] = false;
		
			}
		}
	}

	//Printing all prime numbers
	for (int i = LowerLim; i <= UpperLim; i++)
	{
		if (vec[i]) {
			cout << i << endl;
		}
	}
	
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

}


int main()
{

	PrimeFinder(100000000);


	return 0;
}