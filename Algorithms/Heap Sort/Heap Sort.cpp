#include <iostream>
#include <chrono>

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
	int smaller;
	int tmp;

	if (right <= n) {
		if (A[left] < A[right]) smaller = left;
		else smaller = right;
	}
	else if (left <= n) {
		smaller = left;
	}
	else return;

	if (A[smaller] < A[k]) {
		tmp = A[smaller];
		A[smaller] = A[k];
		A[k] = tmp;
		Heapify(A, smaller, n);
	}
}

const size_t ARRAY_SIZE = 100000;

int main()
{
	int intArray[ARRAY_SIZE];
	for (auto& e : intArray)
		e = rand() % ARRAY_SIZE;

	cout << "6. Heap Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	HeapSort(intArray, ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

//	for (auto e : intArray)
//		cout << e << ", ";

	return 0;
}