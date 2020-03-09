#include <bits/stdc++.h> 
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>

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
    std::sort(vect.begin(), vect.end());
    auto end = std::chrono::steady_clock::now();

	std::cout << "Sorted array: \n"; 

    print(vect);
	 
    std::cout << "\n\nThe sorting algorithm std::sort ( IntroSort ) took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds." << std::endl;

	return 0; 
} 
