f1=Lesson.cpp
o1=Lesson.o
f2=User.cpp
o2=User.o
exe=a.out
obj=main.o $(o1) $(o2)
cc=g++
add=-std=c++11 -Wall -g

$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
main.o:main.cpp
	$(cc) -c main.cpp $(add)
$(o1):$(f1)
	$(cc) -c $(f1) $(add)
$(o2):$(f2)
	$(cc) -c $(f2) $(add)
.PHONY : sclean
clean :
	rm -r *.o $(exe)