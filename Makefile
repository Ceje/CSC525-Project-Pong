CC = g++
CFLAGS = -Wno-deprecated-declarations -Wall
PROG = proj

SRCS = proj.cpp
OBJS = proj.o paddle.o

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut
endif

all: $(PROG) 

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(PROG) $(OBJS) $(LIBS)

proj.o: proj.cpp paddle.h
	$(CC) $(CFLAGS) -g -c proj.cpp

paddle.o: paddle.cpp paddle.h
	$(CC) $(CFLAGS) -g -c paddle.cpp
clean:
	rm -f $(PROG) $(OBJS)
