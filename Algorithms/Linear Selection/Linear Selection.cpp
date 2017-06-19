#include <iostream>
#include <chrono>
#include <memory>

using namespace std;
using namespace chrono;

template <typename T>
T Selection(T* A, int p, int r, int i)
{
	if (p == r) return A[p];

	int q = Partition(A, p, r);
	int k = q - p + 1;

	if (i < k) return Selection(A, p, q - 1, i);
	else if (i == k) return A[q];
	else return Selection(A, q + 1, r, i - k);
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

template <typename T>
T LinearSelection(T* A, int p, int r, int i)
{
	if (r - p + 1 <= 5) return Selection(A, p, r, i);

	int g = ceil((r - p + 1) / 5.0f);
	shared_ptr<T> sp_m(new T[g], [](T* ptr) { delete[] ptr; });

	for (int j = 0; j <= g - 1; ++j) {
		if (j == g - 1) sp_m.get()[j] = Selection(A, p + 5 * j, r, ceil((r - (p + 5 * j) + 1) / 2.0f));
		else sp_m.get()[j] = Selection(A, p + 5 * j, p + 5 * j + 4, 3);
	}

	T M = LinearSelection(sp_m.get(), 0, g - 1, ceil(g / 2.0f));

	int q = LinearPartition(A, p, r, M);
	int k = q - p + 1;

	if (i < k) return LinearSelection(A, p, q - 1, i);
	else if (i == k) return A[q];
	else return LinearSelection(A, q + 1, r, i - k);
}

template <typename T>
int LinearPartition(T* A, int p, int r, int M)
{
	T tmp;
	int i = p - 1;
	int M_idx;

	for (int j = p; j <= r; ++j) {
		if (A[j] <= M) {
			if (A[j] == M) M_idx = j;
			tmp = A[++i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	tmp = A[i];
	A[i] = A[M_idx];
	A[M_idx] = tmp;

	return i;
}

const size_t ARRAY_SIZE = 100'000'000;

int main()
{
	shared_ptr<int> sp_intArray(new int[ARRAY_SIZE], [](int* ptr) { delete[] ptr; });

	for (int i = 0; i <= ARRAY_SIZE - 1; ++i)
		sp_intArray.get()[i] = i;

	cout << "10. Linear Selection" << endl;

	cout << "Start!" << endl;
	auto start = high_resolution_clock::now();

	cout << "LinearSeletion: " << LinearSelection(sp_intArray.get(), 0, ARRAY_SIZE - 1, 50'000'000) << endl;

	cout << "Finish!" << endl;
	auto finish = high_resolution_clock::now();
	auto duration = finish - start;

	cout << "Elapsed Time: " << duration_cast<milliseconds>(duration).count() << "(ms)" << endl;

	return 0;
}