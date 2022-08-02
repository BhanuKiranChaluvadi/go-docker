#pragma once

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>
#include <memory>
#include "logic/Data.hpp"

/**
 * @brief xmlrpc-c Abyss server for XML-RPC communication.
 * See: http://xmlrpc-c.sourceforge.net/doc/libxmlrpc_server_abyss++.html
 *      https://github.com/ensc/xmlrpc-c/blob/master/include/xmlrpc-c/server_abyss.hpp  
 */
class AbyssServer
{
public:
    AbyssServer(std::shared_ptr<Data> data);
    virtual ~AbyssServer();
    void run();

private:
    xmlrpc_c::registry serviceRegistry;
    std::unique_ptr<xmlrpc_c::serverAbyss> abyssServerP;
};
