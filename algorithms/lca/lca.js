// initialize a tree with 13 nodes and 12 edges
// the root node is always 0
setInput(`
12
0 1
0 6
0 8
1 2
1 3
3 4
3 5
6 7
8 9
8 12
9 10
9 11
4 11`) // the last two numbers mean A and B, which is the node number for finding the minimum path between them

function flatTree(tree, root) { 
    return new TreeFlatter(tree, root).flat()
}

class TreeFlatter {
    constructor(tree, root) {
        this.nextId = 0
        this.idToNodeMap = {}
        this.ndoeToIdMap = {}
        this.nodeToLocationMap = {}
        this.nodeToDepthMap = {}
        this.elements = []
        this.tree = tree
        this.root = root
    }

    flat() {
        this._flat(this.root, 0)
        return {
            elementsAsId: this.elements,
            getNodeById: id => this.idToNodeMap[id],
            getIdByNode: node => this.nodeToIdMap[node],
            getPositionByNode: node => this.nodeToLocationMap[node],
            getDepthByNode: node => this.nodeToDepthMap[node]
        }
    }

    // pre-order traversal
    _flat(node, depth) {
        let id = this.nextId
        this.elements.push(id)

        this.nextId += 1
        this.idToNodeMap[id] = node
        this.nodeToIdMap[node] = id

        this.nodeToLocationMap[node] = this.elements.length - 1
        this.nodeToDepthMap[node] = depth

        if (!this.tree[node])
            return

        for (let i = 0; i < this.tree[node].length; i++) {
            this._flat(this.tree[node][i], depth + 1)
            this.elements.push(id)
        }
    }
}

class SegmentTree {
    constructor() {
        this.segTree = []
        this.segTreeLength = 0
    }

    init(arr) {
        this.segTreeLength = arr.length - 1
        this.segTree = new Array(arr.length * 4)
        this._init(arr, 1, 0, arr.length - 1)
    }

    _init(arr, node, left, right) {
        if (left == right) {
            return this.segTree[node] = arr[left]
        }

        const mid = Math.floor((left + right) / 2)
        const leftTree = this._init(arr, node * 2, left, mid)
        const rightTree = this._init(arr, node * 2 + 1, mid + 1, right)
        return this.segTree[node] = Math.min(leftTree, rightTree)
    }

    query(left, right) {
        return this._query(1, 0, this.segTreeLength - 1, left, right)
    }

    _query(node, nodeLeft, nodeRight, queryLeft, queryRight) {
        if (queryLeft > nodeRight || queryRight < nodeLeft) {
            return Number.MAX_SAFE_INTEGER
        }

        if (queryLeft <= nodeLeft && nodeRight <= queryRight) {
            return this.segTree[node]
        }

        const mid = Math.floor((nodeLeft + nodeRight) / 2)
        const leftTree = this._query(node * 2, nodeLeft, mid, queryLeft, queryRight)
        const rightTree = this._query(node * 2 + 1, mid + 1, nodeRight, queryLeft, queryRight)
        return Math.min(leftTree, rightTree)
    }
}

function main() {
    const tree = {}
    const n = Number(readLine())
    for (let i = 0; i < n; i++) {
        let [p, c] = readLine().split(" ").map(Number)
        if (!tree[p])
            tree[p] = []
        tree[p].push(c)
    }
    const [a, b] = readLine().split(" ").map(Number)

    const flattenTree = flatTree(tree, 0)
    for (let id of flattenTree.elementsAsId) {
        write(flattenTree.getNodeById(id) + ",") // write flatten tree
    }
    write("\n")

    const queryLeft = flattenTree.getPositionByNode(a)
    const queryRight = flattenTree.getPositionByNode(b)

    const segTree = new SegmentTree()
    segTree.init(flattenTree.elementsAsId)
    const lcaId = segTree.query(queryLeft, queryRight)
    const lcaNode = flattenTree.getNodeById(lcaId)
    writeLine(lcaNode) // write LCA node between A and B

    const leftDepth = flattenTree.getDepthByNode(a)
    const rightDepth = flattenTree.getDepthByNode(b)
    const lcaDepth = flattenTree.getDepthByNode(lcaNode)

    const pathLength = leftDepth + rightDepth - lcaDepth * 2
    writeLine(pathLength) // write the minimum path between A and B
}