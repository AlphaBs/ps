const inputTextarea = document.getElementById("input-textarea")
const outputTextarea = document.getElementById("output-textarea")
const startedElement = document.getAnimations("started")
const runtimeElement = document.getElementById("runtime")
const inputsElement = document.getElementById("inputs")
const outputsElement = document.getElementById("outputs")

let inputLines = []
let currentLine = 0
function readLine() {
    if (currentLine >= inputLines.length) {
        throw new Error("readLine() EOF")
    }
    let nextLine = inputLines[currentLine]
    currentLine++
    return nextLine
}

function write(msg) {
    outputTextarea.value += msg
}

function writeLine(msg) {
    write(msg + "\n")
}

function run() {
    currentLine = 0
    inputLines = inputTextarea.value.split("\n")
    inputsElement.innerText = inputLines.length

    outputTextarea.value = ""
    startedElement.innerText = ""
    runtimeElement.innerText = ""

    let started = new Date()
    main()
    let ended = new Date()

    startedElement.innerText = started.toLocaleTimeString()
    runtimeElement.innerText = (ended- started) + "ms"
    outputsElement.innerText = outputTextarea.value.split("\n").length
}

function setInput(inputs) {
    inputTextarea.value = inputs.trim()
}