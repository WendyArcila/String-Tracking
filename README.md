# String Tracking: Implementations and Analysis
This repository contains three different implementations for tracking observed strings. Each implementation offers the same functionality but uses different approaches to store and verify the strings. Below are the implementations along with their analysis of time and memory complexity.

## Implementation 1
Description
This implementation uses a list to store the observed strings. Each time a new string is added, it is appended to the end of the list.

Complexity Analysis
add(): O(n * m)
check(): O(n * m)
Memory Cost: O(n)

## Implementation 2
Description
In this implementation, an ordered vector is used to store the observed strings.

Complexity Analysis
add(): O(m * logn)
check(): O(m * logn)
Memory Cost: O(n)

## Implementation 3
Description
The third implementation uses a Trie data structure to store the observed strings.

Complexity Analysis
add(): O(m)
check(): O(m)
Memory Cost: O(W^m)

## General Considerations
All implementations are case-insensitive.
Time analysis is performed using Big O notation.
It is assumed that m is the size of the largest string and n is the size of the list or vector.
Memory cost is calculated considering the additional memory used in relation to the size of the input data.





