#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int Rand_matrix(int M, int N, int** matrix)
{
	for (int r = 0; r < M; r++)
	{
		matrix[r] = new int[N];
	}
	for (int i = 0; i < M; i++)
	{
		int* line = new int[N];

		for (int j = 0; j < N; j++)
		{
			line[j] =rand() % 20 - 10;
			cout << line[j] << " ";
		}
		cout << endl;
		matrix[i] = line;
	}
	return 0;
}

int Matrix_sum(int** mat1, int** mat2, int M, int N)
{
    int** matrix;
	matrix = new int* [M];
	for (int r = 0; r < M; r++)
	{
		matrix[r] = new int[N];
	}
	int** Sum = matrix;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Sum[i][j] = mat1[i][j] + mat2[i][j];
			cout << Sum[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}
int Matrix_dif(int** mat1, int** mat2, int** mat3, int** mat4, int M, int N)
{
	int** matrix;
	matrix = new int* [M];
	for (int r = 0; r < M; r++)
	{
		matrix[r] = new int[N];
	}
	int** Dif = matrix;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Dif[i][j] = (mat1[i][j] + mat2[i][j])-1*(mat3[i][j] + mat4[i][j]);
			cout << Dif[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	locale::global(locale("Russian_Russia.1251"));
	srand(time(NULL));
	int M = rand() % 10 + 1;
	int N = rand() % 10 + 1;
	cout << "Размер матриц: " << M << "*" << N << endl;
	int** A;
	int** B;
	int** C;
	int** D;
	A = new int* [M];
	B = new int* [M];
	C = new int* [M];
	D = new int* [M];

	cout << "Матрица A: " << endl;
	Rand_matrix(M, N, A);
	cout << "Матрица B: " << endl;
	Rand_matrix(M, N, B);
	cout << "Матрица C: " << endl;
	Rand_matrix(M, N, C);
	cout << "Матрица D: " << endl;
	Rand_matrix(M, N, D);
	cout << "A+B: " << endl;
	Matrix_sum(A, B, M, N);
	cout << "C+D: " << endl;
	Matrix_sum(C, D, M, N);
	cout << "(A+B)-(C+D): " << endl;
	Matrix_dif(A, B, C, D, M, N);

	return 0;
}