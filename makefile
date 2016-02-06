OUTPUT = main.exe
SOURCEPATH1 = files
SOURCEPATH2 = mainfunction
SOURCEFILES1 = $(wildcard $(SOURCEPATH1)/*.cpp)
SOURCEFILES2 = $(wildcard $(SOURCEPATH2)/*.cpp)
OBJPATH1 = obj1
OBJPATH2 = obj2
OBJECTFILES1 = $(addprefix $(OBJPATH1)/, $(notdir $(SOURCEFILES1:.cpp=.o)))
OBJECTFILES2 = $(addprefix $(OBJPATH2)/, $(notdir $(SOURCEFILES2:.cpp=.o)))
CFLAGS = -c -Wall -std=c++0x
LINKERFLAGS = -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDEFIX = -Ifiles -Imainfunction
CC = g++

all: main.exe

main.exe: main.cpp $(OBJECTFILES1) $(OBJECTFILES2)
	$(CC) main.cpp $(OBJECTFILES1) $(OBJECTFILES2) $(LINKERFLAGS) -o $(OUTPUT) $(INCLUDEFIX)

$(OBJPATH1)/%.o: $(SOURCEPATH1)/%.cpp
	@mkdir -p $(OBJPATH1)
	$(CC) $< $(CFLAGS) -o $@ $(INCLUDEFIX)

$(OBJPATH2)/%.o: $(SOURCEPATH2)/%.cpp
	@mkdir -p $(OBJPATH2)
	$(CC) $< $(CFLAGS) -o $@ $(INCLUDEFIX)

clean:
	rm $(OBJPATH1)/* 
	rm $(OBJPATH2)/*
	rm $(OUTPUT)
