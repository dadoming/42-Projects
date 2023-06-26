# Perform "bash test.sh [N]" operations
# Range is 1 to 1000000
if [ $# -eq 1 ]
then
    ./PMergeMe `shuf -i 1-1000000 -n $1 | tr "\n" " "`
else
    echo "Usage: bash test.sh [N]"
    exit 1
fi
