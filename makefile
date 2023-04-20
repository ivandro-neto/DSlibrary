LIBS_PATH := libs/
OBJ_PATH := obj/
INCLUDE_PATH := includes/
TEST_PATH := test/

stack_objs:= item.o stack.o
bitree_objs:= bitree.o
list_objs:= item.o list.o
queue_objs:= item.o queue.o

objs:= item.o stack.o bitree.o list.o queue.o

init:
	mkdir obj

start-test-stack: $(stack_objs)
	
	gcc $(TEST_PATH)stack.c $(OBJ_PATH)item.o $(OBJ_PATH)stack.o -o $(TEST_PATH)stack-run

start-test-binary:$(bitree_objs)
	
	gcc $(TEST_PATH)binarytree.c $(OBJ_PATH)bitree.o -o $(TEST_PATH)binarytree-run

start-test-list:$(list_objs)
	
	gcc $(TEST_PATH)list.c $(OBJ_PATH)item.o $(OBJ_PATH)list.o -o $(TEST_PATH)list-run

start-test-queue:$(queue_objs)
	
	gcc $(TEST_PATH)queue.c $(OBJ_PATH)item.o $(OBJ_PATH)queue.o -o $(TEST_PATH)queue-run

start-test:$(objs)
	
	gcc main.c $(OBJ_PATH)bitree.o $(OBJ_PATH)item.o $(OBJ_PATH)list.o $(OBJ_PATH)queue.o $(OBJ_PATH)stack.o -o stack-run

compile-all:$(objs)
	
	gcc -c $(OBJ_PATH)bitree.o $(OBJ_PATH)item.o $(OBJ_PATH)list.o $(OBJ_PATH)queue.o $(OBJ_PATH)stack.o -o $(OBJ_PATH)ds-library

bitree.o : $(INCLUDE_PATH)bitree.h
	gcc -c $(LIBS_PATH)bitree.c -o $(OBJ_PATH)$@ 

item.o : $(INCLUDE_PATH)item.h
	gcc -c $(LIBS_PATH)item.c -o $(OBJ_PATH)$@ 

list.o : $(INCLUDE_PATH)list.h
	gcc -c $(LIBS_PATH)list.c -o $(OBJ_PATH)$@ 

queue.o : $(INCLUDE_PATH)queue.h
	gcc -c $(LIBS_PATH)queue.c -o $(OBJ_PATH)$@ 

stack.o : $(INCLUDE_PATH)stack.h
	gcc -c $(LIBS_PATH)stack.c -o $(OBJ_PATH)$@ 

