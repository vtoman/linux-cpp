gcc race-example1-write-a.c -o race-example1-write-a 
gcc race-example1-write-b.c -o race-example1-write-b 
touch log.txt
./race-example1-write-a &
./race-example1-write-b &
