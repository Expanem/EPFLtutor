CC     = g++
CFLAGS = -g -std=c++11
OFILES = main.o configuration.o

EPFLtutor: $(OFILES)
	$(CC) $(OFILES) -o $@
	
clean:
	@/bin/rm -f *.o *.x *.c~ *.h~ EPFLtutor

main.o: main.cc
	$(CC) $(CFLAGS) -c $< -o $@

configuration.o: configuration.cc configuration.h
	$(CC) $(CFLAGS) -c $< -o $@