# Cash Required

Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents). 
You’ll need to pay them their “change,” the amount leftover after paying for the cost of the candy. 
When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, 
lest you run out (or annoy the customer!). In a file called cash.c in a folder called cash, implement a 
program in C that prints the minimum coins needed to make the given amount of change, in cents, as in the below:

```
Change owed: 25
Output: 1
```
But prompt the user for an int greater than 0, so that the program works for any amount of change:

```
Change owed: 70
Output: 4
```

Re-prompt the user, again and again as needed, if their input is not greater than or equal to 0 (or if their input isn’t an int at all!).

## Specification

- Prompt the user for a non-negative dollar amount (e.g., `0.41`).
- Treat the input as dollars and convert to cents (rounded to nearest cent).
- Compute the minimum number of coins using denominations 25, 10, 5, and 1.
- Output only the number of coins (as an integer) followed by a newline.

## Greedy Strategy (U.S. coins)

1. Use as many quarters (25¢) as possible.
2. Then as many dimes (10¢) as possible.
3. Then as many nickels (5¢) as possible.
4. Finally, pennies (1¢) for the remainder.

## Hints

- Convert to cents using rounding to avoid floating-point issues:
  - In C, `int cents = (int) round(dollars * 100);`
- Validate the input: keep prompting until a non-negative amount is entered.

## Testing

Try these:
- `0` → `0`
- `0.01` → `1`
- `0.04` → `4`
- `0.05` → `1`
- `0.10` → `1`
- `0.25` → `1`
- `0.41` → `4`
- `1.99` → `13`

## Common Pitfalls

- Not rounding to the nearest cent before converting to `int`.
- Printing extra text instead of just the number.
- Accepting negative input without re-prompting.
