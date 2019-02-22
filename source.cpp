#include <iostream>
#include <conio.h>
using namespace std;

const int M = 10, N = 10; //size of the array. M being number of rows, and N number of cols.

void printPath(int path[M][N]) { //this function just prints the path.
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << " " << path[i][j];
		}
		cout << endl;
	}
}

void search(int arr[M][N], int m, int n, bool visited[M][N], int path[M][N]) { //m and n are current row/col in the maze.
	if (visited[m][n]) {
		return;
	}
	else {
		visited[m][n] = true;
		path[m][n] = 1;
		if (m + 1 < M && arr[m+1][n]==1) {
			search(arr, m + 1, n, visited, path);
		}
		if (n + 1 < N && arr[m][n+1]==1) {
			search(arr, m, n + 1, visited, path);
		}
		if (m - 1  >= 0 && arr[m-1][n] == 1) {
			search(arr, m-1, n, visited, path);
		}
		if (n - 1 >=0 && arr[m][n - 1] == 1) {
			search(arr, m, n - 1, visited, path);
		}
		if (m + 1 == M && n + 1 == N) {
			cout << "FINAL STATE REACHED!";
			printPath(path);
			_getch();
			return;
		}
		path[m][n] = 0;
	}
}

void main() { //test input. Feel free to play with the input.
	int arr[M][N] = { 
	{ 1, 0, 1, 0, 1, 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 0, 1, 1, 1, 0, 1, 1 }, 
	{ 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 }, 
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 }, 
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 1 }, 
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 1 }, 
	{ 1, 1, 1, 0, 1, 0, 0, 0, 1, 1 }, 
	{ 1, 0, 1, 0, 1, 0, 0, 1, 1, 0 }, 
	{ 1, 0, 0, 0, 1, 1, 0, 0, 1, 0 }, 
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 }, };

	bool visited[M][N];
	for (int i = 0; i < N; i++) { //initiallizing only.
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
	int path[M][N];
	for (int i = 0; i < N; i++) { //initializing only
		for (int j = 0; j < M; j++) {
			path[i][j] = 0;
		}
	}
	search(arr, 0, 0, visited, path); //start state is (0,0)..
}



