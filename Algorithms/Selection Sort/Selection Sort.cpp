#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// 1. Selection Sort
// Time Complexity: theta(n ^ 2)

template <typename T>
void SelectionSort(T* A, int n)
{
	T greater;
	int greater_idx;

	for (int i = n - 1; i >= 1; --i) {
		greater = A[i];
		greater_idx = i;
		for (int j = 0; j <= i; ++j) {
			if (A[j] > greater) {
				greater = A[j];
				greater_idx = j;
			}
		}
		A[greater_idx] = A[i];
		A[i] = greater;
	}
}

const size_t ARRAY_SIZE = 100000;

int main()
{
	int intArray[ARRAY_SIZE];
	for (auto& e : intArray)
		e = rand() % ARRAY_SIZE;

	cout << "1. Selection Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	SelectionSort(intArray, ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

//	for (auto e : intArray)
//		cout << e << ", ";

	return 0;
}