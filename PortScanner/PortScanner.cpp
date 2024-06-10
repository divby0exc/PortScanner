#include <iostream>
#include <Poco/Net/StreamSocket.h>
#include <vector>
#include <string>
#include <iomanip>

int main() {
	std::vector<std::string> ports{ "20","21","22","23","25","53","137","139","445","80","443","8080","8443","1433","1434","3306","3389", "5000"};

	std::cout << "-------------------------------------------\n";
	for (size_t i{ 0 }; i < ports.size(); ++i)
	{
		try
		{
			Poco::Net::StreamSocket socket(Poco::Net::SocketAddress("127.0.0.1",ports[i]));
			std::cout << "|Port: ";
			std::cout << std::right << std::setw(12) << ports[i];
			std::cout << std::right << std::setw(25) << "OPEN|\n";
			std::cout << "-------------------------------------------\n";
			socket.close();
		}
		catch (Poco::Exception& exc)
		{
			std::cout << "|Port: ";
			std::cout << std::right << std::setw(12) << ports[i];
			std::cout << std::right << std::setw(25) << "CLOSED|\n";
			std::cout << "-------------------------------------------\n";
		}
	}


	return 0;
}