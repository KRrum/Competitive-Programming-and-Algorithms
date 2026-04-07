Knights (Rycerze) - XXXI OI Solution

This is a solution for the "Knights" task from the 2nd stage of the 31st Polish Olympiad in Informatics (OI). The program calculates the optimal sword weights a knight can obtain while navigating a graph within a limited time $d$.

Problem Description

The goal is to find the maximum possible weight for each of the $k$ swords such that there still exists a path from vertex $1$ to $n$ with a total length not exceeding $d$, allowing the collection of all swords with the determined weights.

Algorithm

The solution is based on a greedy approach combined with the Meet-in-the-middle technique using bitmasks:

Greedy Strategy: Each sword is processed individually, attempting to assign the highest possible weight available.

Bitmask BFS: For each vertex, we maintain a state (v, mask), where mask represents the set of swords already collected with previously determined weights.

Meet-in-the-middle: To optimize performance, we perform two BFS traversals:

Starting from the initial vertex ($1$).

Starting from the target vertex ($n$).

Edge Verification: For every edge, we check if it connects states from both BFS traversals such that the total step count is $\le d$, and the bitwise union of the masks covers all required swords.

Complexity

Time Complexity: $O(k \cdot (n \cdot 2^k + m \cdot 2^k))$

Space Complexity: $O(n \cdot 2^k)$

Compilation and Execution

To compile the program, use the g++ compiler (C++17 standard or newer recommended):

g++ -O3 rycerze_final.cpp -o rycerze


To run the program:

./rycerze < test.in


File Structure

rycerze_final.cpp – Main source code with English comments.

README.md – Project documentation.

Note: This README and its formatting were assisted by AI to ensure clarity and professional presentation of the technical logic.
Task Link

The full task description is available on the Szkopuł platform.
