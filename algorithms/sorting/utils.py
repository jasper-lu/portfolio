import random

def swap(arr, a, b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp

#creates a random array of len n
def random_array(n, range=20):
    return [random.randint(0, range) for num in xrange(n)]
