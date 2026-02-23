#include "Painting.h"
#include "Art.h"
#include "Movie.h"
 
int main(){
 
  // Instantiation of child objects
  Painting Painting("Mona Lisa");
  Movie Animation("Pinocchio");
 
  // Art Pointers to child objects (Polymorphism)
  Art *painting1 = &Painting;
  Art *movie1 = &Animation;
 
  // Painting functions calls
  painting1->CallMyType();
  painting1->CallMyTitle();
  painting1->DescribeMe();
 
  cout << endl;
 
  // Movie function calls
  movie1->CallMyType();
  movie1->CallMyTitle();
  movie1->DescribeMe();

  return 0;
}
