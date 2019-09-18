CC     = g++
CFLAGS = -g -std=c++11
OFILES = main.o

EPFLtutor: $(OFILES)
	$(CC) $(OFILES) -o $@
	
clean:
	@/bin/rm -f *.o *.x *.c~ *.h~ EPFLtutor

main.o: main.cc
	$(CC) $(CFLAGS) -c $< -o $@