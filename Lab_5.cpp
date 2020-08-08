//Составить программу, используя отдельные функции для решения каждой задачи своего варианта. 
//Размер массива вводится с клавиатуры. Все основные операции над массивом, которые выполняются 
//в соответствии варианта задания, реализуются с помощью функций. Массив должен передаваться в
//функции в качестве параметра. В большинстве вариантов при инициализации массива используется 
//генератор случайных чисел. Заполнение массива исходными данными и вывод массива на экран оформить 
//в отдельных функциях. Вывод одномерных и двумерных массивов оформить с помощью перегруженных функций.
//
//Написать функцию транспонирования квадратной матрицы.С ее помощью определить является ли
//заданная матрица симметричной(транспонированная матрица равна исходной).
//Оформить заполнения массива в виде отдельной функции.

//Create a program using separate functions for solving each problem of its own version.
//The size of the array is entered from the keyboard.All basic operations on an array, which are
//performed in accordance with the variant of the task, are implemented using functions.
//The array must be passed to the function as a parameter.In most cases, a random number generator
//is used to initialize an array.
//Fill the array with initial dataand display the array on the screen in separate functions.
//Format the output of one - dimensional and two - dimensional arrays using overloaded functions.
//
//Write the transpose function for a square matrix.With its help, determine whether the given matrix is
​​///symmetric(the transposed matrix is ​​equal to the original one).Make the filling of the array as a separate function.


#include <iostream>
#include <ctime>
using namespace std;


void Load_Matrix(int, int**); //Load_Matrix - функция заполнения матрицы
void Trans_Matrix(int, int, int**, int**); //Trans_Matrix - функция транспонирования матрицы
void Cout_Matrix(int S, int **Start_Arr); //Cout_Matrix - функция вывода матрицы
void Cout_Trans_Matrix(int S, int **Trans_Arr); //Cout_Trans_Matrix - функция вывода транспонированой матрицы

int k = 0;


int main()
{
	
	int S; //S - строки и столбцы

	cout << "Vvedite razmer matricu: ";
	cin >> S;

	int **Start_Arr = new int* [S];  //Start_Arr - начальная матрица
	
	for (int i = 0; i < S; i++) {
		Start_Arr[i] = new int[S];
	}

	int **Trans_Arr = new int* [S];  //Trans_Arr - транспонированая матрица

	for (int i = 0; i < S; i++) {
		Trans_Arr[i] = new int[S];
	}

	Load_Matrix(S, Start_Arr);
	Cout_Matrix(S, Start_Arr);
	cout << "--------------------------" << endl;
	Trans_Matrix(S, k, Start_Arr, Trans_Arr);
	Cout_Trans_Matrix(S, Trans_Arr);

	for (int i = 0; i < S; i++) {
		delete[] Start_Arr[i]; //Освобождаем выделенную память после работы с массивом
	}

	delete[] Start_Arr;


	for (int i = 0; i < S; i++) {
		delete[] Trans_Arr[i]; //Освобождаем выделенную память после работы с массивом
	}

	delete[] Trans_Arr;
	return 0;
}

void Load_Matrix(int S, int **Start_Arr){
	srand(time(0));
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			Start_Arr[i][j] = rand()% 1; //Заполнение начальной матрицы случайными числами от 0 до 10
		}
	}

}

void Cout_Matrix(int S, int** Start_Arr) {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			cout << Start_Arr[i][j] << " "; //Вывод начальной матрицы
		}
		cout << endl;
	}
}


void Trans_Matrix(int S, int k, int **Start_Arr, int **Trans_Arr) {
	int b;
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			
			Trans_Arr[i][j] = Start_Arr[j][i]; //Траспонирование матрицы и запись ее в новый массив для последующего сравнения
			
		}
	}
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++)
		{
			if (Start_Arr[i][j] == Trans_Arr[i][j]) //Сравнение
				k++;
		}
	}

	 if (k == S * S)
		cout << "\n Matrica simmetrycnaya\n";
	 else
		 cout << "\n Matrica ne simmetrychnaya\n";

} 

void Cout_Trans_Matrix(int S, int **Trans_Arr) {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			cout << Trans_Arr[i][j] << " "; //Вывод транспонированой матрицы
		}
		cout << endl;
	}
	cout << endl;
}