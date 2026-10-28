#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

// 1. СПОСІБ 1: ЗВИЧАЙНІ ФУНКЦІЇ (для int)

// Формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Форматне виведення масиву в рядок
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

// Обчислення суми квадратів елементів масиву
int SumSq(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}


// 2. СПОСІБ 2: ШАБЛОНИ ФУНКЦІЙ (універсальні)

// Шаблонна функція формування масиву
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
    {
        double r = (double)rand() / RAND_MAX;
        a[i] = (T)(Low + r * (High - Low));
    }
}

// Шаблонна функція виведення масиву
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << setprecision(2) << fixed << a[i];
    cout << endl;
}

// Шаблонна функція обчислення суми квадратів
template <typename T>
T SumSq(T* a, const int size)
{
    T s = T(); // Початкове нульове значення для відповідного типу T
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}


// ГОЛОВНА ФУНКЦІЯ MAIN
int main()
{
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    const int n = 5;
  
    // СПОСІБ 1: Робота зі звичайними функціями (int)
        
    int a[n];
    int LowInt = -5, HighInt = 5;

    cout << "=== 1. ЗВИЧАЙНІ ФУНКЦІЇ (тип int) ===" << endl;
    Create(a, n, LowInt, HighInt);
    cout << "Масив a:" << endl;
    Print(a, n);

    int s1 = SumSq(a, n);
    cout << "Сума квадратів = " << s1 << endl << endl;

    // СПОСІБ 2: Робота з шаблонами функцій (double)

    double b[n];
    double LowDouble = -5.0, HighDouble = 5.0;

    cout << "=== 2. ШАБЛОНИ ФУНКЦІЙ (тип double) ===" << endl;
    Create<double>(b, n, LowDouble, HighDouble);
    cout << "Масив b (double):" << endl;
    Print<double>(b, n);

    double s2 = SumSq<double>(b, n);
    cout << "Сума квадратів = " << s2 << endl;

    return 0;
}