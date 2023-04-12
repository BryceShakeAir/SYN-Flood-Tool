// ip_hdrincl.hpp
// IP_HDRINCL of raw socket
// This is available only for basic_raw_socket
//
#ifndef BOOST_ASIO_IP_HDRINCL_SOCKOPT
#define BOOST_ASIO_IP_HDRINCL_SOCKOPT

#include <netinet/in.h>
#include <sys/socket.h>

namespace boost {
namespace asio {
namespace ip {
    
// This meets SettableSocketOption requirements
// https://www.boost.org/doc/libs/1_50_0/doc/html/boost_asio/reference/SettableSocketOption.html
// Refer this link !
// This protocol is specified because internally this function is called
// int setsockopt(int socket, int level, int option_name,
//       const void *option_value, socklen_t option_len);   

class ip_hdrincl {
public:
    ip_hdrincl() : optval(1) {}
    ip_hdrincl(bool ov) : optval(ov ? 1 : 0) {}
    ~ip_hdrincl() {}

    //The level at which this socket option has to be specified
    template<typename Protocol>
    int level(const Protocol &p) const { return SOL_IP; }

    //The name of option
    template<typename Protocol>
    int name(const Protocol &p)  const { return IP_HDRINCL; }

    template<typename Protocol>
    const void *data(const Protocol &p) const { return reinterpret_cast<const void*>(&optval); }

    template<typename Protocol>
    int size(const Protocol &p) const { return sizeof(optval); }
     
private:
    int optval;
};

} // namespace ip
} // namespace asio
} // namespace boost

#endif // BOOST_ASIO_IP_HDRINCL_SOCKOPT

