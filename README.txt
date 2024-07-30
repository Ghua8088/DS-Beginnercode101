This is a C++ program that implements a hash table using an array of linked lists. Here's a detailed explanation of the code:
1. The program starts by defining two classes: `record` and `Hashtab`. The `record` class has four members:
`registernumber`, `name`, `course`, and `dob`. It also has three methods: `get()`, `update()`, and `display()`.
The `Hashtab` class has a private member variable `L`, which is an array of `List` objects. It also has public
method for inserting, getting, removing, and printing the elements in the hash table.
2. The program then defines a function `Hash()` that takes a `record` object as input and returns an index in the
`L` array based on the value of the `registernumber` field. This function is used to determine the location of
each element in the hash table.
3. In the `main()` function, the program initializes a `Hashtab` object called `Sec_k` with a default size of 100.
It then enters an infinite loop where it prompts the user to enter commands, and based on the command, it performs
the following actions:
        * If the command is 1, the program inserts a new element into the hash table using the `insert()` method.
        * If the command is 2, the program searches for an element in the hash table using the `get()` method and displays
the found element.
        * If the command is 3, the program removes an element from the hash table using the `remove()` method and displays
the removed element.
        * If the command is 4, the program prints all the elements in the hash table using the `print()` method.
        * If the command is 5, the program exits successfully.
4. The program uses `switch()` statement to handle each command differently. For example, when the user enters
`1`, the program calls the `insert()` method with a reference to a `record` object `tmp`. When the user enters
`2`, the program searches for an element in the hash table using the `get()` method and displays the found
element.
5. The program uses `addr` variable to store the address of the list in the `L` array where the element is
located, and then it calls the `remove()` method with the `addr` value to remove the element from the list.
6. The program also uses `cin>>running;` to read the command from the user, and then it enters the corresponding
branch of the `switch()` statement based on the command.
7. Finally, the program exits successfully when the user enters `5`.
