from utils import test, random_array, swap

#divides array into subarrays until size 1, then merges until back to original array, sorted
def merge(a, b):
    arr = []
    while a and b:
        if a[0] < b[0]:
            arr.append(a.pop(0))
        else:
            arr.append(b.pop(0))

    #one of these arrays are empty now
    arr = arr + a + b
    return arr

def merge_sort(arr):
    if len(arr) == 1:
        return arr
    middle = len(arr) / 2
    left = merge_sort(arr[:middle])
    right = merge_sort(arr[middle:])
    return merge(left, right)

if __name__ == "__main__":
    sortedarr = merge_sort(random_array(10))
    print(sortedarr)
    print(test(sortedarr))
