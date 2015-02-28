from utils import test, random_array, swap

#divides array into subarrays until size 1, then merges until back to original array, sorted
def partition(arr, low, high):
    pivotIndex = low
    low = low + 1

    for x in xrange(low, high + 1):
        if arr[x] < arr[pivotIndex]:
            swap(arr, x, low)
            low = low + 1

    swap(arr, pivotIndex, low - 1)

    return low - 1

def quick_sort(arr):
    quick_sort_helper(arr, 0, len(arr) - 1)
    return arr

def quick_sort_helper(arr, low, high):
    if low < high:
        pivotIndex = partition(arr, low, high)
        quick_sort_helper(arr, low, pivotIndex - 1)
        quick_sort_helper(arr, pivotIndex + 1, high)

if __name__ == "__main__":
    sortedarr = quick_sort(random_array(10))
    print(sortedarr)
    print(test(sortedarr))
