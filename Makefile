CC=g++
IDIR=include/
SDIR=src/
ODIR=obj/
PREFLAGS=-I$(IDIR)

main: obj obj/Part.o obj/Equation.o
	$(CC) $(PREFLAGS) $(ODIR)Part.o $(ODIR)Equation.o main.cpp

obj: obj
	mkdir obj

obj/Part.o: $(IDIR)Part.h $(SDIR)Part.cpp
	$(CC) $(PREFLAGS) -c $(SDIR)Part.cpp -o $(ODIR)Part.o

obj/Equation.o: $(IDIR)Equation.h $(SDIR)Equation.cpp
	$(CC) $(PREFLAGS) -c $(SDIR)Equation.cpp -o $(ODIR)Equation.o