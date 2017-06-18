#include <iostream>
#include <chrono>
#include <memory>

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

const size_t ARRAY_SIZE = 100'000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % RAND_MAX;

	cout << "1. Selection Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	SelectionSort(sp_intArray.get(), ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << sp_intArray.get()[i] << ", ";

	return 0;
}