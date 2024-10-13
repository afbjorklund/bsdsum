#!/bin/sh

exitcode=0

testloop () {
	opt=$1

	while read algorithm; do
		n=0
		for f in *.inp; do
			n=$((n + 1))
			expected=$(head -$n $algorithm.digest | tail -1 | cut -d' ' -f4)
			hash=$($algorithm $opt -c "$expected" $f) || exitcode=1
		done
	done < algorithms.txt
}

testloop ""
testloop -q
testloop -r
testloop -qr

exit $exitcode
