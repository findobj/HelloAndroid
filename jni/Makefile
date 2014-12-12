CFLAGS =	-O2 -g -Wall -fmessage-length=0

CURR_PATH = $(shell pwd)
	
CXXSRCS = CppMix.cpp \
		findobj/train/AStar.cpp \
		findobj/train/Tile.cpp \
		findobj/component/AppDelegate.cpp \
		findobj/foundation/Node.cpp \
		findobj/foundation/Point.cpp \
		findobj/foundation/Rect.cpp \
		findobj/foundation/Size.cpp \
		findobj/foundation/AB.cpp \
		findobj/foundation/List.cpp \
		findobj/foundation/HashMap.cpp \
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

TARGET =	HelloAndroid

$(TARGET): $(CXXSRCS) $(CSRCS)
#	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)
	$(CXX) $(CFLAGS) -o $(TARGET) $(CXXSRCS) $(CSRCS) $(INCLUDES) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
