#!/bin/sh

while read algorithm; do
	$algorithm -x > self-test.$algorithm.out || exitcode=$?
	diff self-test.$algorithm.chk self-test.$algorithm.out
done < algorithms.txt

exit $exitcode
