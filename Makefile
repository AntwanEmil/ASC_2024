CXXFLAGS += -std=c++11

#LIB_FUZZING_ENGINE ?= fuzzing_engine.o

all: fuzzer

clean:
	rm -fv *.o *.a *.gch *.so HF.* *_fuzzer crash-* *.zip 



check: all
	   ./fuzzer


fuzzer: fuzzer.cpp my_api.a
	${CXX} ${CXXFLAGS} $< my_api.a ${LIB_FUZZING_ENGINE} -o $@
#	zip -q -e fuzzer_seed_corpus.zip


my_api.a: my_api.cpp my_api.h
	${CXX} ${CXXFLAGS} $^ -c
	ar ruv my_api.a my_api.o


