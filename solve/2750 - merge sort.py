def mergeArray(arr, brr):
    aindex = 0
    bindex = 0
    result = []

    while (aindex < len(arr) and bindex < len(brr)):
        if (arr[aindex] < brr[bindex]):
            result.append(arr[aindex])
            if (aindex == len(arr) -1):
                result.extend(brr[bindex:])
                break
            aindex += 1
        else:
            result.append(brr[bindex])
            if (bindex == len(brr) - 1):
                result.extend(arr[aindex:])
                break
            bindex += 1
    
    return result

def dvArr(inarr):
    mid = len(inarr) // 2 # 두번째 배열 시작 인덱스
    arr = inarr[:mid]
    brr = inarr[mid:]

    if (len(arr) > 1):
        arr = dvArr(arr)
    if (len(brr) > 1):
        brr = dvArr(brr)
    
    return mergeArray(arr, brr)

inputarr = [2,76,3,56,1,8,35,36,99,12,13,14,15,16,17,22,66,55, 0]

print(dvArr(inputarr))