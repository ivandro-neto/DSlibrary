SRC_PATH := src/
OBJ_PATH := obj/
INCLUDE_PATH := includes/
TEST_PATH := test/
LIB_PATH := lib/
stack_objs:= item.o stack.o
bitree_objs:= bitree.o
list_objs:= item.o list.o
queue_objs:= item.o queue.o

objs:= $(OBJ_PATH)item.o $(OBJ_PATH)stack.o $(OBJ_PATH)bitree.o $(OBJ_PATH)list.o $(OBJ_PATH)queue.o

build:
	ar rcs $(LIB_PATH)libds.a $(objs)

init:
	mkdir obj

start-test-stack: $(stack_objs)
	
	gcc $(TEST_PATH)stack.c -o $(TEST_PATH)stack-run -L$(LIB_PATH) -lds

start-test-binary:$(bitree_objs)
	
	gcc $(TEST_PATH)binarytree.c -o $(TEST_PATH)binarytree-run -L$(LIB_PATH) -lds

start-test-list:$(list_objs)
	
	gcc $(TEST_PATH)list.c -o $(TEST_PATH)list-run -L$(LIB_PATH) -lds

start-test-queue:$(queue_objs)
	
	gcc $(TEST_PATH)queue.c -o $(TEST_PATH)queue-run -L$(LIB_PATH) -lds

start-example:$(objs)
	
	gcc main.c -o example-run -L$(LIB_PATH) -lds

compile-all:$(objs)
	
	gcc -c $(OBJ_PATH)bitree.o $(OBJ_PATH)item.o $(OBJ_PATH)list.o $(OBJ_PATH)queue.o $(OBJ_PATH)stack.o 

bitree.o : $(INCLUDE_PATH)bitree.h
	gcc -c $(SRC_PATH)bitree.c -o $(OBJ_PATH)$@ 

item.o : $(INCLUDE_PATH)item.h
	gcc -c $(SRC_PATH)item.c -o $(OBJ_PATH)$@ 

list.o : $(INCLUDE_PATH)list.h
	gcc -c $(SRC_PATH)list.c -o $(OBJ_PATH)$@ 

queue.o : $(INCLUDE_PATH)queue.h
	gcc -c $(SRC_PATH)queue.c -o $(OBJ_PATH)$@ 

stack.o : $(INCLUDE_PATH)stack.h
	gcc -c $(SRC_PATH)stack.c -o $(OBJ_PATH)$@ 

