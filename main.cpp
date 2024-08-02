#include <iostream>

#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <asio/ts/internet.hpp>
#include <asio/ts/buffer.hpp>

int main() {
    asio::error_code ec;
    asio::io_context context;
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("173.194.221.113", ec), 80);
    asio::ip::tcp::socket socket(context);

    socket.connect(endpoint, ec);
    if (!ec) {
        std::cout << "Connected";
    } else {
        std::cout << "Something went wrong!";
    }
    return 0;
}
