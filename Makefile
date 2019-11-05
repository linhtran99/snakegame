OPTS = -Wall -g -std=c++11
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

snakeApp: snakeApp.o Snake.o Wall.o WallArray.o Food.o Body.o ColorButton.o texture.o
	g++ $(OPTS) -o snakeApp snakeApp.o Snake.o Wall.o WallArray.o Food.o Body.o ColorButton.o texture.o $(LIBS)


snakeApp.o: snakeApp.cpp Snake.h Wall.h WallArray.h Food.h Body.h Color.h ColorButton.h initvals.h texture.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c snakeApp.cpp

Food.o:	Food.h Food.cpp Snake.h Snake.cpp Body.h Body.cpp Color.h Wall.h WallArray.h Wall.cpp WallArray.cpp
	g++ $(OPTS) -c Food.cpp

Snake.o: Snake.h Snake.cpp Color.h
	g++ $(OPTS) -c Snake.cpp

Wall.o: Wall.h Wall.cpp
	g++ $(OPTS) -c Wall.cpp

WallArray.o: WallArray.h WallArray.cpp
	g++ $(OPTS) -c WallArray.cpp

Body.o: Body.cpp Body.h Snake.h
	g++ $(OPTS) -c Body.cpp

ColorButton.o:	ColorButton.cpp ColorButton.h Color.h
	g++ $(OPTS) -c ColorButton.cpp

texture.o: texture.cpp texture.h
	g++ $(OPTS) -c texture.cpp

clean:
	rm -f *.o snakeApp
