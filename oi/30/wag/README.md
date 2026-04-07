Task: Wagony (Wagons) - XXX OI Stage II

📝 Problem Description

The goal is to partition a train of $n$ wagons into individual units with the minimum total cost. Each split of a segment of size $k$ into two segments $i$ and $j$ ($i+j=k$) is valid only if the difference between the segment sizes is no greater than $d$ ($|i-j| \le d$). The cost of each split is calculated using a specific modular function.

Full Statement: Szkopuł - WAG

Score: 100/100 points

💡 Solution Strategy

The solution uses Dynamic Programming with Memoization combined with a restricted search space around the midpoint:

Recursive Splitting: The function F(n) recursively finds the optimal split point by checking candidates near the middle ($n/2 \pm d$).

Memoization: An unordered_map<unsigned long long, unsigned long long> is used to store results for large values of $n$ (up to $10^{18}$), preventing redundant calculations.

Cost Function: The modular cost calculation is encapsulated in the cost_function to ensure clarity and avoid naming conflicts with standard libraries.

Efficiency: This strategy results in an efficient $O(d \log n)$ performance, which easily handles the massive input constraints.

🚀 How to run

g++ -O3 wag.cpp -o wag
./wag < input_file


Note: This README and its formatting were assisted by AI to ensure clarity and professional presentation of the technical logic.
