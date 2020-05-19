while True:
    try:
        rInput = input()
        if (rInput == None or rInput == ""):
            break
        inp = rInput.split()
        a = int(inp[0])
        b = int(inp[1])
        print(a + b)
    except:
        break
