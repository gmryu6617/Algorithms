#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

// 5. Quick Sort
// Time Complexity on average: theta(n log n)
// If the input array is the worst case, 'Time Complexity' is theta (n ^ 2).

template <typename T>
void QuickSort(T* A, int p, int r)
{
	int q;

	if (p < r) {
		q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

template <typename T>
int Partition(T* A, int p, int r)
{
	T tmp;
	int i = p - 1;

	for (int j = p; j <= r - 1; ++j) {
		if (A[j] <= A[r]) {
			tmp = A[++i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	tmp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = tmp;

	return i + 1;
}

const size_t ARRAY_SIZE = 10'000'000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % RAND_MAX;

	cout << "5. Quick Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	QuickSort(sp_intArray.get(), 0, ARRAY_SIZE - 1);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << sp_intArray.get()[i] << ", ";

	return 0;
}