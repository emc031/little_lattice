
polyakov.exe: main_polyakov.o utilities.o ensemble.o operators.o
	gcc -lm $^ -o polyakov.exe

metropolis_tuner.exe: main_tuner.o utilities.o ensemble.o operators.o
	gcc -lm $^ -o metropolis_tuner.exe

correlation_time.exe: main_correlations.o correlations.o  utilities.o ensemble.o operators.o
	gcc -lm $^ -o correlation_time.exe

main_polyakov.o: main_polyakov.c main.h
	gcc -c $<

main_tuner.o: main_tuner.c main.h
	gcc -c $<

main_correlations.o: main_correlations.c main.h
	gcc -c $<

utilities.o: utilities.c utilities.h
	gcc -c $<

ensemble.o: ensemble.c ensemble.h
	gcc -c $<

operators.o: operators.c operators.h
	gcc -c $<

correlations.o: correlations.c correlations.h
	gcc -c $<

.PHONY:clean
clean:
	rm *.o