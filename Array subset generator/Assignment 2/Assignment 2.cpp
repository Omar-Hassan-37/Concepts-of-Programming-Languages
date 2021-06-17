
#include <iostream>
#include <stack>

using namespace std;

void GenerateSubsets(int a[], int n);

struct subsetArrayCall
{
    int *values;
    int size;
};

template<class T>
void ArraySubsets(T* a, int n)
{
    stack <subsetArrayCall> s;
    int count = pow(2, n);
    for (int i = 0; i < count; i++)
    {
        subsetArrayCall c;
        c.values = new int[n];
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                //cout << "i = " << i << ", j = " << j << endl;
                c.values[j] = a[j];
            }
        }
        s.push(c);
    }

    while (!s.empty())
    {
        subsetArrayCall saCall = s.top();
        s.pop();
        GenerateSubsets(saCall.values, n);
    }

}


int main()
{
    int a[] = { 1, 3, 8};
    int n = 3;
    //int m = 1;
    //m = 1 << m;
    //cout << "m = " << m << endl;
    ArraySubsets(a, n);
}


void GenerateSubsets(int a[], int n)
{
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= NULL) { continue; }
        cout << a[i] << " ";
    }
    cout << "}";
    cout << endl;
}