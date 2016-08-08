#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/SecureStreamSocket.h"
#include "Poco/Net/SecureServerSocket.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/MediaType.h"
#include <iostream>
#include <sstream>
#include "HttpRouter.h"
#include "HttpHandlers.h"

void DefaultRequestHandler(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
  response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
  response.setContentType(Poco::Net::MediaType("text/plain"));
  response.setKeepAlive(true);
  auto& os = response.send();

  os << "It Works! " << request.getURI() << std::flush;
}

class HttpRouterTest: public Poco::Util::ServerApplication
{
public:
    HttpRouterTest()
	{

	}
	
	~HttpRouterTest()
	{

	}

protected:
	void initialize(Application& self)
	{
	  loadConfiguration("HttpRouter.properties");
    Poco::Util::ServerApplication::initialize(self);
	}
		
	void uninitialize()
	{
    Poco::Util::ServerApplication::uninitialize();
	}

	int main(const std::vector<std::string>&)
	{
    unsigned short port = (unsigned short) config().getInt("HttpRouter.port", 9443);

    std::cout << port << std::endl;

    Poco::Net::SecureServerSocket svs(port);

    HttpRouter* router = new HttpRouter();

    router->AddRoute("/foo", GetHandler, "GET");
    router->AddRoute("/foo/bar", OtherGetHandler, "GET");
    router->AddRoute("/foo", PostHandler, "POST");
    router->AddRoute("/bar", HandlerClass(), "GET");
    router->AddRoute("/", DefaultRequestHandler);

    auto params = new Poco::Net::HTTPServerParams();

    Poco::Net::HTTPServer srv(router, svs, params);
    srv.start();
    waitForTerminationRequest();
    srv.stop();

    return Poco::Util::Application::EXIT_OK;
  }
};


POCO_SERVER_MAIN(HttpRouterTest)
