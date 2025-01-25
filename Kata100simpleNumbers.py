def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def generate_primes(limit):
    primes = []
    number = 2
    while len(primes) < limit:
        if is_prime(number):
            primes.append(number)
        number += 1
    return primes

primes = generate_primes(100)
for prime in primes:
    print prime
