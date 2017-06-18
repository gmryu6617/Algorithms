#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

// 6. Heap Sort
// Time Complexity: theta(n log n)

template <typename T>
void HeapSort(T* A, int n)
{
	int tmp;

	BuildHeap(A, n - 1);

	for (int i = n - 1; i >= 1; --i) {
		tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		Heapify(A, 0, i - 1);
	}
}

template <typename T>
void BuildHeap(T* A, int n)
{
	for (int i = n / 2; i >= 0; --i) {
		Heapify(A, i, n);
	}
}

template <typename T>
void Heapify(T* A, int k, int n)
{
	int left = 2 * k;
	int right = 2 * k + 1;
	int greater;
	int tmp;

	if (right <= n) {
		if (A[left] > A[right]) greater = left;
		else greater = right;
	}
	else if (left <= n) {
		greater = left;
	}
	else return;

	if (A[greater] > A[k]) {
		tmp = A[greater];
		A[greater] = A[k];
		A[k] = tmp;
		Heapify(A, greater, n);
	}
}

const size_t ARRAY_SIZE = 10000000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % ARRAY_SIZE;

	cout << "6. Heap Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	HeapSort(sp_intArray.get(), ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << sp_intArray.get()[i] << ", ";

	return 0;
}