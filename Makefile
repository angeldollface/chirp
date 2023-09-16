build: ; gcc src/main.c -o chirp -O2
perm: ; chmod a+x chirp
clean: ; rm -rf chirp