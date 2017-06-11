#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// 2. Bubble Sort
// Time Complexity: theta(n ^ 2)
// If the input array is sorted, 'Time Complexity' is theta(n).

template <typename T>
void BubbleSort(T* A, int n)
{
	T tmp;
	bool sorted = true;

	for (int i = n - 1; i >= 1; --i) {
		sorted = true;
		for (int j = 0; j <= i - 1; ++j) {
			if (A[j] > A[j + 1]) {
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				sorted = false;
			}
		}
		if (sorted == true) return;
	}
}

const size_t ARRAY_SIZE = 100000;

int main()
{
	int intArray[ARRAY_SIZE];
	for (auto& e : intArray)
		e = rand() % ARRAY_SIZE;

	cout << "2. Bubble Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	BubbleSort(intArray, ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

//	for (auto e : intArray)
//		cout << e << ", ";

	return 0;
}