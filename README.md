# push_swap

A program that find the least moves to sort a stack of numbers instead of the fastest.
In this project, I've explored the concept of using doubly circular linked lists as my stacks.

### Rules

- You have 2 stacks named a and b.
- At the beginning:
	- Stack a contains a random number of unique negative and/or positive integers.
	- Stack b is empty.
- The goal is to sort the numbers in stack a in ascending order.
- To achieve this, you have the following operations at your disposal:
	- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
	- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
	- ss : sa and sb at the same time.
	- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
	- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
	- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
	- rr : ra and rb at the same time.
	- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
	- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
	- rrr : rra and rrb at the same time.

### Bonus

Make a checker that checks the validity of the output of the push swap program.

### Resources

- [libft](https://www.github.com/KrunchiZ/libft)
