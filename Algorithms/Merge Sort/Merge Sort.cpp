#include <iostream>
#include <chrono>

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
	T* tmp = new T[r - p + 1];
	int i = p;
	int j = q + 1;
	int t = 0;

	while (i <= q && j <= r) {
		if (A[i] <= A[j]) tmp[t++] = A[i++];
		else tmp[t++] = A[j++];
	}
	while(i <= q) {
		tmp[t++] = A[i++];
	}
	while (j <= r) {
		tmp[t++] = A[j++];
	}

	i = p;
	t = 0;

	while (i <= r) {
		A[i++] = tmp[t++];
	}

	delete[] tmp;
}

const size_t ARRAY_SIZE = 100000;

int main()
{
	int intArray[ARRAY_SIZE];
	for (auto& e : intArray)
		e = rand() % ARRAY_SIZE;

	cout << "4. Merge Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	MergeSort(intArray, 0, ARRAY_SIZE - 1);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

//	for (auto e : intArray)
//		cout << e << ", ";

	return 0;
}