echo "./RPN \"1 1 + 5\""
./RPN "1 1 + 5"
echo "./RPN \"1 1 + 5 5 +\""
./RPN "1 1 + 5 5 +"
echo "./RPN \"1 1 + 5 5 + +\""
./RPN "1 1 + 5 5 + +"
echo "./RPN \"1\""
./RPN "1"
echo "./RPN \"-1 +\""
./RPN "-1 +"
echo "./RPN \"1 + 1\""
./RPN "1 + 1"
echo "./RPN \"1 1 + 1 +\""
./RPN "1 1 + 1 +"
echo "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "./RPN \"7 7 * 7 -\""
./RPN "7 7 * 7 -"
echo "./RPN \"1 2 * 2 / 2 * 2 4 - +\""
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "./RPN \"1 - 1 - 1 - 1\""
./RPN "1 1 - 1 - 1 -"