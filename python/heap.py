import math

def printArrayInTreeStructure(arr):
    arrayLen = len(arr)
    # find nearst prefect tree of given arr
    nearestprefectTree = 0
    while(arrayLen > (2**(nearestprefectTree+1)-1)):
        nearestprefectTree+=1
        pass
    print(nearestprefectTree)
    totalNumberOfNodes = 2**(nearestprefectTree+1)-1
    print(totalNumberOfNodes)
    numberOfLeafNodes = math.ceil(totalNumberOfNodes/2**1)
    print(numberOfLeafNodes)
    rightHalf = numberOfLeafNodes//2
    node = 0
    for i in range(nearestprefectTree+1):
        print("   "*(rightHalf-2**i), end="")
        # for j in range(i):
            # print("  ", end="")
        for j in range(2**i):
            if node < arrayLen:
                print(arr[node], end="  ")
                # print("   "*(rightHalf-2**i), end="")
                node+=1
            else:
                break
        print()
            
arr = [0, 9, 6, 5, 0, 8, 2, 7, 1, 3]

def makeMaxHeap(arr, i):
    l = 2 * i
    r = l+1
    largest = i
    if l < len(arr) and arr[i] < arr[l]:
        largest = l
    else:
        largest = i
    if r< len(arr) and arr[r] > arr[largest]:
        largest = r
    if i != largest:
        arr[largest], arr[i] = arr[i], arr[largest]
        makeMaxHeap(arr, largest)

def buildMaxHeap(arr):
    for i in range(int((len(arr)-1)/2), 0, -1):
        makeMaxHeap(arr, i)
        # print(arr)
        printArrayInTreeStructure(arr[1: ])
        # input()

def popInMaxHeap(arr):
    maxElement = arr[1]
    arr[1] = arr[-1]
    arr = arr[:-1]
    printArrayInTreeStructure(arr[1: ])
    makeMaxHeap(arr, 1)
    printArrayInTreeStructure(arr[1: ])
    return maxElement

def heapDecreaseElement(arr, index, key):
    if arr[index]<key:
        raise "key is gereater"
    arr[index] = key
    makeMaxHeap(arr, index)
    printArrayInTreeStructure(arr[1:])

def heapIncreaseElement(arr, index, key):
    if arr[index]>key:
        raise "key is smaller"
    arr[index] = key
    while(index//2>0 and arr[index]>arr[index//2]):
        arr[index], arr[index//2] = arr[index//2], arr[index]
        index//=2
    printArrayInTreeStructure(arr[1:])
buildMaxHeap(arr)
input()
# heapDecreaseElement(arr, 1, 50)
heapIncreaseElement(arr, 5, 16)
# print(popInMaxHeap(arr))
# arr = [0]*31
# printArrayInTreeStructure(arr)