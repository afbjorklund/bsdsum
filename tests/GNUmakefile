
TESTS = self-test bsd-c-test bsd-p-test bsd-s-test coreutils-c-test

UNAME ?= $(shell uname)

tests:
	-cp algorithms-$(UNAME).txt algorithms.txt
	for test in $(TESTS); do ./$$test.sh; done
