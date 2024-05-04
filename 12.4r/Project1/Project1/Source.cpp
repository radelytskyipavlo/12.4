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

void PrintRecursive(int N, Elem*& L, int increaseBy, int index)
{
    if (index == N)
        return;
    else
    {
        Info a;
        cout << "Element " << index << " :";
        cin >> a;
        insert(L, a, increaseBy);
        PrintRecursive(N, L, increaseBy, index + 1);
    }
}

void printAndRemove(Elem*& L) {
    if (L == NULL)
        return;
    cout << remove(L) << ' ';
    printAndRemove(L);
}

int main()
{
    SetConsoleOutputCP(1251);
    Elem* L = NULL;
    int N, increaseBy;
    cout << "Enter the quantity: "; cin >> N;
    cout << "Enter the increase value: "; cin >> increaseBy;
    PrintRecursive(N, L, increaseBy, 0);
    Elem* first = L;
    printAndRemove(L);
    return 0;
}
