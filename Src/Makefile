CC     = g++
CFLAGS = -g -std=c++17
OFILES = main.o configuration.o dataManager.o

EPFLtutor: $(OFILES)
	$(CC) $(OFILES) -o $@
	
clean:
	@/bin/rm -f *.o *.x *.c~ *.h~ EPFLtutor

main.o: main.cc configuration.h dataManager.h statistics.h
	$(CC) $(CFLAGS) -c $< -o $@

configuration.o: configuration.cc configuration.h
	$(CC) $(CFLAGS) -c $< -o $@

dataManager.o: dataManager.cc dataManager.h configuration.h
	$(CC) $(CFLAGS) -c $< -o $@

statistics.o: statistics.cc statistics.h configuration.h dataManager.h
	$(CC) $(CFLAGS) -c $< -o $@