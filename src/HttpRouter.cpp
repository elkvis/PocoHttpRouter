//
// Created by team_dev on 7/29/16.
//

#include <iostream>
#include "HttpRouter.h"
//#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/URI.h"
#include "Poco/Net/MediaType.h"

bool operator < (const HttpRoute& lhs, const HttpRoute& rhs)
{
  return lhs.path > rhs.path;
}

class HttpRouteRequestHandler : public Poco::Net::HTTPRequestHandler
{
    HttpRouteHandler m_handler;
  public:
    HttpRouteRequestHandler(const HttpRouteHandler& handler) : m_handler(handler)
    {

    }

    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
    {
      m_handler(request, response);
    }
};

Poco::Net::HTTPRequestHandler* HttpRouter::createRequestHandler(const Poco::Net::HTTPServerRequest& request)
{
  Poco::URI uri(request.getURI());

  for (auto& route : m_routes)
  {
    bool methodFound = std::find(route.methods.begin(), route.methods.end(), request.getMethod()) != route.methods.end();

    if ((route.path == "/" || uri.getPath() == route.path || uri.getPath().find(route.path + "/") == 0) && (route.methods.empty() || methodFound))
    {
      std::cout << "Chosen Route Path: " << request.getMethod() << ":" << route.path << std::endl;
      return new HttpRouteRequestHandler(route.handler);
    }
  }

  return nullptr;
}

void HttpRouter::AddRoute(const HttpRoute& route)
{
  m_routes.insert(route);
}

void HttpRouter::AddRoute(const std::string& path, HttpRouteHandler handler)
{
  AddRoute(path, handler, { });
}

void HttpRouter::AddRoute(const std::string& path, HttpRouteHandler handler, const std::string& method)
{
  AddRoute(path, handler, { method });
}

void HttpRouter::AddRoute(const std::string& path, HttpRouteHandler handler, const std::initializer_list<std::string>& methods)
{
  AddRoute({ methods, path, handler });
}