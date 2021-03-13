# Nesting-Depth (5pts, 11pts)

# Problem

tl;dr: Given a string of digits S, insert a minimum number of opening and closing parentheses into it such that the resulting string is balanced and each digit d is inside exactly d pairs of matching parentheses.

Let the nesting of two parentheses within a string be the substring that occurs strictly between them. An opening parenthesis and a closing parenthesis that is further to its right are said to match if their nesting is empty, or if every parenthesis in their nesting matches with another parenthesis in their nesting. The nesting depth of a position p is the number of pairs of matching parentheses m such that p is included in the nesting of m.

For example, in the following strings, all digits match their nesting depth: `0((2)1)`, `(((3))1(2))`, `((((4))))`, `((2))((2))(1)`. The first three strings have minimum length among those that have the same digits in the same order, but the last one does not since `((22)1)` also has the digits `221` and is shorter.

Given a string of digits `S`, find another string `S'`, comprised of parentheses and digits, such that:

- all parentheses in `S'` match some other parenthesis,
- removing any and all parentheses from `S'` results in `S`,
- each digit in `S'` is equal to its nesting depth, and
- `S'` is of minimum length.

### Input

The first line of the input gives the number of test cases, T. T lines follow. Each line represents a test case and contains only the string S.
### Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the string S' defined above.
### Limits

- Time limit: 20 seconds per test set.
- Memory limit: 1GB.
- 1 ≤ T ≤ 100.
- 1 ≤ length of S ≤ 100.

### Test set 1 (Visible Verdict)
Each character in S is either 0 or 1.

### Test set 2 (Visible Verdict)
Each character in S is a decimal digit between 0 and 9, inclusive.

# Sample

## Input 
```
4
0000
101
111000
1
```
  
## Output
```
Case #1: 0000
Case #2: (1)0(1)
Case #3: (111)000
Case #4: (1)
```
  

The strings `()0000()`, `(1)0(((()))1)` and `(1)(11)000` are not valid solutions to Sample Cases #1, #2 and #3, respectively, only because they are not of minimum length. In addition, `1)(` and `)(1` are not valid solutions to Sample Case #4 because they contain unmatched parentheses and the nesting depth is `0`


# Analysis

## Test Set 1

To solve Test Set 1, we can put an opening parenthesis before each group of 1s and a closing parenthesis after.

We can use the following trick to simplify the implementation: prepend and append one extra `0` to `S`. Then the implementation is just replacing `01` with `0(1` and `10` with `1)0`, which can be written in one line of code in some programming languages. Don't forget to remove the extra `0`s from the end of the resulting string!

## Test Set 2

For convenience, let's once again use the trick described above: prepend and append extra `0`s to `S`, and then scan `S` from left to right.

Suppose we see some number `A` immediately followed by some larger number `B` and suppose all of the previously inserted parentheses would leave `A` at the right nesting depth — that is, there are exactly A unmatched opening parentheses preceding `A`, and no unmatched closing parentheses. For `B` to be at nesting depth `B` we need to add at least `B - A` opening parentheses. We can just do that and nothing else, to keep the final string length minimal. Any additional opening parentheses we would add would need to be closed before B, which would needlessly lengthen the string. Similarly, if we see some number `A` immediately followed by some smaller number `B`, we can just insert `A - B` closing parentheses. And in the case when `A` is equal to `B`, we don't need to add anything.

We don't need any parentheses before the temporary `0` in the beginning, or after the one in the end, so we can just drop them before printing the result.

Since we only add p parentheses when at least p are needed, the resulting string is of minimum length.
An inefficient but fun solution

The problem can be solved using only string replacements. First, replace each digit `D` with `D` (s, then the digit itself, then `D` )s. Then eliminate all instances of `)(`, collapsing the string each time, until there are no more to remove.

Here's a Python3 implementation:
```
for C in range(int(input())):
  rawstr = ''.join([int(x) * '(' + x + ')' * int(x) for x in str(input())])
  for _ in range(9):
```
