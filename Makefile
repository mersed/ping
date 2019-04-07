output: main.o IpV4.o
	g++ main.o IpV4.o -o net-map

IpV4.o:
	g++ -c IpV4.cpp

main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm *.o net-map