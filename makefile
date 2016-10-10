listtest: list.c
	gcc list.c -o listtest

clear:
	rm *~

run: listtest
	./listtest
