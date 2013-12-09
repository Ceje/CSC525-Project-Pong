CC = g++
CFLAGS = -Wno-deprecated-declarations -Wall
PROG = proj

SRCS = ProjectGuiMain.cpp
OBJS = proj.o Paddle.o Ball.o Pong.o drawFunc.o menus.o windows.o projIO.o timers.o

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut
endif

all: $(PROG) 

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(PROG) $(OBJS) $(LIBS)

proj.o: ProjectGuiMain.cpp Paddle.h Pong.h Ball.h drawFunc.h menus.h windows.h projIO.h timers.h
	$(CC) $(CFLAGS) -g -c proj.cpp

Paddle.o: Paddle.cpp Paddle.h
	$(CC) $(CFLAGS) -g -c Paddle.cpp

Ball.o: Ball.cpp Ball.h
	$(CC) $(CFLAGS) -g -c Ball.cpp

drawFunc.o: drawFunc.cpp drawFunc.h
	$(CC) $(CFLAGS) -g -c drawFunc.cpp

menus.o: menus.cpp menus.h
	$(CC) $(CFLAGS) -g -c menus.cpp

windows.o: Windows.cpp windows.h
	$(CC) $(CFLAGS) -g -c Windows.cpp

projIO.o: projIO.cpp projIO.h
	$(CC) $(CFLAGS) -g -c projIO.cpp

timers.o: timers.cpp timers.h
	$(CC) $(CFLAGS) -g -c timers.cpp

clean:
	rm -f $(PROG) $(OBJS)
