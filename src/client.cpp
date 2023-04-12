#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: client <host>" << std::endl;
      return 1;
    }
    //1.io_context
    boost::asio::io_context io_context;

    //2.What is endpoint ?
    //Data stucture used to store ip + port

    //3.resolver
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints =
      resolver.resolve(argv[1], "daytime");

    //4.socket
    tcp::socket socket(io_context);
    
    //5.connect
    boost::asio::connect(socket, endpoints);

    for (;;)
    {
      //6.Buffer
      //The requirement is to use mutable buffer sequence
      //Simply a sequence of asio::mutable_buffer objects
      boost::array<char, 128> buf;

      //7.Error checking mechanism provided
      boost::system::error_code error;

      //boost::asio::buffer is used so that an object is created which automatically determines the size of buffer 
      //and prevents overflow also the object is typecasted into object mutable_buffer_1
      size_t len = socket.read_some(boost::asio::buffer(buf), error);

      if (error == boost::asio::error::eof)
        break; // Connection closed cleanly by peer.
      else if (error)
        throw boost::system::system_error(error); // Some other error.

      std::cout.write(buf.data(), len);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}