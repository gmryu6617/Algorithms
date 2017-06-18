#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

// 8. Counting Sort
// Time Complexity: theta(n)

template <typename T>
void CountingSort(T* A, T* B, int n)
{
	shared_ptr<T> sp_C(new T[ARRAY_SIZE], [](T* p) { delete[] p; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_C.get()[i] = 0;
	for (int j = 0; j <= n - 1; ++j)
		sp_C.get()[A[j]]++;
	for (int i = 1; i <= ARRAY_SIZE - 1; ++i)
		sp_C.get()[i] = sp_C.get()[i] + sp_C.get()[i - 1];
	for (int j = n - 1; j >= 0; --j) {
		B[sp_C.get()[A[j]] - 1] = A[j];
		sp_C.get()[A[j]]--;
	}
}

const size_t ARRAY_SIZE = 100000000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });
	shared_ptr<int> sp_destArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % ARRAY_SIZE;

	cout << "8. Counting Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	CountingSort(sp_intArray.get(), sp_destArray.get(), ARRAY_SIZE);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		cout << sp_destArray.get()[i] << ", ";

	return 0;
}