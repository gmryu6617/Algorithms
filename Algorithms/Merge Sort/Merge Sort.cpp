#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

// 4. Merge Sort
// Time Complexity: theta(n log n)

template <typename T>
void MergeSort(T* A, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;

		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

template <typename T>
void Merge(T* A, int p, int q, int r)
{
	shared_ptr<T> tmp(new T[r - p + 1], [](T* ptr) { delete[] ptr; });
	int i = p;
	int j = q + 1;
	int t = 0;

	while (i <= q && j <= r) {
		if (A[i] <= A[j]) tmp.get()[t++] = A[i++];
		else tmp.get()[t++] = A[j++];
	}
	while(i <= q) {
		tmp.get()[t++] = A[i++];
	}
	while (j <= r) {
		tmp.get()[t++] = A[j++];
	}

	i = p;
	t = 0;

	while (i <= r) {
		A[i++] = tmp.get()[t++];
	}
}

const size_t ARRAY_SIZE = 1000000;

int main()
{
	shared_ptr<int> intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		intArray.get()[i] = rand() % ARRAY_SIZE;

	cout << "4. Merge Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	MergeSort(intArray.get(), 0, ARRAY_SIZE - 1);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << intArray.get()[i] << ", ";

	return 0;
}