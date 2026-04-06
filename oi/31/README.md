# Task: Liczniki (Meters) - XXXI OI Stage II

## 📝 Problem Description
The goal is to assign available water meter readings to specific meters in a way that minimizes the total cost, while ensuring each new reading is not smaller than the current state of the meter.

* **Full Statement:** [Szkopuł - LIC](https://szkopul.edu.pl/problemset/problem/9Xg3SiF9DZ-Xn65OWbu9B42J/site/)
* **Score:** 100/100 points

## 💡 Solution Strategy
The problem is solved using a **Greedy Approach** combined with efficient data structures:

1. **Sorting:** Meters are sorted by their unit cost in descending order. This ensures that we prioritize finding the smallest possible valid readings for the most expensive meters first.
2. **Data Structure:** We use `std::multiset` to store available readings for the current month.
3. **Binary Search:** For each meter, we use `multiset::lower_bound` to find the smallest reading that satisfies the condition (`new_reading >= current_reading`).
4. **Efficiency:** This approach ensures an optimal $O(M \cdot N \log N)$ time complexity, which easily fits within the time limits.

## 🚀 How to run
```bash
g++ -O3 lic.cpp -o lic
./lic < input_file

"README assisted by AI for clarity and professional formatting"
