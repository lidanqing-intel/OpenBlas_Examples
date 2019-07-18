LIB=-Llib/OpenBLAS/lib
INC=-Ilib/OpenBLAS/include/
libs=-lopenblas -lpthread -lgfortran
FLAGS=

LD_LIBRARY_PATH=lib/OpenBLAS/lib

default: OpenBlasCExample_Profile OpenBlasCExample OpenBlasCExample_Simple 
#OpenBlasFortranExample #failing dont know how to link to fortran...

OpenBlasCExample: OpenBlas_Example.cpp
	g++ -std=c++11 -march=corei7-avx -mfpmath=sse -masm=intel -m64 -Ofast -flto -funroll-loops -ffast-math -fno-signed-zeros -fno-trapping-math -frename-registers \
	-o OpenBlasCExample OpenBlas_Example.cpp $(INC) $(LIB) $(libs)

OpenBlasCExample_Simple: OpenBlas_Example.cpp
	g++ -std=c++11 -fprofile-use -fprofile-correction \
	-o OpenBlasCExample_Simple OpenBlas_Example.cpp $(INC) $(LIB) $(libs)

OpenBlasCExample_Profile: OpenBlas_Example.cpp
	g++ -std=c++11 -fprofile-generate \
        -o OpenBlasCExample_Profile OpenBlas_Example.cpp $(INC) $(LIB) $(libs)


OpenBlasFortranExample: OpenBlas_Fortran_Example.cpp
	g++ -o OpenBlasFortranExample OpenBlas_Fortran_Example.cpp $(INC) $(LIB) $(libs)

clean:
	rm -f OpenBlasCExample OpenBlasCExample_Simple OpenBlasCExample_Profile OpenBlasFortranExample 

