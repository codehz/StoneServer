#ifndef SIMPPL_DETAIL_CLIENTRESPONSEHOLDER_H
#define SIMPPL_DETAIL_CLIENTRESPONSEHOLDER_H


#include <cstdint>
#include <tuple>


// forward decl
struct ClientResponseBase;
struct DBusPendingCall;


namespace simppl
{
   
namespace dbus
{

// forward decl
struct Dispatcher;

   
namespace detail
{

struct ClientResponseHolder
{
   inline
   ClientResponseHolder(Dispatcher& disp, ClientResponseBase* r)
    : dispatcher_(disp)
    , r_(r)
   {
      // NOOP
   }
   
   Dispatcher& dispatcher_;
   ClientResponseBase* r_;
};


} // namespace detail

}   // namespace dbus

}   // namespace simppl


#endif   // SIMPPL_DETAIL_CLIENTRESPONSEHOLDER_H