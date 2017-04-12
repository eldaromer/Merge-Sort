#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

const int size = 20;

void print(int *input) {
	for (int i = 0; i < size; i++)
		cout << input[i] << " ";
	cout << endl;
}

void randomArray(int* in) {
	for (int i = 0; i < size; i++) {
		in[i] = rand() % 100;
	}
}

void merge(int* input, int low, int high) {
	int mid = floor((low + high) / 2);;

	int count = 0;
	int countA = low;
	int countB = mid + 1;

	vector<int> temp;

	while (countA <= mid && countB <= high) {
		if (input[countA] < input[countB]) {
			temp.push_back(input[countA]);
			countA++;
		}
		else {
			temp.push_back(input[countB]);
			countB++;
		}
	}

	while (countA <= mid) {
		temp.push_back(input[countA]);
		countA++;
	}

	while (countB <= high) {
		temp.push_back(input[countB]);
		countB++;
	}

	for (int i = low; i <= high; i++) {
		input[i] = temp[i - low];
	}
}

void mergeSort(int* input, int low, int high) {
	if (low < high) {
		int mid = floor((low + high) / 2);
		mergeSort(input, low, mid);
		mergeSort(input, mid + 1, high);
		merge(input, low, high);
	}
}

int main() {
	int input[size];
	randomArray(input);
	print(input);
	mergeSort(input, 0, size - 1);
	print(input);

	cin.ignore();

	return 0;
}