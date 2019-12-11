#include <ctime>
#include <cmath>
#include <iostream>


template <typename Type>

int partition(Type* A, int left, int right) {
	Type tmp;
	srand(time(NULL));
	int q = left + rand() % (right - left + 1);
	tmp = A[right]; //������� ��������� �������, �������� � ���������
	A[right] = A[q];
	A[q] = tmp;

	Type x = A[right];
	int i = left - 1; // ������� ��������� <= x

	for (int j = left; j < right; j++)
	{
		if (A[j] <= x)
		{
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	tmp = A[right];
	A[right] = A[i + 1];
	A[i + 1] = tmp; // x ����� ����� �� ��������
	return i + 1;
}

template <typename Type>

void quickSort(Type* A, int left, int right)
{
	if (left < right) {
		int q = partition<Type>(A, left, right);
		quickSort<Type>(A, left, q - 1);
		quickSort<Type>(A, q + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	quickSort <int> (arr, 0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}