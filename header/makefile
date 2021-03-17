CXX			=	g++
AR			=	ar
CFLAGS		=	-g -Wall -O2
FILES		=	$(shell for cpp in $(shell find . -name "*.cpp" -not -name "*-checkpoint.cpp");do echo "$$(basename $$cpp)"; done)
OBJECTS		=	$(shell for cpp in $(shell find . -name "*.cpp" -not -name "*-checkpoint.cpp");do echo "$$(basename $$cpp .cpp).o"; done)
OBJDIR		=	../objs/
TARGET		=	../lib/libstatisticaltest.a

all: $(OBJDIR) $(OBJECTS) MAKELIB

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(OBJECTS):$(FILES)
		$(CXX) $(CFLAGS) -std=c++0x -c $< -o $(OBJDIR)$@

MAKELIB:
		$(AR) -csruU $(TARGET) $(shell find $(OBJDIR) -type f \( -name *.o -not -name *-checkpoint.o \))

clean:
	rm -rf $(OBJDIR)
	rm -rf $(TARGET)