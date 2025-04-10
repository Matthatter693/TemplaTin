cc = gcc
target=mainfun.o func.o info.o

tin : ${target}
	${cc} build/*.o -o build/tin

mainfun.o : mainfun.c
	gcc -c mainfun.c -o build/mainfun.o 

func.o : func.c
	gcc -c func.c -o build/func.o

info.o : info.c
	gcc -c info.c -o build/info.o

clean:
	@echo "cleaning build files...."
	rm -f build/*.o
	rm -f build/tin
