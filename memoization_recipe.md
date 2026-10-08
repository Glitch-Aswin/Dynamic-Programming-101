# Memoization Recipe

Two simple steps:

1. Make it work with recursion
2. Make it efficient

## 1. Make it work with recursion

### 1.a Visualise the problem as a tree

- DP often involves problems that can be decomposed into smaller problems.
- The nodes of the tree become the problem, and the edges represent shrinking that problem into simpler sub-problems.
- Ask yourself: "What are the choices at each step, and what does the problem look like after making one?" Each choice is an edge to a child node.
- Example: `fib(5)` has children `fib(4)` and `fib(3)`.

```
            fib(5)
           /      \
       fib(4)    fib(3)
       /    \     /   \
   fib(3) fib(2) fib(2) fib(1)
     ...
```

- Notice that `fib(3)` and `fib(2)` appear more than once. These repeated sub-problems are what memoization will remove.

### 1.b Implement the tree using recursion

- The leaf nodes become the base cases (the smallest inputs that can be answered directly, e.g. `fib(0) = 0`, `fib(1) = 1`).
- Each recursive call is an edge to a child; combine the children's results to get the answer for the current node.

```cpp
int fib(int n) {
    if (n <= 1) return n;          // base case
    return fib(n - 1) + fib(n - 2);
}
```

- Without memoization this is exponential, roughly O(2^n) time.

### 1.c Test

- Check the base cases and a few small inputs by hand before optimising.
- Keep these tests; they confirm the memoized version still gives the same answers.

## 2. Make it efficient (memoization)

### 2.a Add a memo object

- The object should be shared by all the recursive calls (pass it by reference, or make it global or a class member).
- Typically an array, `vector`, or `unordered_map` keyed by the function arguments.
- If the function has several changing arguments, the key must include all of them (e.g. `pair<int,int>` or a 2D array).

### 2.b Add a base case to return the memo values

- This is on top of the tree base cases.
- If the key is already in the memo, return the stored value immediately instead of recomputing.

### 2.c Store return values into the memo

- Store the return values for the values that are not there yet.
- Finally, return the memoized value.

```cpp
long long fib(int n, unordered_map<int, long long>& memo) {
    if (memo.count(n)) return memo[n];   // 2.b memo base case
    if (n <= 1) return n;                // tree base case
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);  // 2.c store
    return memo[n];
}
```

- With memoization each distinct sub-problem is computed once, so `fib` drops to O(n) time and O(n) space.

## Quick Checklist

- Can the problem be broken into smaller versions of itself?
- Are the same sub-problems repeated in the tree?
- What are the base cases?
- What uniquely identifies a sub-problem (the memo key)?
