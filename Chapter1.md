# Table of Contents

1.  [Exercise 1.1](#orgcc9bb96)
    1.  [1.1: Give the output that a connectivity algorithm should produce when given the input 0-2, 1-4, 2-5, 3-6, 0-4, 6-0, 1-3](#org1f228ea)
    2.  [1.2: List all the different ways to connect two different objects for the example in Figure 1.1.](#org354b6e9)
    3.  [Describe a simple method for counting the number of sets remaining after using the union and find operations to solve the connectivity problem as described in the text.](#orgfd461ec)
2.  [Union-Find Algorithms](#org1536c58)
    1.  [Program 1.1 Quick-Find solution to connectivity problem.](#orga28a88b)
    2.  [Program 1.2: Quick-Union solution to the connectivity problem](#org2757683)

<a id="orgcc9bb96"></a>

# Exercise 1.1

<a id="org1f228ea"></a>

## 1.1: Give the output that a connectivity algorithm should produce when given the input 0-2, 1-4, 2-5, 3-6, 0-4, 6-0, 1-3

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">

<colgroup>
<col  class="org-right" />

<col  class="org-right" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-right">Input</th>
<th scope="col" class="org-right">Output</th>
<th scope="col" class="org-left">Path exists?</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-right">0-2</td>
<td class="org-right">0-2</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">1-4</td>
<td class="org-right">1-4</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">2-5</td>
<td class="org-right">2-5</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">3-6</td>
<td class="org-right">3-6</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">0-4</td>
<td class="org-right">0-4</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">6-0</td>
<td class="org-right">6-0</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">1-3</td>
<td class="org-right">No output</td>
<td class="org-left">1-4-0-6-3</td>
</tr>
</tbody>
</table>

<a id="org354b6e9"></a>

## 1.2: List all the different ways to connect two different objects for the example in Figure 1.1.

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">

<colgroup>
<col  class="org-right" />

<col  class="org-right" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-right">Input</th>
<th scope="col" class="org-right">Output</th>
<th scope="col" class="org-left">Path exist?</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-right">3-4</td>
<td class="org-right">3-4</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">4-9</td>
<td class="org-right">4-9</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">8-0</td>
<td class="org-right">8-0</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">2-3</td>
<td class="org-right">2-3</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">5-6</td>
<td class="org-right">5-6</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">2-9</td>
<td class="org-right">No output</td>
<td class="org-left">2-3-4-9 or 9-4-3-2</td>
</tr>

<tr>
<td class="org-right">5-9</td>
<td class="org-right">5-9</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">7-3</td>
<td class="org-right">7-3</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">4-8</td>
<td class="org-right">4-8</td>
<td class="org-left">&#xa0;</td>
</tr>

<tr>
<td class="org-right">5-6</td>
<td class="org-right">No output</td>
<td class="org-left">5-6</td>
</tr>

<tr>
<td class="org-right">0-2</td>
<td class="org-right">&#xa0;</td>
<td class="org-left">0-8-4-3-2 or 2-3-4-8-0</td>
</tr>

<tr>
<td class="org-right">6-1</td>
<td class="org-right">6-1</td>
<td class="org-left">&#xa0;</td>
</tr>
</tbody>
</table>

<a id="orgfd461ec"></a>

## Describe a simple method for counting the number of sets remaining after using the union and find operations to solve the connectivity problem as described in the text.

<a id="org1536c58"></a>

# Union-Find Algorithms

The first step in the process of developing an efficient algorithm to solve a given problem is to implement a simple algorithm that solves the problem.
Note: For detailed comments on the code see the chapter#.cpp file where each example is thoroughly annotated with comments

<a id="orga28a88b"></a>

## Program 1.1 Quick-Find solution to connectivity problem.

\#+begin<sub>src</sub> C++
void QuickFind() {
int i, p, q, id[N];
for (i = 0; i < N; i++) {
id[i] = i;
}
while (cin >> p >> q) {
int t = id[p];  
 if (t == id[q])
continue;
for (i = 0; i < N; i++) {
if (id[i] == t)
id[i] = id[q];
}
cout << p << &ldquo;-&rdquo; << q << endl;
}
}
\#+end<sub>src</sub> C++

1.  Property 1.1: The Quick Find algorithm executes at least M N instructions to solve a connectivity problem with N objects that involves M union operations.

    Proof: For each of the M union operations, we iterate the for loop N times. Each iteration requires at least one instruction (if only to check whether the loop is finished).
    So this algorithm is O(N<sup>2</sup>)

<a id="org2757683"></a>

## Program 1.2: Quick-Union solution to the connectivity problem

If we replace the body of the while loop in <a id="org0636a14"></a> by the code in the while loop below we have a program that meets the same specifications as QuickFind but does less computation for the union operation at the expense of more computation for the find operation. The for loops and subsequent if statement in this code specify the necessary and sufficient conditions on the id array for p and q to be connected. The assignment statement id[i] = j implements the union operation.
\#+begin<sub>src</sub> C++
void QuickUnion() {
int i, j, p, q, id[N];
for (i = 0; i < N; i++) {
id[i] = i;
}
while (cin >> p >> q) {
for (i = p; i != id[i]; i = id[i])
;
for (j = q; j != id[j]; j = id[j])
;
if (i == j)
continue;
id[i] = j;
cout << &ldquo; &rdquo; << p << &ldquo; &rdquo; << q << endl;
}
}
\#+end<sub>src</sub> C++

1.  Property 1.2: For M > N, the quick-union algorithm could take more than MN/2 instructions to solve a connectivity problem with M pairs of N object.

    Proof: Suppose that pairs come in the order 1-2, 2-3, &#x2026; so on. After N - 1 such pairs, we have N objects all in the same set and the tree that is formed by the quick union algorithm is a straight line with N pointing to N - 1, which points to N - 2 until we reach 1. To execute the find operation for object N, the program has to follow N -1 Pointers. Thus the average number of pointers followed for the first N pairs is:
    1 + 2 + 3 + 4 &#x2026; N = n(n+1)/2
    (0 + 1 + &#x2026; + (N-1))/N = (N-1)(N)/2N = (N-1)/2

    Now suppose that the remainder of the pairs all connect N to some other object. The find operation for each of these pairs involves at least (N-1) pointers. The grand total for the M find operations for this sequence of input pairs is certainly greater than MN/2.
