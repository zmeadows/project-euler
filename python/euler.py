def primes():
  yield 2
  yield 3
  i = 1
  while True:
    j=(6*i)-1
    k=(6*i)+1
    if isprime(j):
      yield j
    if isprime(k):
      yield k
    i+=1

def isprime(n):
  i=3
  while (i * i <= n):
    if (n % i == 0):
      return False
    else: 
      i+=2
  return True

def digitsof(n):
  for i in str(n):
    yield int(i)

def lpd(n): # Lowest Prime Divisor
  for i in primes():
    j = n % i
    if (j == 0):
      return i

def pfacs(n): # Prime Factors
  pf = []
  while (n != 1):
     p = lpd(n)
     pf.append(p)
     n=n/p
  return pf

def bico(n,k): # Binomial Coefficient
  c = 1.0
  i = 1.0
  while (i < k+1.0):
    c *= ((n-k+i)/i)
    i+=1.0
  return int(c)

def powers(n):
    i = 1
    while True:
        yield i**n
        i += 1

memo = {0:0, 1:1}
def fib(n): # fibonacci sequence
    if not n in memo:
        memo[n] = fib(n-1) + fib(n-2)
    return memo[n]
