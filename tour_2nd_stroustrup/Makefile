SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
DEPS=$(SOURCES:.cpp=.d)
BINS=$(SOURCES:.cpp=)

CFLAGS+=-MMD
CXXFLAGS+=-MMD -std=c++17

.PHONY: all

all: $(BINS)

.PHONY: clean

clean:
		$(RM) $(OBJECTS) $(DEPS) $(BINS)

-include $(DEPS)
