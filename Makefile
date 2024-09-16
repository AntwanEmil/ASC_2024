CXX=clang++
CXXFLAGS += -std=c++11 -fsanitize=fuzzer

SRC_DIR = src
INC_DIR = inc
FUZZER_DIR = fuzzers
FUZZERS = $(wildcard $(FUZZER_DIR)/*.cpp)

# Find all .cpp files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
FUZZER_OBJS = $(FUZZERS:.cpp=.o)

# Define the object files
OBJS = $(SRCS:.cpp=.o)


#LIB_FUZZING_ENGINE ?= fuzzing_engine.o

all: fuzzers

clean:
	rm -fv src/*.o fuzzers/*.o *.o *.a *.gch *.gcno *.so HF.* *_fuzzer crash-* *.zip 



check: all
	   ./fuzzers


# Define the target for the fuzzer
fuzzers: $(FUZZER_OBJS) my_api.a
	for fuzzer in $(FUZZER_OBJS); do \
		${CXX} ${CXXFLAGS} $$fuzzer my_api.a ${LIB_FUZZING_ENGINE} -o $${fuzzer%.o}; \
	done
#	zip -q -e fuzzer_seed_corpus.zip


# Define the target for the static library
my_api.a: $(OBJS)
	ar ruv my_api.a $(OBJS)

# Compile each .cpp file into an object file
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	${CXX} ${CXXFLAGS} -I$(INC_DIR) -c $< -o $@


$(FUZZER_DIR)/%.o: $(FUZZER_DIR)/%.cpp
	${CXX} ${CXXFLAGS} -I$(INC_DIR) -c $< -o $@