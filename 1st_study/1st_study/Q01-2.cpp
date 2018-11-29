#include <iostream>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int num1 = 15, num2 = 35;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'C', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double db1 = 0.95, db2 = 4.85;
	swap(&db1, &db2);
	std::cout << db1 << ' ' << db2 << std::endl;

	return 0;

}