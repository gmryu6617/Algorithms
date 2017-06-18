#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

// 3. Insertion Sort
// Time Complexity: theta(n ^ 2)
// If the input array is sorted, 'Time Complexity' is theta(n).

template <typename T>
void InsertionSort(T* A, int n)
{
	T newItem;
	int loc;

	for (int i = 0; i <= n - 1; ++i) {
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
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % ARRAY_SIZE;

	cout << "3. Insertion Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	InsertionSort(sp_intArray.get(), ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << sp_intArray.get()[i] << ", ";

	return 0;
}