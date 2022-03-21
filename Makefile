
BINARY=diff_eq
CC=g++
OPT=-O1
INCDIRS= ./Inc/
SOURCE_DIR=Src
#dependendencies flags
DEPFLAGS=-MP -MD
#includes
CPP_INCLUDES=$(foreach D,$(INCDIRS),-I$(D))
#compiler flags
CXXFLAGS=-Wall -Wextra -g $(CPP_INCLUDES) $(OPT) $(DEPFLAGS)
# source files
#CPPFILES=$(foreach(D,$(SOURCE_DIR),$(wildcard $(D)/*.cpp)))
CPPFILES=Src/diff_eq.cpp
# object and dependencies files
OBJECTS=$(patsubst %.cpp,%.o,$(CPPFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CPPFILES))


all: $(BINARY)
	$(info $$CPPFILES is [${CPPFILES}])

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) -c $(CXXFLAGS) -Wa,-a,-ad -o $@ $< >$*.lst

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES) $(SOURCE_DIR)/*.lst

-include $(DEPFILES)