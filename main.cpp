#include <iostream>

#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <asio/ts/internet.hpp>
#include <asio/ts/buffer.hpp>
#include <string>
#include <thread>
#include <chrono>

int main() {
    asio::error_code ec;
    asio::io_context context;
    std::string ipaddr{"173.194.221.113"};
    int port{80};
    auto time = std::chrono::system_clock::now();
    std::time_t currenttime = std::chrono::system_clock::to_time_t(time);

    asio::ip::tcp::endpoint endpoint(asio::ip::make_address(ipaddr, ec), port);
    asio::ip::tcp::socket socket(context);

    socket.connect(endpoint, ec);
    if (!ec) {
        std::string request{"GET /index.html HTTP/1.1\r\n"
                            "Host: google.com\r\n"
                            "Connection: close\r\n\r\n"};
        std::cout << "Connected to " << ipaddr << " by " << port <<  " port" << std::endl;
        std::cout << "Connection was at " << std::ctime(&currenttime) << std::endl;

        socket.write_some(asio::buffer(request.data(), request.size()),ec);
        //std::this_thread::sleep_for(std::chrono::seconds(3));

        size_t bytes = socket.available();
        std::cout << bytes << " bytes are available to read\n";
        if (bytes > 0) {
            std::vector<char> rBuffer(bytes);
            socket.read_some(asio::buffer(rBuffer.data(), rBuffer.size()), ec);
            std::cout << "Message from " << ipaddr << ":\n";
            for(auto byte : rBuffer) {
                std::cout << byte;
            }
        }
    } else {
        std::cout << "Something went wrong!";
    }
    return 0;
}
