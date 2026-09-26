# COS214 Practical 5

Binary is `campusguard`.

## Docker

```
docker compose up --build
```

Builds the image and starts the container. 

Stop it with:

```
docker compose down
```

Valgrind and GDB need the tools inside the container. `make` already compiles with `-g`.

```
docker compose run --rm --entrypoint make campusguard valgrind
docker compose run --rm -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined --entrypoint gdb campusguard ./campusguard
```

## Local

Same Makefile, if g++ and make are installed:

```
make
./campusguard
make run
make valgrind
make debug
make clean
```
