FROM gcr.io/oss-fuzz-base/base-builder
#Copying source directory contents to a temp directory
COPY . $SRC/clusterfuzzlite-example
# setting the temp directory to be the default directory
WORKDIR clusterfuzzlite-example
# copying the build file from this directory to the src directory (including all .c and .h files) 
COPY .clusterfuzzlite/build.sh $SRC/
