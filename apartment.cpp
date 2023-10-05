#include "apartment.h"

using std::cout;
using std::endl;

my_apartment::apartment::apartment(int rooms_, int floor_, int living_area,
                                   int total_area, int people_, int street_,
                                   int house_n_, int apart_n_)
    : rooms(rooms_), floor(floor_) {
  area.living = living_area;
  area.total = total_area;
  people = people_;
  address.street = street_;
  address.house_number = house_n_;
  address.apart_number = apart_n_;
}

my_apartment::apartment::apartment(const apartment& obj)
    : rooms(obj.rooms), floor(obj.floor) {
  area.living = obj.area.living;
  area.total = obj.area.total;
  people = obj.people;
  address.street = obj.address.street;
  address.house_number = obj.address.house_number;
  address.apart_number = obj.address.apart_number;
}

bool my_apartment::apartment::operator==(const apartment& other) const {
  bool result = true;
  if (rooms != other.rooms || floor != other.floor ||
      area.living != other.area.living || area.total != other.area.total ||
      people != other.people ||
      address.apart_number != other.address.apart_number ||
      address.house_number != other.address.house_number ||
      address.street != other.address.street)
    result = false;
  return result;
}

my_apartment::apartment& my_apartment::apartment::operator=(
    const apartment& other) {
  rooms = other.rooms;
  floor = other.floor;
  area.living = other.area.living;
  area.total = other.area.total;
  people = other.people;
  address.street = other.address.street;
  address.house_number = other.address.house_number;
  address.apart_number = other.address.apart_number;
  return *this;
}

std::ostream& my_apartment::operator<<(std::ostream& os,
                                       const my_apartment::apartment& obj) {
  os << "Apartment, "
     << "street: " << obj.address.street
     << ", house number: " << obj.address.house_number
     << ", apartment number: " << obj.address.apart_number << endl;
  return os;
}
