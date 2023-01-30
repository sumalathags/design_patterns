 g++ -c logger.cpp
 ar ru lib.a logger.o
 g++ -o driver driver.cpp lib.a
 ./driver
