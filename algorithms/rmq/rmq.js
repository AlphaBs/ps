setInput(`
15
7
2
8
3
5
16
3
4
4
1
6
9
3
1
7`)

function main() {
    const n = Number(readLine())
    const arr = new Array(n)
    for (let i = 0; i < n; i++) {
        arr[i] = Number(readLine())
    }

    const tree = new Array(n * 4)
    init(arr, tree)

    //arr[9] = 5
    //update(arr, 9, tree)

    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            let rangeMin = query(arr, tree, i, j)
            writeLine(`[${i},${j}] = ${rangeMin}`)
        }
    }
}

function init(arr, tree) {
    initTree(arr, tree, 1, 0, arr.length - 1)
}

// [left, right]
function initTree(arr, tree, node, left, right) {
    if (left == right) { // length=1
        return tree[node] = arr[left];
    }

    let mid = Math.floor((left + right) / 2)
    let leftTree = initTree(arr, tree, node * 2, left, mid)
    let rightTree = initTree(arr, tree, node * 2 + 1, mid + 1, right)
    return tree[node] = Math.min(leftTree, rightTree)
}

function query(arr, tree, left, right) {
    return queryTree(tree, 1, 0, arr.length - 1, left, right)
}

// [queryLeft, queryRight] in [nodeLeft, nodeRight]
function queryTree(tree, node, nodeLeft, nodeRight, queryLeft, queryRight) {
    // empty
    if (queryRight < nodeLeft || queryLeft > nodeRight) {
        return Number.MAX_SAFE_INTEGER
    }

    // inclusive
    if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
        return tree[node]
    }

    let mid = Math.floor((nodeLeft + nodeRight) / 2)
    let leftTree = queryTree(tree, node * 2, nodeLeft, mid, queryLeft, queryRight)
    let rightTree = queryTree(tree, node * 2 + 1, mid + 1, nodeRight, queryLeft, queryRight)
    return Math.min(leftTree, rightTree)
}

function update(arr, pos, tree) {
    udpateTree(arr, pos, tree, 1 , 0, arr.length - 1)
}

// update tree with arr[pos]
function updateTree(arr, pos, tree, node, nodeLeft, nodeRight) {
    if (nodeLeft > pos || nodeRight < pos) {
        return tree[node]
    }

    let mid = Math.floor((nodeLeft + nodeRight) / 2)
    let leftTree = updateTree(arr, pos, tree, node * 2, nodeLeft, mid)
    let rightTree = updateTree(arr, pos, tree, node * 2 + 1, mid + 1, nodeRight)
    return tree[node] = Math.min(leftTree, rightTree)
}