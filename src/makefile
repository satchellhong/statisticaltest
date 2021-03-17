CXX			=	g++
LIB_INC		=	../lib/
LIB			=	-L$(LIB_INC) -lstatisticaltest
CXXFLAGS	=	-O2 -g -Wall -std=c++0x
FILES		=	$(shell for cpp in $(shell find . -name "*.cpp" -not -name "*-checkpoint.cpp");do echo "$$(basename $$cpp)"; done)
OBJECTS		=	$(shell for cpp in $(shell find . -name "*.cpp" -not -name "*-checkpoint.cpp");do echo "$$(basename $$cpp .cpp).o"; done)
TARGET		=	../bin/test

all : $(OBJECTS) $(TARGET)

$(OBJECTS):$(FILES)
		$(CXX) $(CXXFLAGS) -std=c++0x -c $< -o $@

$(TARGET):$(OBJECTS)
	$(CXX) $^ $(CXXFLAGS) $(LIB) -o $@

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJECTS)
