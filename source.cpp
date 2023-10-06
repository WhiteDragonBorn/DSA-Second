#include <fstream>
#include <iostream>
#include <vector>

#include "apartment.h"
#include "linkedList.h"
#include "node_d.h"

using std::cout;
using std::endl;

int main() {
  setlocale(LC_ALL, "Russian");

  std::ifstream FILE_IN("data_in.txt");

  my_linkedList::linkedList information;

  if (FILE_IN.is_open()) {
    std::vector<int> temp_vec;
    temp_vec.reserve(8);
    while (!FILE_IN.eof()) {
      int temp;
      FILE_IN >> temp;
      temp_vec.push_back(temp);
      if (temp_vec.size() == 8) {
        my_apartment::apartment Test(temp_vec[0], temp_vec[1], temp_vec[2],
                                     temp_vec[3], temp_vec[4], temp_vec[5],
                                     temp_vec[6], temp_vec[7]);

        temp_vec.clear();
        information.addToHead(Test);
      }
    }
  } else {
    cout << "Couldn't open the file.";
  }

  information.printList();
  cout << endl << "------------" << endl;
  my_apartment::apartment Test(0, 0, 0, 0, 0, 0, 0, 0);
  // Node_d* thead = information.getHead();
  information.addBeforeNode(information.getHead(), Test);
  cout << information.getHead()->data;
  cout << information.getTail()->data;
  cout << endl << "------------" << endl;
  information.printList();
  information.deleteCurrentNode(information.getHead()->next);
  // information.deleteAfterNode(information.getHead());
  // information.deleteBeforeNode(information.getHead()->next);
  information.printList();
  cout << endl << "------------" << endl;

  my_linkedList::linkedList newInformation(information);
  my_linkedList::linkedList veryNewInformation;
  veryNewInformation = newInformation;
  newInformation.printList();
  veryNewInformation.printList();
  FILE_IN.close();
}
