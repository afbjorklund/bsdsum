#!/bin/sh

exitcode=0

testloop () {
	opt=$1

	while read algorithm; do
		${algorithm}sum -c ${algorithm}.digest || exitcode=1
		${algorithm}sum -c ${algorithm}sum.digest || exitcode=1
	done < algorithms.txt
}

testloop ""
testloop -q
testloop -r
testloop -qr

exit $exitcode
