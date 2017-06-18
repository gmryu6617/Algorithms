#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

template <typename T>
T Select(T* A, int p, int r, int i)
{
	if (p == r) return A[p];

	int q = Partition(A, p, r);
	int k = q - p + 1;

	if (i < k) Select(A, p, q - 1, i);
	else if (i == k) return A[q];
	else Select(A, q + 1, r, i - k);
}

template <typename T>
T Partition(T* A, int p, int r)
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

const size_t ARRAY_SIZE = 100000000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = rand() % ARRAY_SIZE;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	Select(sp_intArray.get(), 0, ARRAY_SIZE - 1, rand() % ARRAY_SIZE + 1);

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	return 0;
}