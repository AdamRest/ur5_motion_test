// Generated by gencpp from file ur_msgs/Digital.msg
// DO NOT EDIT!


#ifndef UR_MSGS_MESSAGE_DIGITAL_H
#define UR_MSGS_MESSAGE_DIGITAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ur_msgs
{
template <class ContainerAllocator>
struct Digital_
{
  typedef Digital_<ContainerAllocator> Type;

  Digital_()
    : pin(0)
    , state(false)  {
    }
  Digital_(const ContainerAllocator& _alloc)
    : pin(0)
    , state(false)  {
  (void)_alloc;
    }



   typedef uint8_t _pin_type;
  _pin_type pin;

   typedef uint8_t _state_type;
  _state_type state;





  typedef boost::shared_ptr< ::ur_msgs::Digital_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ur_msgs::Digital_<ContainerAllocator> const> ConstPtr;

}; // struct Digital_

typedef ::ur_msgs::Digital_<std::allocator<void> > Digital;

typedef boost::shared_ptr< ::ur_msgs::Digital > DigitalPtr;
typedef boost::shared_ptr< ::ur_msgs::Digital const> DigitalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ur_msgs::Digital_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ur_msgs::Digital_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ur_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'ur_msgs': ['/home/amr/ur_ws/src/universal_robot/ur_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ur_msgs::Digital_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ur_msgs::Digital_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ur_msgs::Digital_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ur_msgs::Digital_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ur_msgs::Digital_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ur_msgs::Digital_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ur_msgs::Digital_<ContainerAllocator> >
{
  static const char* value()
  {
    return "83707be3fa18d2ffe57381ea034aa262";
  }

  static const char* value(const ::ur_msgs::Digital_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x83707be3fa18d2ffULL;
  static const uint64_t static_value2 = 0xe57381ea034aa262ULL;
};

template<class ContainerAllocator>
struct DataType< ::ur_msgs::Digital_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ur_msgs/Digital";
  }

  static const char* value(const ::ur_msgs::Digital_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ur_msgs::Digital_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 pin\n"
"bool state\n"
;
  }

  static const char* value(const ::ur_msgs::Digital_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ur_msgs::Digital_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pin);
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Digital_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ur_msgs::Digital_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ur_msgs::Digital_<ContainerAllocator>& v)
  {
    s << indent << "pin: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.pin);
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UR_MSGS_MESSAGE_DIGITAL_H
