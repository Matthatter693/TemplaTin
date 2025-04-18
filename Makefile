cc = gcc
target= mainfun.o func.o info.o confread.o

tin : ${target}
	${cc} build/*.o -o build/tin

mainfun.o : mainfun.c
	gcc -c mainfun.c -o build/mainfun.o 

func.o : func.c
	gcc -c func.c -o build/func.o

info.o : info.c
	gcc -c info.c -o build/info.o

confread.o: confread.c
	gcc -c confread.c -o build/confread.o

clean:
	@echo "cleaning build files...."
	rm -f build/*.o
	rm -f build/tin
	rm -f build/*.c
	rm -f build/*.cpp

conf:
	@echo "Creating templates and config file"
	mkdir -p ~/.tindir
	cp -r templates ~/.tindir
	cp .tinconf ~/.tinconf

install:
	install -Dm755 build/tin /usr/local/bin/tin

