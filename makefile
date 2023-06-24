#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -Wall -Werror -Wextra -pedantic

#OBJS specifies which files to compile as part of the project
OBJS = *.c

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = monty

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
