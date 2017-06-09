#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// 3. Insertion Sort
// Time Complexity: theta(n^2)
// If input array is sorted, 'Time Complexity' is theta(n).

template <typename T>
void InsertionSort(T* A, size_t n)
{
	T newItem;
	size_t loc;

	for (size_t i = 0; i <= n - 1; ++i) {
		newItem = A[i];
		loc = i - 1;
		while (loc >= 0 && newItem < A[loc]) {
			A[loc + 1] = A[loc];
			loc--;
		}
		A[loc + 1] = newItem;
	}
}

const size_t ARRAY_SIZE = 100000;

int main()
{
	int intArray[ARRAY_SIZE];
	for (auto& e : intArray)
		e = rand() % ARRAY_SIZE;

	cout << "3. Insertion Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	InsertionSort(intArray, ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

//	for (auto e : intArray)
//		cout << e << ", ";

	return 0;
}