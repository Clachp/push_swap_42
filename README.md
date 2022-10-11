# push_swap_42

This programm allows to sort from lowest to highest a list of integers sent in a stack called "a" with the smallest amount of moves instructions, helping with another stack called "b". 

## Install
Clone the repository then : 

```make```

## Run
``` ./push_swap <add a list of integers separated by spaces>```

ex :

```./push_swap 78 -32 0 -6584 5 6```

## output

The programm displays the shortest list of moves to sort the list :
```
ra
pb
pb
pb
pa
ra
pa
pa
rra
```
## moves definitions

ra / rb = rotate a / rotate b : take the number on top of a/b to the bottom of the stack

rra /rrb = reverse rotate a/b : take the number at the bottom of the stack to the top

pa = Put the top number of stack a on the top of stack b

pb = Put the top number of stack b on the top of stack a
