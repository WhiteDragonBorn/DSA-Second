#pragma once
namespace my_apartment {
class apartment {
  const int rooms;
  const int floor;
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

 public:
  apartment() = default;
  apartment(int rooms_, int floor_, int living_area, int total_area,
            int people_, int street_, int house_n_, int apart_n_);
  apartment(const apartment& obj);

  bool operator==(const apartment& other) const;
};
}  // namespace my_apartment
