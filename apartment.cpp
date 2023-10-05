#include "apartment.h"

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

bool my_apartment::apartment::operator==(const apartment& other) const
{
  return false;
}
