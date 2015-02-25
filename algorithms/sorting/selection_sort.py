from utils import test, random_array, swap

def my_min(arr):
    mini = 0
    for x in xrange(1, len(arr)):
        if arr[x] < arr[mini]:
            mini = x
    return mini

#selection sort. finds the minimum and exchanges it with the current minimum
def selection_sort(arr):
    for x in xrange(0, len(arr)):
        mini = x
        for y in xrange(x, len(arr)):
            if arr[y] < arr[mini]:
                mini = y
        swap(arr, x, mini)

    return arr

if __name__ == "__main__":
    sortedarr = selection_sort(random_array(10))
    print(sortedarr)
    print(test(sortedarr))
