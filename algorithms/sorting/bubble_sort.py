from utils import test, random_array, swap

#bubble sort. runs through over and over until all is well
def bubble_sort(arr):
    in_order = False
    while not in_order:
        in_order = True
        for x in xrange(0, len(arr) - 1):
            if arr[x] > arr[x + 1]:
                swap(arr, x, x + 1)
                in_order = False

    return arr

if __name__ == "__main__":
    sortedarr = bubble_sort(random_array(10))
    print(sortedarr)
    print(test(sortedarr))
