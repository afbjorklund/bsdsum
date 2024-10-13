#!/bin/sh

exitcode=0

testloop () {
	opt=$1
	sum=$2
	field=$3

	while read algorithm; do
		n=0
		for f in *.inp; do
			n=$((n + 1))
			read text < $f
			hash=$($algorithm$sum $opt -s "$text" | cut -d= -f$field)
			hash=$(echo $hash | cut -d' ' -f1)
			expected=$(head -$n $algorithm.digest | tail -1 | cut -d' ' -f4)
			[ "$hash" = "$expected" ] || exitcode=1
		done
	done < algorithms.txt
}

testloop "" "" 2
testloop -q "" 1
testloop -r "" 1
testloop -qr "" 1
testloop "" sum 1
testloop -q sum 1

exit $exitcode
