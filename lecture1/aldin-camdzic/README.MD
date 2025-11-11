# Lecture 1

Here are my solutions for the lecture 1 problems.

## Setup Issues

When I first cloned this repo I had some problems getting everything to work:

The `.clangd` file had this path:
```
CompileFlags:
  Add:
    - -I/home/contraboi/Documents/Work/academy/lib
    - -std=c11
```

It wouldn't recognize `paroot.h` no matter what I did. I had to change it to my actual Windows path:
```
CompileFlags:
  Add:
    - -IC:/Users/Aldin/Desktop/academy/lib
    - -std=c11
```

Then it worked. Also, the whole project was being detected as "Objective-C++" instead of C, so I had to add `-xc` at the end of the `.clangd` file and then everything was fine.

## Mario Required

This one prints a pyramid using # symbols. You input a number between 1-8 and it makes a right-aligned pyramid.

I used a do-while loop to keep asking for input until it's valid. Then I have two nested loops - one for spaces and one for the hashes.

## Mario Optional

Same as the first Mario but with two pyramids side by side with a gap between them. I just added another loop to print the second pyramid and put two spaces in the middle.

## Cash

This calculates the minimum coins needed to make change. The math was a bit tricky with the division and modulo operators but once I got it working it made sense.

One thing I noticed - the task description says that input `1.99` should return `19` coins, but that's wrong. It actually returns `13` coins (7 quarters + 2 dimes + 4 pennies = 1.99$). I wrote a Python script to test 100 different inputs and they all passed correctly, so I'm confident my solution is right.

## Credit Card

This one was the hardest. It checks if a credit card number is valid using something called Luhn's algorithm. The task description mentioned it but I had to research it online and study how it actually works. You have to double every other digit from the right and add everything up, then check if it's divisible by 10.

After validating, it checks the length and starting digits to figure out if it's AMEX, MASTERCARD, or VISA.

I used strings to handle the card number because it's easier to work with individual digits that way.

---

All programs compile and run correctly with the test cases I tried.
