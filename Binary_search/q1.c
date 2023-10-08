#include <stdio.h>


int sum(int);

int main() {

	printf("sum is %d\n", sum(5));
	return 0;

}


int sum(int n) {
	if (n == 1) {
		return 1;
	}

	return n + sum(n - 1);
}