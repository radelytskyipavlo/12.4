#include <iostream>
#include <Windows.h>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value, int increaseBy) 
{
    Elem* tmp = new Elem;
    tmp->info = value + increaseBy;
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else
    {
        L = tmp;
    }
    tmp->link = L;
}

Info remove(Elem*& L)
{
    Elem* T = L;
    while (T->link != L)
        T = T->link;
    Info value = L->info;
    if (T != L)
    {
        Elem* tmp = L->link;
        delete L;
        L = tmp;
        T->link = L;
    }
    else
    {
        delete L;
        L = NULL;
    }
    return value;
}

void Print(int N, Elem*& L, int increaseBy) 
{
    Info a;
    for (int i = 0; i < N; i++)
    {
        cout << "Element " << i << " :";
        cin >> a;
        insert(L, a, increaseBy); 
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    Elem* L = NULL;
    int N, increaseBy; 
    cout << "Enter the quantity: "; cin >> N;
    cout << "Enter the increase value: "; cin >> increaseBy;
    Print(N, L, increaseBy); 
    Elem* first = L;
    while (L != NULL)
    {
        cout << remove(L) << ' ';
    }
    return 0;
}
