#include <memory>
#include <iostream>
#include "server/XMLRPCAbyssServer.hpp"
#include "server/XMLRPCMethods.hpp"

#define SERVER_PORT 40405 // Please use a unique port number!

AbyssServer::AbyssServer(std::shared_ptr<Data> data)
{
    // Add all adapters defined in XMLRPCMethods here
    serviceRegistry.addMethod("get_title", new GetTitle(data));
    serviceRegistry.addMethod("set_title", new SetTitle(data));
    serviceRegistry.addMethod("get_message", new GetMessage(data));

    // you may specify serverOwnsSignals(false), which places the responsibility 
    // on you to handle signals as serverAbyss requires.
    abyssServerP = std::make_unique<xmlrpc_c::serverAbyss>(xmlrpc_c::serverAbyss::constrOpt()
                                                               .registryP(&serviceRegistry)
                                                               .portNumber(SERVER_PORT)
                                                               .keepaliveMaxConn(UINT_MAX)
                                                               .logFileName("/tmp/xmlrpc_log"));
}

AbyssServer::~AbyssServer() {}

void AbyssServer::run()
{
    abyssServerP->run();
    return;
}
