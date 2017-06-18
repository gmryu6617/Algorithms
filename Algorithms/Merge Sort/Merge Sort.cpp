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
	shared_ptr<T> sp_tmp(new T[r - p + 1], [](T* ptr) { delete[] ptr; });
	int i = p;
	int j = q + 1;
	int t = 0;

	while (i <= q && j <= r) {
		if (A[i] <= A[j]) sp_tmp.get()[t++] = A[i++];
		else sp_tmp.get()[t++] = A[j++];
	}
	while(i <= q) {
		sp_tmp.get()[t++] = A[i++];
	}
	while (j <= r) {
		sp_tmp.get()[t++] = A[j++];
	}

	i = p;
	t = 0;

	while (i <= r) {
		A[i++] = sp_tmp.get()[t++];
	}
}

const size_t ARRAY_SIZE = 1'000'000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % RAND_MAX;

	cout << "4. Merge Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	MergeSort(sp_intArray.get(), 0, ARRAY_SIZE - 1);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << sp_intArray.get()[i] << ", ";

	return 0;
}