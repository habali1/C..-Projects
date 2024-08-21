#include <iostream>
#include <stdlib.h>
#include "SongCollection.h"
using namespace std;

int main(int argc, char *argv[]) {
   Song one;
   Song *two = new Song("In Your Eyes", 1986, "Peter Gabriel");
   Song *three = new Song("redrum" , 2024, "21 Savage");
   one.show();
   two->show();
   three->show();
   delete(two);
   SongCollection myCollection(*three);
   myCollection.show();
   return 0;
}
