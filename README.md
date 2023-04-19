# push_swap

<img width="1280" alt="Screenshot 2023-04-19 at 04 09 45" src="https://user-images.githubusercontent.com/115113929/232948436-054f86ed-46a7-4306-b589-3948581fad64.png">
💫 push_swap visualizer: https://github.com/o-reo/push_swap_visualizer 💫

### ***Because swap_push isn’t as natural***

This program sorts data on a stack, using radix, with a limited set of operations. The goal is to use the lowest possible number of actions.

 ***Operations include:***
 - sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
 - sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
 - ss : sa and sb at the same time.
 - pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
 - pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
 - ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
 - rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
 - rr : ra and rb at the same time.
 - rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
 - rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
 - rrr : rra and rrb at the same time.
