NAME  =     SuperMarioBros.etna

CC    =     gcc

CXX   =     g++

RM    =     rm -f

CPPFLAGS    =     -g -W -Wall -Werror

LDFLAGS     =     -g -Iinclude

LDLIBS      =     -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRCS        =     src/Engine.cpp \
			src/engine/entities/Mario.cpp \
			src/engine/entities/Coin.cpp \
			src/engine/entities/Bloc.cpp \
			src/engine/entities/Pipe.cpp \
			src/engine/entities/Ground.cpp \
			src/engine/entities/Character.cpp \
			src/engine/entities/CharacterFactory.cpp \
			src/engine/entities/Score.cpp \
			src/engine/entities/Map.cpp \
			src/engine/entities/AbstractEntity.cpp \
			src/engine/time/TimeManager.cpp \
			src/main.cpp
			# src/engine/entities/Animation.cpp \

OBJS        =     $(subst .cc,.o,$(SRCS))

all:        $(NAME)

$(NAME):    $(OBJS)
		$(CXX) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

depend: 	.depend

.depend:    $(SRCS)
		$(RM) ./.depend
		$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
		$(RM) $(OBJS)

distclean:  clean
		$(RM) *~ .depend

include .depend
