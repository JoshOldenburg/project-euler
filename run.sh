# Compile and run a solution written in C
if [ $# -lt 1 ]; then
	echo "Usage: ./run.sh <number>"
	exit 1
fi

clang -o $1 ${1}.c && time ./$1
