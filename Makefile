.SURFFIXES : .cpp .o
CXX = g++

CPPFLAGS = -g

HEDRS = LinkedList.h Stack.h
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = s191293 

all : $(TARGET)

$(TARGET) : $(OBJS) $(HDRS)
	$(CXX) -o $@ $(OBJS)

.PHONY : clean

clean :
	rm -rf $(OBJS) $(TARGET)	
