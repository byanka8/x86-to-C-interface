nasm -f win64 asmDistance.asm
gcc -c cDistance.c -o cDistance.obj -m64
gcc cDistance.obj asmDistance.obj -o cDistance.exe -m64
cDistance.exe