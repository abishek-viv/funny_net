var := "file_name".cpp
var_c :="compiled file"

all:
	g++ -std=c++11 -o $(var_c) $(var)
clean:
	rm -rf *o $(var_c)
valg:
	valgrind ./$(var_c)
exec:
	./$(var_c)
