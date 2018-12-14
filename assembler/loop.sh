#!/bin/sh
for i in {1..50}
do
	../asm test.s
	sleep .1
done
