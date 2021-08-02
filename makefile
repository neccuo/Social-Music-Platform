# Use the first FLAGS definition for debugging, the 2nd for optimizing your code
FLAGS = -Wall -Wextra -g
EXECUTABLE = Terminal

auto:	Terminal
	cat inst.txt | ./Terminal

vauto:  Terminal
	cat inst.txt | valgrind --leak-check=full ./Terminal

Terminal:	Song.o User.o Heap.o BST.o UBST.o Graph.o System.o PrimaryUser.o Terminal.o
	g++ $(FLAGS) Song.o User.o Heap.o BST.o UBST.o Graph.o System.o PrimaryUser.o Terminal.o -o Terminal

Terminal.o:	Terminal.cpp Terminal.h 
	g++ $(FLAGS) -c Terminal.cpp

Heap.o: Heap.cpp Heap.h Song.h
	g++ $(FLAGS) -c Heap.cpp 

BST.o:	BST.cpp BST.h Song.h
	g++ $(FLAGS) -c BST.cpp

UBST.o:		UBST.cpp UBST.h User.h
	g++ $(FLAGS) -c UBST.cpp

Song.o:	Song.cpp Song.h
	g++ $(FLAGS) -c Song.cpp

Graph.o:	Graph.cpp Graph.h UBST.h
	g++ $(FLAGS) -c Graph.cpp

System.o:	System.cpp System.h Heap.h BST.h 
	g++ $(FLAGS) -c System.cpp

User.o :	User.cpp User.h Song.h 
	g++ $(FLAGS) -c User.cpp

PrimaryUser.o: 	PrimaryUser.cpp PrimaryUser.h Song.h BST.h 
	g++ $(FLAGS) -c PrimaryUser.cpp

tar: clean
	cd .. && tar -cvzf CA5_Cppotify.tar.gz cs240-spring21-ca5-cppotify && cd -

scrub: clean
	rm ~* *.swp *\#

memcheck: $(EXECUTABLE)
	valgrind --leak-check=full ./$(EXECUTABLE)

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o $(EXECUTABLE)
