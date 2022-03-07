while True:
    inp = input()
    if inp == ".":
        break
    
    result = True
    stk = list()
    for i in inp:
        if i == '(':
            stk.append(1)
        elif i == ')':
            if len(stk) == 0 or stk.pop() != 1:
                result = False
                break
        elif i == '[':
            stk.append(2)
        elif i == ']':
            if len(stk) == 0 or stk.pop() != 2:
                result = False
                break

    if result and len(stk) == 0:
        print("yes")
    else:
        print("no")