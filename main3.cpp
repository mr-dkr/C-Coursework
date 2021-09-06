#include "Bst.h"
#include <iostream>

using namespace std;

int main()
{
    Bst<int> tree(3);
    // N is Number of Intergers 
    // T is Number of tries
    int N, T;
    int arr[1000];
    int totalHeight = 0;
    cout << "Number of Intergers N : ";
    cin >> N;
    cout << "Number of Tries T : ";
    cin >> T;
    for (int j = T - 1; j > 0; j--)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            tree.insert(i);
            cout << i << endl;

        }
    }
    vector<int> v = tree.toVector();
    v = tree.toVector();
    for (int i : v)
        cout << i << " ";
    cout << endl;
}