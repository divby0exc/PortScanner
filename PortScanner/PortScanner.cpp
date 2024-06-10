#include <iostream>
#include <Poco/Net/StreamSocket.h>
#include <vector>
#include <string>

int main() {
	std::vector<std::string> ports{ "20","21","22","23","25","53","137","139","445","80","443","8080","8443","1433","1434","3306","3389" };


	for (size_t i{ 0 }; i < ports.size(); ++i)
	{
		try
		{
			Poco::Net::StreamSocket socket(Poco::Net::SocketAddress("127.0.0.1",ports[i]));
			std::cout << ports[i] << " is OPEN\n";
			socket.close();
		}
		catch (Poco::Exception& exc)
		{
			std::cout << "Port: " << ports[i] << " is CLOSED\n";
		}
	}


	return 0;
}