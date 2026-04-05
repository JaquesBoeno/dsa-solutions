// O seguinte código é a resolução de alguns exercicios da seguinte lista
// https://www.facom.ufu.br/~backes/wordpress/ListaC08.pdf
#include <stdio.h>

int sum(int n) {
	if (n == 1)
		return 1;
	return n + sum(n - 1);
}

int fat(int n) {
	if (n == 1)
		return 1;
	return n * fat(n - 1);
}

int sumOfCubes(int n) {
	if (n == 1)
		return 1;
	return n * n * n + sumOfCubes(n - 1);
}

int power(int a, int b) {
	if (b == 0)
		return 1;
	return a * power(a, b - 1);
}

int fib(int n) {
	if (n < 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int mul(int a, int b) {
	if (b == 0)
		return 0;
	return a + mul(a, b - 1);
}

int main() {
	int choice = 0;
	int a = 0, b = 0;
	do {
		printf("Digite o numero do programa que deseja exeecutar:\n");
		printf("1. Somatorio ate N\t2. Fatorial\t3. Soma dos Cubos\n4. Potencia\t\t5. Fibonacci\t6. Multiplicação\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Digite um N: ");
				scanf("%d", &a);
				printf("Resultado: %d", sum(a));
				break;
			case 2:
				printf("Digite um N: ");
				scanf("%d", &a);
				printf("Resultado: %d", fat(a));
				break;
			case 3:
				printf("Digite um N: ");
				scanf("%d", &a);
				printf("Resultado: %d", sumOfCubes(a));
				break;
			case 4:
				printf("Digite um A: ");
				scanf("%d", &a);
				printf("Digite um B: ");
				scanf("%d", &b);
				printf("Resultado de A^B: %d", power(a, b));
				break;
			case 5:
				printf("Digite um N: ");
				scanf("%d", &a);
				printf("Resultado: %d", fib(a));
				break;
			case 6:
				printf("Digite um A: ");
				scanf("%d", &a);
				printf("Digite um B: ");
				scanf("%d", &b);
				printf("Resultado de A*B: %d", mul(a, b));
				break;
		}
		printf("\n");
	} while (choice);
}
