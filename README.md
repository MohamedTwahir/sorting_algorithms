# 0x1B. C - Sorting algorithms & Big O
Sorting algorithm is an alorithm that puts elements of a list into an order.
The order itself can be:
	* numerical order
	* lexicographical order
	* ascending or descending order
Efficient sorting is important for optimizing the efficiency of other algorithms(search and merge) that require input data to be in sorted lists.
Sorting is also useful in canonicalization(normalization) of data into human readable form.
Requirements for output of any sorting algorithm:
 * output should be monotonic order - smaller/larger than the previous element
 * permutation output(reordering, yet retaining all of the original elements) of the input.
Input data should be stored in a data structure which allows random access rather that one that allows only allows sequential access.

Comparison sorting algorithms have a fundamental requirement of Ω(n log n) comparisons (some input sequences will require a multiple of n log n comparisons, where n is the number of elements in the array to be sorted). Algorithms not based on comparisons, such as counting sort, can have better performance.

Some algorithms concepts that i came through while doing these tasks include:
* big O notation
* divide-and-conquer algorithms
* data structures such as heaps and binary trees
* randomized algorithms
* best, worst and average case analysis
* time-space tradeoffs
* upper and lower bounds.
# Sorting algorithms can be classified by:
* Computational complexity:
	* Best, worst and average case behavior in terms of the size of the list. For typical serial sorting:
		~ good behavior = O(n log n)
		~ parallel sort = O(log^2 n)
		~ bad behavior = O(n^2) 
		~ serial sort = O(n)
		~ Optimal parallel sorting is O(log n)
	* Swaps for "in-place algorithms.
* Memory usage (and use of other computer resources). In particular, some sorting algorithms are "in-place". Strictly, an in-place sort needs only O(1) memory beyond the items being sorted; sometimes O(log n) additional memory is considered "in-place".
* Recursion: Some algorithms are either recursive or non-recursive, while others may be both (e.g., merge sort).
* Stability: stable sorting algorithms maintain the relative order of records with equal keys (i.e., values).
* Whether or not they are a comparison sort. A comparison sort examines the data only by comparing two elements with a comparison operator.
* General method: insertion, exchange, selection, merging, etc. Exchange sorts include bubble sort and quicksort. Selection sorts include cycle sort and heapsort.
* Whether the algorithm is serial or parallel. The remainder of this discussion almost exclusively concentrates upon serial algorithms and assumes serial operation.
* Adaptability: Whether or not the presortedness of the input affects the running time. Algorithms that take this into account are known to be adaptive.
* Online: An algorithm such as Insertion Sort that is online can sort a constant stream of input.
# Stability
Stable sort algorithms sort equal elements in the same order that they appear in the input. For example, in the card sorting example to the right, the cards are being sorted by their rank, and their suit is being ignored. This allows the possibility of multiple different correctly sorted versions of the original list. Stable sorting algorithms choose one of these, according to the following rule: if two items compare as equal (like the two 5 cards), then their relative order will be preserved, i.e. if one comes before the other in the input, it will come before the other in the output(first in first out).

Stability is important to preserve order over multiple sorts on the same data set. For example, say that student records consisting of name and class section are sorted dynamically, first by name then by class section. If a stable algorithm is used in both cases, the sort-by-class-section operation will not change the name order; with an unstable sort, it could be that sorting by section shuffles the name order, resulting in a nonalphabetical list of students.
One application for stable sorting algorithms is sorting a list using a primary and secondary key. For example, suppose we wish to sort a hand of cards such that the suits are in the order clubs (♣), diamonds (♦), hearts (♥), spades (♠), and within each suit, the cards are sorted by rank. This can be done by first sorting the cards by rank (using any sort), and then doing a stable sort by suit.
# Simple sorts
Two of the simplest sorts are insertion sort and selection sort, both of which are efficient on small data, due to low overhead, but not efficient on large data. Insertion sort is generally faster than selection sort in practice, due to fewer comparisons and good performance on almost-sorted data, and thus is preferred in practice, but selection sort uses fewer writes, and thus is used when write performance is a limiting factor.

* Insertion sort
Insertion sort is a simple sorting algorithm that is relatively efficient for small lists and mostly sorted lists, and is often used as part of more sophisticated algorithms. It works by taking elements from the list one by one and inserting them in their correct position into a new sorted list similar to how one puts money in their wallet.In arrays, the new list and the remaining elements can share the array's space, but insertion is expensive, requiring shifting all following elements over by one. Shellsort is a variant of insertion sort that is more efficient for larger lists.

* Selection sort
Selection sort is an in-place comparison sort. It has O(n2) complexity, making it inefficient on large lists, and generally performs worse than the similar insertion sort. Selection sort is noted for its simplicity, and also has performance advantages over more complicated algorithms in certain situations.

The algorithm finds the minimum value, swaps it with the value in the first position, and repeats these steps for the remainder of the list.[23] It does no more than n swaps, and thus is useful where swapping is very expensive.

