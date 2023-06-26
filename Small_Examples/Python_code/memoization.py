def naive_fibonacci(n):
    """
    Precondition: n >= 1

    Naive implementation of fibonacci without using
    memoization

    Returns:
        -The nth fibonacci number
    """
    if n < 1:
        print("Please enter in a valid number. Choose a number greater than or equal to 1")
    if n == 1:
        return 0
    if n == 2:
        return 1
    return naive_fibonacci(n-1) + naive_fibonacci(n-2)
    

def memoized_fibonacci(n):
    """
    Precondition: n >= 1

    Improving on the naive implementation of fibonacci
    using memoization

    Returns:
        -The nth fibonacci number
    """
    memoized_array = [None]*n
    memoized_array[0] = 0
    memoized_array[1] = 1
    if n < 1:
        print("Please enter in a valid number. Choose a number greater than or equal to 1")
    for counter in range(2,n):
        if memoized_array[counter] is None:
            memoized_array[counter] = memoized_array[counter - 1] + memoized_array[counter - 2]
    return memoized_array[n - 1]



if __name__ == "__main__":
    print("Main Section")
    user_number = input("Please enter in a number greater than or equal to 1:       ")
    print(f"Using naive implementation of fibonacci      :        {naive_fibonacci(int(user_number))}\n\n")
    print(f"Using memoization implementation of fibonacci:        {memoized_fibonacci(int(user_number))}\n\n")
    print("The naive implementation of naive implementaton runs in O(2^n) time while memoization runs in O(n) time\n\n\n\n\n")
    print("End of Small Example")
