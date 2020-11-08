# Learnings
- Default vs Value iniatilization:
    Default initialization doesn't overwrite remaining stack bits.
    ```
        # default initialization
        int *foo = new int[length];
        foo[0] # != 0 
    ```
    Value initalization initializes the array with a clean stack and overwrites all entries with 0.
    ```
        # value initialization
        int *foo = new int[length];
        foo[0] # == 0
    ```

# Core Data Structures, Algorithms, and Concepts
| Data Structures        | Algorithms           | Concepts                |
| ---------------------- | -------------------- | ----------------------- |
| Linked Lists           | Breadth-First Search | Bit Manipulation        |
| Trees, Tries, & Graphs | Depth-Frist Search   | Memory (Stack vs. Heap) |
| Stacks & Queues        | Binary Search        | Recursion               |
| Heaps                  | Merge Sort           | Dynamic Programming     |
| Vector/ArrayLists      | Quick Sort           | Big O Time & Space      |
| ~~Hash Tables~~        |                      |                         |