# Merge sort
Merge sort takes advantage of the ease of merging already sorted lists into a new sorted list. It starts by comparing every two elements (i.e., 1 with 2, then 3 with 4...) and swapping them if the first should come after the second. It then merges each of the resulting lists of two into lists of four, then merges those lists of four, and so on; until at last two lists are merged into the final sorted list.
It is the first that scales well to very large lists, because its worst-case running time is O(n log n). It is also easily applied to lists, not only arrays, as it only requires sequential access, not random access. However, it has additional O(n) space complexity, and involves a large number of copies in simple implementations.
# Heap sort
Heapsort is a much more efficient version of selection sort. It also works by determining the largest (or smallest) element of the list, placing that at the end (or beginning) of the list, then continuing with the rest of the list, but accomplishes this task efficiently by using a data structure called a heap, a special type of binary tree.
Once the data list has been made into a heap, the root node is guaranteed to be the largest (or smallest) element. When it is removed and placed at the end of the list, the heap is rearranged so the largest element remaining moves to the root. Using the heap, finding the next largest element takes O(log n) time, instead of O(n) for a linear scan as in simple selection sort. This allows Heapsort to run in O(n log n) time, and this is also the worst case complexity.
# Quick Sort
Quicksort is a divide-and-conquer algorithm which relies on a partition operation: to partition an array, an element called a pivot is selected
All elements smaller than the pivot are moved before it and all greater elements are moved after it. This can be done efficiently in linear time and in-place. The lesser and greater sublists are then recursively sorted. This yields average time complexity of O(n log n), with low overhead, and thus this is a popular algorithm. Efficient implementations of quicksort (with in-place partitioning) are typically unstable sorts and somewhat complex, but are among the fastest sorting algorithms in practice. Together with its modest O(log n) space usage, quicksort is one of the most popular sorting algorithms and is available in many standard programming libraries.
The important caveat about quicksort is that its worst-case performance is O(n2); while this is rare, in naive implementations (choosing the first or last element as pivot) this occurs for sorted data, which is a common case. The most complex issue in quicksort is thus choosing a good pivot element, as consistently poor choices of pivots can result in drastically slower O(n2) performance, but good choice of pivots yields O(n log n) performance, which is asymptotically optimal. For example, if at each step the median is chosen as the pivot then the algorithm works in O(n log n). Finding the median, such as by the median of medians selection algorithm is however an O(n) operation on unsorted lists and therefore exacts significant overhead with sorting. In practice choosing a random pivot almost certainly yields O(n log n) performance.

If a guarantee of O(n log n) performance is important, there is a simple modification to achieve that. The idea, due to Musser, is to set a limit on the maximum depth of recursion.[32] If that limit is exceeded, then sorting is continued using the heapsort algorithm.
#Shell sort
t improves upon insertion sort by moving out of order elements more than one position at a time. The concept behind Shellsort is that insertion sort performs in O(kn) time, where k is the greatest distance between two out-of-place elements. This means that generally, they perform in O(n2), but for data that is mostly sorted, with only a few elements out of place, they perform faster. So, by first sorting elements far away, and progressively shrinking the gap between the elements to sort, the final sort computes much faster. One implementation can be described as arranging the data sequence in a two-dimensional array and then sorting the columns of the array using insertion sort.
# Bubble sort
Bubble sort is a simple sorting algorithm. The algorithm starts at the beginning of the data set. It compares the first two elements, and if the first is greater than the second, it swaps them. It continues doing this for each pair of adjacent elements to the end of the data set. It then starts again with the first two elements, repeating until no swaps have occurred on the last pass.
This algorithm's average time and worst-case performance is O(n2), so it is rarely used to sort large, unordered data sets. Bubble sort can be used to sort a small number of items (where its asymptotic inefficiency is not a high penalty). Bubble sort can also be used efficiently on a list of any length that is nearly sorted (that is, the elements are not significantly out of place).
## Big O 
It is the simplified analysis of an algorithm's efficiency.
Big O gives us:
	* Algorithm complexity in terms of the input size, N
	* Machine Independent - gives a way to extract machines effeciency.
	*  basic computer steps
	* Time & space
There are couple of ways to determine an algorithms efficiency.
We can determine:
		* worst-case
		* best-case
		* average-case
In bigO notation we typically look at the worst case.
* General rules
1. Big O notation ignores constants
 a function running time of 5n is stated as O(n)
2. Certain terms "dominate" others:
O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(2^n) < O(n!)
We ignore or drop low-order terms when dominated by high order ones
# Examples
* Constant time
Imagine we have the following code:
x = 5 + (15 * 20);
notice it is independent of input size N
bigO will be O(1)
Imagine this other code:
x = 5 + (15 * 20);
y = 15 - 2;
print x + y;
You will notice each statement has its execution time.
Total time = O(1) + O(1) + O(1) = 3 * O(1)
but we ignore the constants so the big O will be O(1)
* linear time
Suppose we have the following for loop that prints a number in particular range
for x in range (0, n):
	print x;

we now the print statement will be O(1) so the block of statements will be N * O(1)
In other words N * O(1) = O(N)

Here is another example:
y = 5 + (15 * 20);
for x in range (0, n):
	print x;
The first statement will be O(1) and we know the for loop will be O(N)
So the total time = O(1) + O(N) but we drop the lower terms at the expense of higher terms so the bigO will be O(N).
* quadratic time
In the below example of code:
for x in range (0, n):
	for y in range (0, n):
		print x * y;
From that the print statement will be executed O(N) * O(N) which will be O(N^2)
   
Another last statement assuming its bigO has been deduced:
if x > 0: //O(1)
else if x < 0: //O(logn)
else:// O(N^2)

