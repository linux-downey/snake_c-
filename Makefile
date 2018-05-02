
TARGET = snake_exe
HED_DIR  += ./inc/
LIB_DIR  +=
LIB_NAME +=-lcurses -lpthread

#CC= gcc
#CFLAG= -std=gnu99 -Wall 

RM =rm -rf

CC= g++
CFLAG= -std=c++11 -Wall

ifeq ($(SRC_DIR),)
	SRC_DIR=.
endif
ifeq ($(HED_DIR),)
	HED_DIR=.
endif
ifeq ($(TARGET),)
	TARGET=a.out
endif
ifeq ($(LIB_DIR),)
	LIB_DIR=.
endif


HED+=

SRC+= src/get_input.cpp src/main.cpp src/show_graph.cpp src/snake_operation.cpp


ifeq ($(LIB_NAME),)
all:
	$(CC) $(CFLAG) $(SRC) -I$(HED_DIR) -o $(TARGET)
else
all:
	$(CC) $(CFLAG) $(SRC) -I$(HED_DIR) -L$(LIB_DIR) $(LIB_NAME) -o $(TARGET)
endif
clean:
	$(RM)  $(TARGET)
	
