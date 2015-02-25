import utils

#my implementation of insertion sort
#insertion sort works by iterating and inserting the values in their correct spots

def insertion_sort(arr):
    for n in xrange(1, len(arr)):
        for m in xrange(n, 0, -1):
            if arr[m] < arr[m - 1]:
                utils.swap(arr, m, m - 1)
            else:
                break
    return arr

if __name__ == "__main__":
    sortedarr = insertion_sort(utils.random_array(10))
    print(utils.test(sortedarr))
