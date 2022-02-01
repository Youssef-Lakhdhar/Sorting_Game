CC	=	g++
CFLAGS	=	-Wall
EXEC_NAME	=	miam
LIBS	=	-lsfml-graphics	-lsfml-window	-lsfml-system
OBJ_FILES	= Personnage.o Humain.o	Obstacle.o Objet.o Emballage.o Organique.o Verre.o Zombie.o	main.o

all	:	miam

miam:	$(OBJ_FILES)
	$(CC)	-o	$(EXEC_NAME)	$(OBJ_FILES)	$(LIBS)

clean	:
	rm	$(EXEC_NAME)	$(OBJ_FILES)
