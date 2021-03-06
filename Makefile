# Copyright 2016 wink saville
#
# licensed under the apache license, version 2.0 (the "license");
# you may not use this file except in compliance with the license.
# you may obtain a copy of the license at
#
#     http://www.apache.org/licenses/license-2.0
#
# unless required by applicable law or agreed to in writing, software
# distributed under the license is distributed on an "as is" basis,
# without warranties or conditions of any kind, either express or implied.
# see the license for the specific language governing permissions and
# limitations under the license.

#CC = clang
CC = gcc

CFLAGS = -m64 -O3 -Wall -std=c11

all: test

test.o: test.c
	$(CC) -x c $(CFLAGS) -o test.o -c test.c
	objdump -d test.o > test.txt

test: test.o
	$(CC) $(CFLAGS) test.o -o test

clean:
	rm -f test test.o test.txt
