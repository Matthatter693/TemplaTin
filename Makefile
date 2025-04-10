cc = gcc
target=mainfun.o func.o info.o

tin : ${target}
	${cc} ${target} -o tin

mainfun.o : mainfun.c
	gcc -c mainfun.c

func.o : func.c
	gcc -c func.c

info.o : info.c
	gcc -c info.c

clean:
	@echo "cleaning build files...."
	rm -f *.o
	rm -f tin
