// https://www.acmicpc.net/problem/1991

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
pair<char, char> tree[33];

void preorder(int c)
{
    cout << (char)(c + 'A');
    if (tree[c].first != '.')
        preorder(tree[c].first - 'A');
    if (tree[c].second != '.')
        preorder(tree[c].second - 'A');
}

void inorder(int c)
{
    if (tree[c].first != '.')
        inorder(tree[c].first - 'A');
    cout << (char)(c + 'A');
    if (tree[c].second != '.')
        inorder(tree[c].second - 'A');
}

void postorder(int c)
{
    if (tree[c].first != '.')
        postorder(tree[c].first - 'A');
    if (tree[c].second != '.')
        postorder(tree[c].second - 'A');
    cout << (char)(c + 'A');
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c, l, r;
        cin >> c >> l >> r;
        tree[c - 'A'] = {l, r};
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    return 0;
}