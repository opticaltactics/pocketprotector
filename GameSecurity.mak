# GameSecurity make file
 
# Some common definitions

RM=rm -f

CC=gcc

# Compiler flags, patchs for incclude files and libraries

CFLAGS =  -g

INCLUDES = 
	      
LDFLAGS = -o

LIBS = 

# Rule to create .o files from .c files
.c.o:
	$(RM) $@
	$(CC) -c $(CFLAGS) $(INCLUDES) $*.c

# Targets

all::	GameSecurity

GameSecurity.o:	    	GameSecurity.c

GameSecurity: GameSecurity.o

	$(RM) $@ GameSecurity

	$(CC) $(LIBS) $(LDLIBS) $(LDFLAGS) $@ $(CFLAGS) GameSecurity.o $(LIBS)	
            
clean:
	rm GameSecurity.o
	
