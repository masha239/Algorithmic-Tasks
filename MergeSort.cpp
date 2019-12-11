#include <iostream>


template <typename Type>

void merge(Type* A, int left, int right, int half) {

	Type* C = new Type[right - left + 1];
	int head1 = left;
	int head2 = half + 1;

	int t = 0;
	while (head1 <= half && head2 <= right)
	{
		if (A[head1] <= A[head2])
		{
			C[t] = A[head1];
			head1++;
			t++;
		}
		else
		{
			C[t] = A[head2];
			head2++;
			t++;
		}
	}
	if (head1 > half) while (head2 <= right)
	{
		C[t] = A[head2];
		head2++;
		t++;
	}
	else
		if (head2 > right) while (head1 <= half)
		{
			C[t] = A[head1];
			head1++;
			t++;
		}
	for (int i = 0; i < t; i++) A[left + i] = C[i];
	delete[] C;
}

template <typename Type>

void mergeSort(Type* A, int left, int right)
{
	if (left == right) return;
	int half = (left + right) / 2;
	mergeSort <Type>(A, left, half);
	mergeSort <Type>(A, half + 1, right);
	merge <Type>(A, left, right, half);
}


using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort <int>(arr, 0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}