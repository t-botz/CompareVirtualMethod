all: testPointerExtern

testPointer : testPointer.o
	gcc -o $@ $^

testPointer.o : testPointer.c
	gcc -c $^
	

testPointerExtern : testPointerExtern.o animals.o
	gcc -o $@ $^

testPointerExtern.o : testPointerExtern.c
	gcc -c $^
	
animals.o : animals.c
	gcc -c $^

clean:
	rm testPointer testPointer.o animals.o testPointerExtern.o testPointerExtern
