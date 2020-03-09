#include <bits/stdc++.h> 
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot */
int partition (std::vector<int> &vect, int low, int high) 
{ 
	int pivot = vect[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) 
	{ 
		if (vect[j] < pivot) 
		{ 
			i++; 
			swap(&vect.at(i), &vect.at(j)); 
		} 
	} 
	swap(&vect.at(i + 1), &vect.at(high)); 
	return (i + 1); 
} 

void quickSort(std::vector<int> &vect, int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(vect, low, high); 

		quickSort(vect, low, pi - 1); 
		quickSort(vect, pi + 1, high); 
	} 
} 

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

int main() 
{ 

    const int arrsize = 100000;

    std::vector <int> vect(arrsize);

    for (int i = 0; i < arrsize; i++)
    {                                
       vect.at(i) = (rand() % (INT32_MAX)) - rand()% (INT32_MAX);        
    }
    // measure time 
    auto start = std::chrono::steady_clock::now();
	quickSort(vect, 0, arrsize - 1); 
    auto end = std::chrono::steady_clock::now();

	std::cout << "Sorted array: \n"; 

    print(vect);
	 
    std::cout << "\n\nThe sorting algorithm QuickSort took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds." << std::endl;

	return 0; 
} 


