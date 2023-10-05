#pragma once
#include <iostream>
#include <string>
// #include <vector>

// const std::string STREETS[2] = {"", ""};

namespace my_apartment {

class apartment {
 private:
  int rooms;
  int floor;
  struct {
    int living;
    int total;
  } area;
  int people;
  struct {
    int street;
    int house_number;
    int apart_number;
  } address;
  // static std::string STREETS;

 public:
  // apartment();
  apartment(int rooms_, int floor_, int living_area, int total_area,
            int people_, int street_, int house_n_, int apart_n_);
  apartment(const apartment& obj);

  bool operator==(const apartment& other) const;
  apartment& operator=(const apartment& other);
  friend std::ostream& operator<<(std::ostream& os, const apartment& obj);
};
}  // namespace my_apartment

// my_apartment::apartment::STREETS