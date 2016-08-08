//
// Created by team_dev on 7/29/16.
//

#ifndef POCOSECUREHTTPTIMESERVER_HTTPHANDLERS_H
#define POCOSECUREHTTPTIMESERVER_HTTPHANDLERS_H

#include "Poco/Net/HTTPServerRequestImpl.h"
#include "Poco/Net/HTTPServerResponse.h"

extern void GetHandler(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
extern void OtherGetHandler(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
extern void PostHandler(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

class HandlerClass
{
  public:
    void operator()(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};

#endif //POCOSECUREHTTPTIMESERVER_HTTPHANDLERS_H
