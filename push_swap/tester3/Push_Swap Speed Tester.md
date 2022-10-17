# Push_Swap Speed Tester

#### A simple speed tester for your push_swap.

----

#### Requirements:

You must have the *checker_Mac* or *checker_linux* provided by 42 on the same directory as the tester. The file must be named *checker*.

#### Input:

The tester expects 3 arguments + 1 optional:
* Minimum random integer list value
* Maximum random integer list value
* Max instruction count (inclusive)
* *Optional:* **-s** flag for silenced output

E.g:
`bash tester.sh 1 5 12` will create lists of integers in range 1 to 5, in a random order. The tester will exit if the instruction count is greater than 12 or if the integers are not properly sorted.

#### How testing works?

If the instruction count surprasses the informed maximum, the tester exits.
If the *checker* returns *KO*, it also exits.
Otherwise, the tester will keep testing with new integer lists.

#### Output:

Each time your push_swap is called, the tester will output a string in the following format: `[INTEGERS] - [OK/KO] - [INSTRUCTION_COUNT]`

#### Test duration:

The tester will run endlessly if there are no errors. To stop it, press CTRL+C in the terminal window it's being executed.