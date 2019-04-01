#ifndef CORE_INTERFACE_ERROR_HPP_
#define CORE_INTERFACE_ERROR_HPP_

namespace ipm_broker {
namespace error {

enum MessageError {
  kBufferOverflow,
  kNullPointer,
  kSuccess
};

} // error
} // ipm_broker

#endif // CORE_INTERFACE_ERROR_HPP_
