# Predefined targets
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

#  Includes header files in the make file
C_SRCS := \
  $(wildcard *.c) \
  $(wildcard src/*.c) \
  $(wildcard src/**/*.c)
# Includes header files in the make file
HDRS := \
  $(wildcard *.h) \
  $(wildcard src/*.h) \
	$(wildcard src/**/*.h)
# add comments
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# Says that the makefile is done
all: build
		@echo "All Done"

# Builds the targeted files
build: $(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# Catch root directory src files
bin/%.o: %.c $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

# Catch all nested directory files
bin/%.o: src/%.c $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@


#Cleans the file so you can recompile
clean:
		rm -f $(TARGET)
		rm -rf bin
#Runs the targeted files
run: build
		./$(TARGET) <put your command line arguments here>
#Says which files have been included in the makefile as an echo
which:
		@echo "FOUND SOURCES: ${C_SRCS}"
		@echo "FOUND HEADERS: ${HDRS}"
		@echo "TARGET OBJS: ${OBJS}"
