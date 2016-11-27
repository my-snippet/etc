# Refrences : https://ko.wikipedia.org/wiki/%ED%80%B5_%EC%A0%95%EB%A0%AC


def quicksort(x):
     if len(x) <= 1:
         return x
 
     pivot = x[len(x) // 2]
     less = []
     more = []
     equal = []

     for a in x:
         if a < pivot:
             less.append(a)
         elif a > pivot:
             more.append(a)
         else:
             equal.append(a)
 
     return quicksort(less) + equal + quicksort(more)


def quick3(x):

    def _quick3(x, len_x):
        if len_x <= 1:
            return x

        pivot = x[len_x // 2]
        less = []
        more = []

        for i in x:
            if i < pivot:
                less.append(i)
            elif i > pivot:
                more.append(i)

        return _quick3(less, len(less)) + [pivot] + _quick3(more, len(more))

    return _quick3(x, len(x))


def quick2(a):
    if a == []:
        return []
    return quick2([i for i in a[1:] if i <= a[0]]) + [a[0]] + \
            quick2([i for i in a[1:] if i > a[0]])


def quick(a):
    
    def _quick(l, r):
        left = l
        right = r
        pivot = a[(l + r) // 2]
    
        while(l <= r):
            while(a[l] < pivot):
                l += 1
            while(a[r] > pivot):
                r -= 1
    
            # if l < r, a little bit annoying
            if(l <= r):
                print(a[r], a[l])
                tmp = a[r]
                a[r] = a[l]
                a[l] = tmp

                # this is invalid because of reference(pointer)
                #a[r] += a[l]
                #a[l] = a[r] - a[l]
                #a[r] -= a[l]
                l += 1
                r -= 1

        if left < r:
            _quick(left, r)
    
        if l < right:
            _quick(l, right)

    _quick(0, len(a)-1)
    return a

#print(quick3([6,5,3,4]))
#print(quick2([6,5,3,5,1]))
#print(quicksort([6,3,5,4,6,8,8,3,3,2,1,1,3,6,7,2,6]))
print(quick2([i for i in range(996)]))
print(quick2([i for i in reversed(range(996))]))

#print(quick3([i for i in reversed(range(10000))]))
#quicksort([i for i in range(100000)])
