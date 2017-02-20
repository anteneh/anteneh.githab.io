#!/bin/bash

#g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
#echo "computing critical charge for 0.5v"

#./snmout.exe 0.0998291015625 0.095356 0.6 8 512 vdd06.txt fp06.txt > results/log06512.log #sp-0.0
#rm snmout.exe
#g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
#./snmout.exe 0.0998291015625 0.095356 0.6 8 256 vdd06.txt fp06.txt > results/log06256.log #sp-0.1
#rm snmout.exe
#g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
#./snmout.exe 0.0998291015625 0.095356 0.6 8 128 vdd06.txt fp06.txt > results/log06128.log #sp-0.2
#rm snmout.exe
#g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
#./snmout.exe 0.0998291015625 0.095356 0.6  8 64 vdd06.txt fp06.txt > results/log0664.log #sp-0.3
#rm snmout.exe
#g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
#./snmout.exe 0.0998291015625 0.095356 0.6 8 32 vdd06.txt fp06.txt > results/log0632.log #sp-0.4
#rm snmout.exe

#0.7V

g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.11629638671875 0.118214 0.7 8 512 vdd07.txt fp07.txt > results/log07512.log #sp-0.0
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.11629638671875 0.118214 0.7 8 256 vdd07.txt fp07.txt > results/log07256.log #sp-0.1
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.11629638671875 0.118214 0.7 8 128 vdd07.txt fp07.txt > results/log07128.log #sp-0.2
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.11629638671875 0.118214 0.7  8 64 vdd07.txt fp07.txt > results/log0764.log #sp-0.3
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.11629638671875 0.118214 0.7 8 32 vdd07.txt fp07.txt > results/log0732.log #sp-0.4
rm snmout.exe

#0.8V

g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.12978515625 0.141466 0.8 8 512 vdd08.txt fp08.txt > results/log08512.log #sp-0.0
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.12978515625 0.141466 0.8 8 256 vdd08.txt fp08.txt > results/log08256.log #sp-0.1
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.12978515625 0.141466 0.8 8 128 vdd08.txt fp08.txt > results/log08128.log #sp-0.2
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.12978515625 0.141466 0.8  8 64 vdd08.txt fp08.txt > results/log0864.log #sp-0.3
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.12978515625 0.141466 0.8 8 32 vdd08.txt fp08.txt > results/log0832.log #sp-0.4
rm snmout.exe

#0.9V

g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.14122924804688 0.165056 0.9 8 512 vdd09.txt fp09.txt > results/log09512.log #sp-0.0
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.14122924804688 0.165056 0.9 8 256 vdd09.txt fp09.txt > results/log09256.log #sp-0.1
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.14122924804688 0.165056 0.9 8 128 vdd09.txt fp09.txt > results/log09128.log #sp-0.2
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.14122924804688 0.165056 0.9  8 64 vdd09.txt fp09.txt > results/log0964.log #sp-0.3
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.14122924804688 0.165056 0.9 8 32 vdd09.txt fp09.txt > results/log0932.log #sp-0.4
rm snmout.exe

#1.0V

g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.15142822265625 0.188941 1.0 8 512 vdd10.txt fp10.txt > results/log10512.log #sp-0.0
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.15142822265625 0.188941 1.0 8 256 vdd10.txt fp10.txt > results/log10256.log #sp-0.1
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.15142822265625 0.188941 1.0 8 128 vdd10.txt fp10.txt > results/log10128.log #sp-0.2
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.15142822265625 0.188941 1.0  8 64 vdd10.txt fp10.txt > results/log1064.log #sp-0.3
rm snmout.exe
g++ -std=c++0x snmfp.cpp -o snmout.exe -lm
./snmout.exe 0.15142822265625 0.188941 1.0 8 32 vdd10.txt fp10.txt > results/log1032.log #sp-0.4
rm snmout.exe


