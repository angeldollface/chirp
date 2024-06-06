build: ; gcc src/main.c src/lib/*.c src/lib/*.h -o chirp -s -O2 -static
clean: ; rm -rf chirp
