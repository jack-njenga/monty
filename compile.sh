#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty && ./monty bytecodes/00.m
