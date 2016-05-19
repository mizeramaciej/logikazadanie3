#!/bin/bash

a=(0.2 1 0.2 0.2 0.2 0.3)
b=(15 15 12 15 17)
c=(5 5 5 2 5 6)
d=(50 50 50 50 54 52)
e=(10 10 10 10 10 5)
f=(3 3 3 3 4 6)

result=(0 1 1 1 1 1)

for i in $(seq 0 5); do
	out=$(./badanie.exe ${a[$i]} ${b[$i]} ${c[$i]} ${d[$i]} ${e[$i]} ${f[$i]})
	
	if [ "$out" != "${result[$i]}" ] ; then
		echo "in" ${a[$i]} ${b[$i]} ${c[$i]} ${d[$i]} ${e[$i]} ${f[$i]} 
		echo "real out" $out
		echo "expected out" ${result[$i]}
	fi
done
