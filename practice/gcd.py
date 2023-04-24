# Python3 program to find the sum
# of GCD of all integers up to N
# with N itself
 
# Function to Find Sum of
# GCD of each numbers
def getCount(d, n):
     
    no = n // d;
    result = no;
 
    # Consider all prime factors
    # of no. and subtract their
    # multiples from result
    for p in range(2, int(pow(no, 1 / 2)) + 1):
 
        # Check if p is a prime factor
        if (no % p == 0):
 
            # If yes, then update no
            # and result
            while (no % p == 0):
                no //= p;
                 
            result -= result // p;
 
    # If no has a prime factor greater
    # than Math.sqrt(n) then at-most one such
    # prime factor exists
    if (no > 1):
        result -= result // no;
 
    # Return the result
    return result;
 
# Finding GCD of pairs
def sumOfGCDofPairs(n):
     
    res = 0;
 
    for i in range(1, int(pow(n, 1 / 2)) + 1):
        if (n % i == 0):
 
            # Calculate the divisors
            d1 = i;
            d2 = n // i;
 
            # Return count of numbers
            # from 1 to N with GCD d with N
            res += d1 * getCount(d1, n);
 
            # Check if d1 and d2 are
            # equal then skip this
            if (d1 != d2):
                res += d2 * getCount(d2, n);
 
    return res;
 
# Driver code
if __name__ == '__main__':
     
    n = 2015;
     
    print(sumOfGCDofPairs(n));
 
# This code is contributed by Amit Katiyar