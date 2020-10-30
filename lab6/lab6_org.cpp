#include <iostream>
using namespace std;


class Book{
  private:
    string title;
    long ISBN;

  public:
};


int main()
{
  string titleArr [] = {"Sherlock Holmes: The Complete Novels and Stories",
  "The Very Hungry Caterpillar","Goodnight Moon","On the Night You Were Born",
  "The Kissing Hand","The Monster at the End of this Book",
  "The Story of Ruby Bridges","The Road Not Taken and Other Poems",
  "The Cat in the Hat and Other Dr. Seuss Favorites","Green Eggs and Ham",
  "One Morning in Maine","The Glass Castle","A Child's Garden of Verses",
  "Twenty Love Poems and a Song of Despair","The Lorax",
  "Letters to a Young Poet","The Body","The Missing Piece Meets the Big O",
  "Matilda","Harry Potter and the Sorcerer's Stone"};
  long isbnArr [] = {9780553212419,9780241003008,9780060775858,9780312346065,
    9781933718002,9780375829130,9780439598446,9780486275505,9780807218730,
    9780394800165,9780140501742,9780743247542,9780689823824,9780143039969,
    9780679889106,9780486422459,9780582418172,9780060256579,9780141301068,
    9780439554930};

  return 0;
}
