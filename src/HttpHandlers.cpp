//
// Created by team_dev on 7/29/16.
//

#include <iostream>
#include <string>
#include "Poco/Net/HTTPServerRequestImpl.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/MediaType.h"
#include "Poco/URI.h"
#include "HttpHandlers.h"

void GetHandler(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
  response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
  response.setKeepAlive(true);

  response.setContentType(Poco::Net::MediaType("text/plain"));
  std::ostream& os = response.send();

  os << "GetHandler(): " << request.getURI() << std::endl;
  Poco::URI uri(request.getURI());
  std::string query = uri.getQuery();

  std::cout << uri.getQuery() << std::endl;

  os.flush();
}

void OtherGetHandler(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
  response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
  response.setKeepAlive(true);

  response.setContentType(Poco::Net::MediaType("text/plain"));
  std::ostream& os = response.send();

  os << "OtherGetHandler(): " << request.getURI() << std::endl;

  os.flush();
}

void PostHandler(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
  response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
  response.setKeepAlive(true);

  response.setContentType(Poco::Net::MediaType("text/plain"));
  std::ostream& os = response.send();

  os << "PostHandler()" << request.getURI() << std::endl;

  os.flush();
}

void HandlerClass::operator()(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
  response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
  response.setKeepAlive(true);

  response.setContentType(Poco::Net::MediaType("text/plain"));
  std::ostream& os = response.send();

  os << "HandlerClass::operator()" << request.getURI() << std::endl;

  os.flush();
}