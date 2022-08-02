#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <memory>
#include <thread>
#include "server/XMLRPCAbyssServer.hpp"
#include "logic/Data.hpp"

// called at exit
void onshutdown() {
	std::cerr << "Daemon::shutdown" << std::endl; 
}

int main(int argc, char *argv[])
{	
	// unused variables
	(void)argc;
	(void)argv;

	// call onshutdown() at program exit
	atexit(onshutdown);  

	// Example data container for domain logic
	auto data = std::make_shared<Data>();

	// To communicate between URScript and the executable we use the xmlrpc-c library
	// This library is standard available on the robot and in the development toolchain.
	AbyssServer server(data);

	// Run server in a separate thread
	std::thread serverT(&AbyssServer::run, &server);

	std::cout << "Hello World started" << std::endl;

	// wait for the server thread to terminate
	serverT.join();

	return 0;
}
