#include <iostream>
#include <vector>

void MovingAverage(std::vector<double> const &input, std::vector<double>& output, int n, int h) {
	double sum = 0;
	for (int i = 0; i < h; i++) {
		sum += input[i];
		output[i] = sum / (i + 1);
	}
	for (int i = h; i < n; i++) {
		sum += (input[i] - input[i - h]);
		output[i] = sum / h;
	}
}


int main() {
	unsigned int n;
	unsigned int h;
	std::cin >> n >> h;
	std::vector <double> input(n);
	std::vector <double> output(n);
	for (int i = 0; i < n; i++) std::cin >> input[i];
	MovingAverage(input, output, n, h);
	for (int i = 0; i < n; i++) std::cout << output[i] << " ";
	return 0;
}