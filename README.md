# isSorted-and-Sorting-Study
Completed Assignment for CS210-11 Class. This contains 4 sorting functions: bubbleSort, insertionSort, selectionSort, and quickSort.

## Explanation:
  ### isSorted: 
  The function iterates through the whole list once, and compares each element to the next. If an element with a smaller index holds a greater value than the next element, then it will output False. Otherwise, it will output True.
  ### bubbleSort: 
  The function iterates through the entire list n amount of times. In each iteration, it basically drags from left to right the greatest value. Visualizing it, it kinda looks like the pointer is constantly bubbling to the right of the list. This function is further optimized by keeping track of each iteration’s switch boolean. If no switch occurred in an iteration, it logically means that every element is arranged in order, so it terminates before it can start the next loop.
  ### selectionSort:
  In a way, it’s kind of like the opposite of bubbleSort. It iterates through the entire list an n amount of times. During each iteration, it keeps track of the smallest value, and then swaps the ith element with the element with the smallest value (i being the iteration number).
  ### insertion Sort:
  The function sorts the lists, starting with elements from the left side and working its way to the right. When it picks up element i, it works itself backwards and constantly adjusts the elements to the left of i until they are all sorted. Then, it moves onto element i + 1 and repeats the process.
  ### quickSort:
  This is a recursive function that repeatedly calls itself and another function, cutting the list into many easily-sortable portions. The bulk of its activity is achieved through another function, partition. Partition grabs a pivot (in this case, the last element of the portion it was assigned), and then sorts the list so that the smaller values are on the left of the pivot, and greater values are on the right of the pivot. (Note that the pivot is the only element that is truly sorted). Now that there are two unsorted sections on either side of the pivot, quickSort is called onto both portions, and it repeats this process.
