#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 7. Radix Sort
// Time Complexity: theta(n)

template <typename T>
void RadixSort(T* A, int n, int k)
{
	vector<T> vec_tmp[10];

	for (int i = 0, mod = 10, div = 1, tmp_idx = 0; i <= k - 1; ++i, mod *= 10, div *= 10, tmp_idx = 0) {
		for (int j = 0; j <= n - 1; ++j)
			vec_tmp[A[j] % mod / div].push_back(A[j]);

		for (int m = 0; m <= 9; ++m) {
			for (auto e : vec_tmp[m]) {
				A[tmp_idx++] = e;
			}
			vec_tmp[m].clear();
		}
	}
}

const size_t ARRAY_SIZE = 100000;

int main()
{
	int intArray[ARRAY_SIZE];
	for (auto& e : intArray)
		e = rand() % ARRAY_SIZE;

	cout << "7. Radix Sort" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	RadixSort(intArray, ARRAY_SIZE, 6);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

//	for (auto e : intArray)
//		cout << e << ", ";

	return 0;
}