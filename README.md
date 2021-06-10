# push_swap
Sorting data on a stack with a limited set of instructions

Final Score: 125/100

### Average 100 set speed:
575 Actions (Minimum 490 / Maximum 610)

### Average 500 set speed:
4550 Actions (Minimum 4100 / Maximum 4900)

## Algorithm explained:
I start with a dirty sorting algorithm for indexing.

Then I find the biggest "loop" which is actually the biggest valid ascending consecutive index in stack a. I could also pretty much push everything to B it wouldn't impact much on actions for large stacks.

I then push everything that isn't in the loop to stack B. For > 100 values i also make sure to push them in groups (3 for 500) to optimize navigation in the stack. This is crucial for fast large stack processing but slows down small stacks.

I then find a spot in stack A for the value i'm pushing from stack B. To find the best value to push, i loop through all values of stack B and find the closest spot in A possible (index 4 in stack B, would be between 2 and 7 in stack A for example), with the least rotation from the B value too.

You then need to rotate the stack back to the minimum index (0), and you're good to go!

## Making it even faster
If i wasn't lasy this project could be even faster:
- For groups, limit reverse rotating when pushing values to B: When you push an element with reverse rotate, you end up having to re execute that action for each value you push even if they're close together, that's because when you push a value the stack automatically goes up and not down.
- Brute force different solutions: I rewrote this project because i wasn't pleased with the first approach i took, in my first version i did try using brute forcing with different magic values that influenced the action count, you could very well implement this here by changing the initial A loop stack values to make the algorith take different paths, this would however slow the algorith down even more...
- Implement some sort of Travelling salesman problem resolving algorithm to find the true shortest path to multiple values you want to push

## Useful guides
https://github.com/VBrazhnik/Push_swap/wiki/Algorithm (I highly recomment you check this wiki out for a very simillar approach but without groups)

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
