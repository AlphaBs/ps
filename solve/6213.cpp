// https://www.acmicpc.net/problem/6213

#include <iostream>
#include <cstdio>
#include <algorithm>

#define TREE_MAX 999'999'999
#define TREE_MIN -1
#define TREE_SIZE 55'555 * 4

using namespace std;

int n, q;
int height[55'555];
pair<int, int> tree[TREE_SIZE];

pair<int, int> init(int node, int start, int end)
{
    if (start == end)
        return tree[node] = { height[start], height[start] };
    int mid = (start + end) / 2;
    pair<int, int> left = init(node * 2, start, mid);
    pair<int, int> right = init(node * 2 + 1, mid + 1, end);
    tree[node] = { max(left.first, right.first), min(left.second, right.second) };
    return tree[node];
}

pair<int, int> find(int node, int start, int end, int left, int right)
{
    // 겹치지 않음
    if (left > end || right < start)
        return { TREE_MIN, TREE_MAX };
    
    // [left, right] 안에 [start, end]
    if (left <= start && end <= right)
        return tree[node];
    
    // 겹쳐짐
    int mid = (start + end) / 2;
    pair<int, int> leftTree = find(node * 2, start, mid, left, right);
    pair<int, int> rightTree = find(node * 2 + 1, mid + 1, end, left, right);
    return { max(leftTree.first, rightTree.first), min(leftTree.second, rightTree.second) };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> result = find(1, 0, n - 1, a - 1, b - 1);
        cout << (result.first - result.second) << '\n';
    }

    return 0;
}