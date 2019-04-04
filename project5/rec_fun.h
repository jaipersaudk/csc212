#ifndef RECURSIVE_FUCNTIONS_H
#define RECURSIVE_FUCNTIONS_H

// any includes

// any namespace

class rec_fun
{
  public:
    void triangle (ostream& outs, unsigned int m, unsigned int n);
    // Precondition: m <= n
    // Postcondition: The function has printed a pattern of 2*(n-m+1) lines
    // to the output stream outs. The first line contains m asterisks, the next
    // line contains m+1 asterisks, and so on up to a line with n asterisks.
    // Then the pattern is repeated backwards, going n back down to m.

    /* Example output:
    triangle(cout, 3, 5) will print this to cout:
    ***
    ****
    *****
    *****
    ****
    ***
    */

    void numbers(ostream& outs, const String& prefix, unsigned int levels);

    bool bears(int n);
    // Postcondition: A true return value means that it is possible to win
    // the bear game by starting with n bears. A false return value means that
    // it is not possible to win the bear game by starting with n bears.
    // Examples:
    // bear(250) is true (as shown above)
    // bear(42) is true
    // bear(84) is true
    // bear(53) is false
    // bear(41) is false

    void pattern(ostream& outs, unsigned int n, unsigned int i);
    // Precondition: n is a power of 2 greater than zero.
    // Postcondition: A pattern based on the above example has been
    // printed to the ostream outs. The longest line of the pattern has
    // n stars beginning in column i of the output.
    //For example, The above pattern is produced by the call pattern(cout, 8, 0).

}
#endif
