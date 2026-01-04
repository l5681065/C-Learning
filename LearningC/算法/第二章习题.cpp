#include <iostream>
using namespace std;

void Merge(int A[], int B[], int C[], int n);

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//1(8) 
int main_1_8() {
	int A1[] = { 1, 3, 5, 7 };
	int B1[] = { 2, 4, 6, 8 };
	int C1[8];
	Merge(A1, B1, C1, 4);
	for (int i = 0; i < 8; i++) {
		std::cout << C1[i] << " ";
	}
}

//合并两个各有n个元素的有序表为一个有序表 
void Merge(int A[], int B[], int C[], int n) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < n) {
		if (A[i] < B[j]) {
			C[k] = A[i];
			i++;
			k++;
		}
		else {
			C[k] = B[j];
			j++;
			k++;
		}
	}
	while (i < n) {
		C[k] = A[i];
		i++;
		k++;
	}
	while (j < n) {
		C[k] = B[j];
		j++;
		k++;
	}
}

/