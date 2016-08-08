//
// Created by team_dev on 7/29/16.
//

#ifndef POCOSECUREHTTPTIMESERVER_HTTPROUTER_H
#define POCOSECUREHTTPTIMESERVER_HTTPROUTER_H

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequestImpl.h"
#include "Poco/Net/HTTPServerResponse.h"
#include <functional>
#include <vector>
#include <string>
#include <set>

typedef std::function<void(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)> HttpRouteHandler;

struct HttpRoute
{
  std::vector<std::string> methods;
  std::string path;
  HttpRouteHandler handler;
};

extern bool operator < (const HttpRoute& lhs, const HttpRoute& rhs);

class HttpRouter : public Poco::Net::HTTPRequestHandlerFactory
{
    std::multiset<HttpRoute> m_routes;

  public:
    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

    void AddRoute(const HttpRoute& route);
    void AddRoute(const std::string& path, HttpRouteHandler handler);
    void AddRoute(const std::string& path, HttpRouteHandler handler, const std::string& method);
    void AddRoute(const std::string& path, HttpRouteHandler handler, const std::initializer_list<std::string>& methods);
};


#endif //POCOSECUREHTTPTIMESERVER_HTTPROUTER_H
