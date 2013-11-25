CC = g++
CFLAGS = -Wno-deprecated-declarations -Wall
PROG = proj

SRCS = proj.cpp
OBJS = proj.o Paddle.o Ball.o

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut
endif

all: $(PROG) 

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(PROG) $(OBJS) $(LIBS)

proj.o: proj.cpp Paddle.h
	$(CC) $(CFLAGS) -g -c proj.cpp

Paddle.o: Paddle.cpp Paddle.h
	$(CC) $(CFLAGS) -g -c Paddle.cpp

Ball.o: Ball.cpp Ball.h
	$(CC) $(CFLAGS) -g -c Ball.cpp
clean:
	rm -f $(PROG) $(OBJS)
