
#include "vrpn_Shared.h"


//==========================================================================
//
// class vrpn_McastGroupDescrp
//
// this is a helper class for encapsulating information about the multicast
// channel. this class is marshalled and passed through the network to the 
// client during the setup phase of multicast communications.
//
//==========================================================================
class vrpn_McastGroupDescrp {

public:

  //-------------------------------------------------------------------
  // constructor
  //-------------------------------------------------------------------
  vrpn_McastGroupDescrp(void){};

  //-------------------------------------------------------------------
  // data members
  //-------------------------------------------------------------------
  char d_mcast_group[20]; // string in dot notation
  vrpn_int32 d_mcast_addr; // 32 bit number form
  vrpn_uint16 d_mcast_port;
  vrpn_int32 d_mcast_ttl;

};



//==========================================================================
//
// class vrpn_BaseMulticastChannel
//
// this is the abstract base class from which the other multicast classes 
// inherit, currently there are unreliable sender and receiver classes. in 
// the future there may be reliable sender and receiver classes inheriting
// from this one.
//
//==========================================================================
class vrpn_BaseMulticastChannel {

public:

  //-------------------------------------------------------------------
  // constructors and destructor
  //-----------------------------------------------------------------
  vrpn_BaseMulticastChannel( char* group_name, vrpn_uint16 port);
  ~vrpn_BaseMulticastChannel(void){};

  //-------------------------------------------------------------------
  // get functions
  //------------------------------------------------------------------
  virtual vrpn_int32 get_mcast_info(char *info_buffer) = 0;
  char* get_mcast_group_name(void);

  vrpn_int32 get_mcast_addr(void);
  vrpn_uint16 get_mcast_port_num(void);

  vrpn_int32 get_mcast_sock(void);


protected:

  //-------------------------------------------------------------------
  // set functions
  //-------------------------------------------------------------------
  void set_mcast_group_name(char *);
  void set_mcast_port_num(vrpn_uint16);
  vrpn_int32 set_mcast_sock(vrpn_int32);


  virtual void init_mcast_channel(void) = 0;  // implement in subclasses

  
private:

  //-------------------------------------------------------------------
  // data members
  //-------------------------------------------------------------------
  vrpn_int32 d_mcast_sock;
  vrpn_int32 d_mcast_port;
  char d_mcast_group[20];
  vrpn_int32 d_mcast_ttl;

};


