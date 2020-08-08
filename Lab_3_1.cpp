#include <iostream>
#include <iomanip>
#include <ctime>


using namespace std;

int main()
{
    const int n = 9, l = 81;
    float A[n][n]; //объявляем матрицу 9 х 9
    double T[l], G[l];
    int i, j, kol, nomer_1, nomer_2, zero;
    double proz;

    srand(time(0));

    cout << "Vvedite matricu " << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j]; //Вводим матрицу
        }
    cout << "\nVvedena  matrica" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << setw(5) << A[i][j]; //Выводим матрицу
        cout << "\n";
    }

    kol = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] > 0) {
                kol = kol + 1;         //Ищем количество отрицательных элементов в матрице       
            }
        }
    }
    cout << "\nKolichestvo otrichatelnyh elementov:" << kol << endl;

    proz = 1;
    for (i = 0; i < n; i++)
    {
        if (A[i][4] > 0) {
            proz = proz* A[i][4]; //Ищем произведение положительных элементов в 5 столбце
        }
    }

    cout << "\n Proizvedeniye polojutelnuh elementov 5 stolbca:" << proz;

    nomer_1 = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] > 8) {
                T[nomer_1] = A[i][j]; //Ищем и записываем в массив Т элементы, большие 8
                nomer_1++;
            }
        }
    }


    cout << "\nMassiv iz elementov > 8" << endl;
    for (i = 0; i < nomer_1; i++)
    {
        cout << T[i] << " "; //Выводим массив Т
    }



    nomer_2 = 0;
    for (j = 0; j < n; j++)
    {
        zero = 0;
        for (i = 0; i < n; i++)
        {
            if (A[i][j] == 0 && j <= i && j <= n - i - 1) {
                zero++; //Ищем и подсчитываем количество нулей в каждом стоблце заштрихованой области
            }

        }
        G[nomer_2] = zero; //Записываем это количество в массив G
        nomer_2++;

    }

    cout << "\nMassiv iz kolichestva elementov, ravnuh 0 v kazdom stolbce zashtrihovennoy oblasti" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << G[i] << " "; //Выводим массив
    }

    return 0;
}
