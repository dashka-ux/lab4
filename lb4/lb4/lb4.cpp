#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;
void DFS(int vert, int* vis, int** mass, int size) {
	printf("%d", vert + 1);
	vis[vert] = 1;
	for (int i = 0; i < size; i++) {
		if (mass[vert][i] && vis[i] != 1) {
			DFS(i, vis, mass, size);
		}
	}
}


int main() {
	srand(time(NULL));
	int size;
	printf("Enter lenght: ");
	scanf("%d", &size);
	int* visited = (int*)malloc(sizeof(int) * size);
	int* v = (int*)malloc(sizeof(int) * size);
	int** mass = (int**)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		visited[i] = 0;
	}
	printf("\n");
	printf("\n");
	for (int i = 0; i < size; i++) {
		v[i] = i + 1;
		printf("%d ", v[i]);
	}
	printf("\n");
	printf("\n");
	for (int i = 0; i < size; i++) {
		mass[i] = (int*)malloc(sizeof(int) * size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int c = rand() % 101;
			if (c <= 50) {
				mass[i][j] = 1;
			}
			else mass[i][j] = 0;
			if (i == j) {
				mass[i][j] = 0;
			}

		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mass[i][j] != mass[j][i])
				mass[i][j] = mass[j][i];

		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}

	for (int vert = 0; vert < size; vert++) {
		if (visited[vert] == 0) {
			printf("\n");
			printf("recurse: ");
			DFS(vert, visited, mass, size);
		}
		for (int i = 0; i < size; i++) {
			visited[i] = 0;
		}	printf("\n");
	}
	for (int i = 0; i < size; i++) {
		visited[i] = 0;
	}
	printf("\n");



}