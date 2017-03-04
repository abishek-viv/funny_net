var := trial_2.cpp
var_c := trial_2_c

all:
	g++ -std=c++11 -o $(var_c) $(var)
clean:
	rm -rf *o $(var_c)
valg:
	valgrind ./$(var_c)
exec:
	./$(var_c)
