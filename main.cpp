#include <iostream>
using namespace std;

/* ---------- ВВЕДЕННЯ МАСИВУ ---------- */
template <typename T>
void inputArray(T a[], int &N) 
{
    do 
    {
        cout << "Введіть розмір масиву (2..50): ";
        cin >> N;
    } while (N < 2 || N > 50);

    for (int i = 0; i < N; i++) 
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }
}

/* ---------- ВИВЕДЕННЯ МАСИВУ ---------- */
template <typename T>
void printArray(const T a[], int N) 
{
    for (int i = 0; i < N; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

/* ---------- ОБРОБКА Array30 ---------- */
void processArray30(const double a[], int N) 
{
    int count = 0;

    cout << "Номери елементів, більших за правого сусіда: ";
    for (int i = 0; i < N - 1; i++) 
    {
        if (a[i] > a[i + 1]) 
        {
            cout << i + 1 << " ";
            count++;
        }
    }
    cout << endl;
    cout << "Кількість таких елементів: " << count << endl;
}

/* ---------- ОБРОБКА Array98 ---------- */
void processArray98(int a[], int &N) 
{
    for (int i = 0; i < N; i++) 
    {
        int count = 0;

        for (int j = 0; j < N; j++) 
        {
            if (a[j] == a[i]) count++;
        }

        if (count < 3) 
        {
            for (int k = i; k < N - 1; k++)
                a[k] = a[k + 1];
            N--;
            i--;
        }
    }
}

/* ---------- ЗАВДАННЯ 1 ---------- */
void task1() 
{
    cout << "\n--- Завдання 1 (Array30) ---\n";

    double a[50];
    int N;

    inputArray(a, N);
    cout << "Масив: ";
    printArray(a, N);

    processArray30(a, N);
}

/* ---------- ЗАВДАННЯ 2 ---------- */
void task2() {
    cout << "\n--- Завдання 2 (Array98) ---\n";

    int a[50];
    int N;

    inputArray(a, N);
    cout << "Початковий масив: ";
    printArray(a, N);

    processArray98(a, N);

    cout << "Розмір нового масиву: " << N << endl;
    cout << "Отриманий масив: ";
    printArray(a, N);
}

/* ---------- MAIN ---------- */
int main() 
{
    int choice;
    do 
    {
        cout << "\n1 - Завдання 1\n2 - Завдання 2\n0 - Вихід\n";
        cin >> choice;

        if (choice == 1) task1();
        else if (choice == 2) task2();

    } 
    while (choice != 0);

    return 0;
}
