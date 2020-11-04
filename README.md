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