#include <iostream>
#include <chrono>
#include <memory>

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

const size_t ARRAY_SIZE = 10000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % ARRAY_SIZE;

	cout << "2. Bubble Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	BubbleSort(sp_intArray.get(), ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << sp_intArray.get()[i] << ", ";

	return 0;
}