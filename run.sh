echo "PWD=$PWD"
make clean
make

LIB=lib/OpenBLAS/lib

LD_LIBRARY_PATH=$LIB ./OpenBlasCExample_Profile || true
LD_LIBRARY_PATH=$LIB ./OpenBlasCExample_Simple || true
LD_LIBRARY_PATH=$LIB ./OpenBlasCExample || true
LD_LIBRARY_PATH=$LIB ./OpenBlasFortranExample || true
