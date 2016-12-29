large = [1,0]

def fn(x):
    j =x
    global large
    n = 0
    while x!= 1:
        if x %2 == 0:
            x = x/2
            n += 1
        else:
            x = (3*x+1)/2
            n+=2
    if large[1]<n:
        large = [j,n]
        print(large)
    return n

for i in range(1,10000000):
    fn(i)
