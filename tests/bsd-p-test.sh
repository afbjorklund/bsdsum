#!/bin/sh

exitcode=0

testloop () {
	opt=$1
	sum=$2

	for algorithm in sha512; do
		for f in *.inp; do
			outbase=$(basename $f .inp)
			$algorithm$sum $opt -p < $f > $outbase.out
			diff $outbase.$algorithm$sum-p.chk $outbase.out || exitcode=1
		done
	done
}

testloop "" ""
testloop -q ""
testloop -qr ""
testloop "" sum
testloop -q sum

exit $exitcode
