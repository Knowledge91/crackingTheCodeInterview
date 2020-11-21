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
- Use C++11 **smart pointers** instead of `new` and `delete`.
    ```
    #include <memory>

    {
        // Use make_shared when possible. foo ref count is 1.
        std::shared_ptr<Foo> foo = std::make_shared<Foo>();
        {
            std::unique_ptr<Bar> bar = std::make_unique<Bar>();
            // Initialize with copy constructor. Increments ref count of foo to 2.
            std::shared_ptr<Foo> foo2(foo);
        } // foo is deallocated here.
        // bar has ref count 1 and points to an existing Foo instance.
    } // bar is deallocated here.
    ```

# Core Data Structures, Algorithms, and Concepts
| Data Structures                | Algorithms           | Concepts                |
| ------------------------------ | -------------------- | ----------------------- |
| ~~Linked Lists~~               | Breadth-First Search | Bit Manipulation        |
| ~~Trees~~, ~~Tries~~, & Graphs | Depth-Frist Search   | Memory (Stack vs. Heap) |
| Stacks & Queues                | Binary Search        | Recursion               |
| Heaps                          | Merge Sort           | Dynamic Programming     |
| Vector/ArrayLists              | Quick Sort           | Big O Time & Space      |
| ~~Hash Tables~~                |                      |                         |