#pragma once

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include "logic/Data.hpp"

/**
 * Add a XMLRPC adapter (i.e. Hello) for each method that should be exposed through XML-RPC.
 * Relevant XMLRPC-C documentation can be found here: http://xmlrpc-c.sourceforge.net/doc/libxmlrpc_server++.html
 */
class GetTitle : public xmlrpc_c::method
{
public:
    GetTitle(std::shared_ptr<Data> data);
    void execute(xmlrpc_c::paramList const &paramList, xmlrpc_c::value *const retvalP);

private:
    GetTitle(); // Hereby disabled
    std::shared_ptr<Data> data;
};

class SetTitle : public xmlrpc_c::method
{
public:
    SetTitle(std::shared_ptr<Data> data);
    void execute(xmlrpc_c::paramList const &paramList, xmlrpc_c::value *const retvalP);

private:
    SetTitle(); // Hereby disabled
    std::shared_ptr<Data> data;
};

class GetMessage : public xmlrpc_c::method
{
public:
    GetMessage(std::shared_ptr<Data> data);
    void execute(xmlrpc_c::paramList const &paramList, xmlrpc_c::value *const retvalP);

private:
    GetMessage(); // Hereby disabled
    std::shared_ptr<Data> data;
};
