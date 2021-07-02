OPT = -Wall

a02:	main.o  Course.o Taken.o Student.o DynArray.o StatArray.o School.o Control.o View.o
	g++ $(OPT) -o a02 main.o  Course.o Taken.o Student.o DynArray.o StatArray.o School.o Control.o View.o

Control.o: Control.cc Control.h
	g++ $(OPT) -c Control.cc

View.o: View.cc View.h
	g++ $(OPT) -c View.cc

Student.o: Student.cc Student.h
	g++ $(OPT) -c Student.cc

Course.o: Course.cc Course.h
	g++ $(OPT) -c Course.cc

Taken.o: Taken.cc Taken.h
	g++ $(OPT) -c Taken.cc

DynArray.o: DynArray.cc DynArray.h
	g++ $(OPT) -c DynArray.cc

StatArray.o: StatArray.cc StatArray.h
		g++ $(OPT) -c StatArray.cc

School.o: School.cc School.h
		g++ $(OPT) -c School.cc

main.o:	main.cc  Course.h Taken.h Student.h DynArray.h StatArray.h School.h Control.h View.h
	g++ $(OPT) -c main.cc
clean:
	rm -f *.o a02
