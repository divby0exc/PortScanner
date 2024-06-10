#include <iostream>
#include <Poco/Net/Socket.h>
#include <Poco/Net/StreamSocket.h>

int main() {
	Poco::Net::IPAddress address("127.0.0.1");
	Poco::Net::SocketAddress socket_address("127.0.0.1:8080");
	Poco::Net::SocketAddress socket_address2("127.0.0.1", 8080);

	try {
	Poco::Net::StreamSocket socket(socket_address2);
	socket.connect(socket_address2);
	socket.close();

	}
	catch (Poco::Exception& exc) {
		std::cout << exc.displayText() << "\n";
	}



	

	return 0;
}