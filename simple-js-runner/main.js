setInput(`
5
1
2
3
4
5`)

function main() {
    let n = Number(readLine())
    let sum = 0
    for (let i = 0; i < n; i++) {
        sum += Number(readLine())
    }
    writeLine(sum)
}