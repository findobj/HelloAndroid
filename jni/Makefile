CFLAGS =	-O2 -g -Wall -fmessage-length=0

CURR_PATH = $(shell pwd)
	
CXXSRCS = CppMix.cpp \
		findobj/train/AStar.cpp \
		findobj/train/GraphRouter.cpp \
		findobj/train/Tile.cpp \
		findobj/component/AppDelegate.cpp \
		findobj/foundation/BiTreeNode.cpp \
		findobj/foundation/LinkedNode.cpp \
		findobj/foundation/SearchNode.cpp \
		findobj/foundation/Point.cpp \
		findobj/foundation/Rect.cpp \
		findobj/foundation/Size.cpp \
		findobj/foundation/Pair.cpp \
		findobj/foundation/ArrayList.cpp \
		findobj/foundation/LinkedList.cpp \
		findobj/foundation/HashMap.cpp \
		findobj/foundation/BiTree.cpp \
		findobj/foundation/Heap.cpp \
		findobj/foundation/Graph.cpp \
		findobj/foundation/Iterator.cpp \
		findobj/foundation/Object.cpp \
		findobj/foundation/String.cpp \
		findobj/util/Config.cpp \
		findobj/util/Const.cpp \
		findobj/util/Log.cpp \
		findobj/platform/linux/LLog.cpp

CSRCS = train.c

OBJS =

INCLUDES = -I$(CURR_PATH)

LIBS = -lpthread \
	-ldl

TARGET =	HelloTrain

$(TARGET): $(CXXSRCS) $(CSRCS)
#	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)
	$(CXX) $(CFLAGS) -o $(TARGET) $(CXXSRCS) $(CSRCS) $(INCLUDES) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
