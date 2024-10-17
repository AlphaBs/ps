// https://www.acmicpc.net/problem/1927

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int length = 0;
int arr[111'111];

bool isEmpty()
{
    return length == 0;
}

void push(int value)
{
    arr[++length] = value;
    int current = length;
    while (current > 1 && arr[current] < arr[current / 2])
    {
        swap(arr[current], arr[current / 2]);
        current /= 2;
    }
}

int top()
{
    return arr[1];
}

void pop()
{
    arr[1] = arr[length--];
    int current = 1;
    while (true)
    {
        int parent = current;
        int left = current * 2;
        int right = current * 2 + 1;

        if (left <= length && arr[left] < arr[parent])
        {
            parent = left;
        }
        if (right <= length && arr[right] < arr[parent])
        {
            parent = right;
        }
        if (current == parent)
        {
            break;
        }
        swap(arr[current], arr[parent]);
        current = parent;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == 0) // remove
        {
            if (!isEmpty())
            {
                cout << top() << '\n';
                pop();
            }
            else
            {
                cout << "0\n";
            }
        }
        else // add
        {
            push(x);
        }
    }

    return 0;
}