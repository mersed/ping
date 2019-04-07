output: main.o IpV4.o Ping.o
	g++ main.o IpV4.o Ping.o -o net-map

IpV4.o:
	g++ -c IpV4.cpp
	
Ping.o:
	g++ -c Ping.cpp

main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm *.o net-map