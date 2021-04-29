#include <iostream>

using namespace std;

static const int N = 10;

/*
** This program reads a sequence of pairs of nonnegative integers less than N
*from standard input
** Interpreting p q to mean connect object p to object q and prints out pairs
*representing objects that are not yet connected.
** It maintains an array id that has an entry for each object, with the property
*that id[q] == id[p]  if and only if p and q are connected.
** For simplicity we define N as a constant but can change it to be taken from
*user input.
*/
void QuickFind() {
  int i, p, q, id[N];
  for (i = 0; i < N; i++) {
    /* We loop through id and in the beginning each number i will have id[i] ==
     * i because it is not connected to anything */
    id[i] = i;
  }
  while (cin >> p >> q) { // read user input
    int t = id[p];        // set t to id of p
    // find operation
    if (t == id[q]) {
      for (int k = 0; k < N; k++) {
        cout << id[k] << " ";
      }
      cout << endl;
      // if p and q have the same id they are connect so we dont output anything
      continue;
    }
    // union operation
    for (i = 0; i < N; i++) {
      // we loop through the whole array and change all entries with the same id
      // as p to have the same id as q so in essense we take all connections of
      // p and connect them to q.
      // this choice is arbitary and we couldve changed
      // all entries with id q to id p
      if (id[i] == t) {
        cout << "changing id of " << i << " which currently is " << id[i]
             << endl;
        id[i] = id[q];
        cout << "id of " << i << " is now " << id[i] << endl;
        for (int k = 0; k < N; k++) {
          cout << id[k] << " ";
        }
        cout << endl;
      }
    }
    cout << p << "-" << q << endl;
  }
}

void QuickUnion() {
  int i, j, p, q, id[N];
  // id[i] = i at the start
  for (i = 0; i < N; i++) {
    id[i] = i;
  }
  while (cin >> p >> q) {
    for (i = p; i != id[i]; i = id[i]) // find the root pointer of p
      ;
    for (j = q; j != id[j]; j = id[j]) // find the root pointer of q
      ;
    if (i == j) // if pointers are the same then the two objects are connected
      continue;
    id[i] = j; // otherwise we make a connection between root of p and q
    cout << " " << p << " " << q << endl;
  }
}

int main(int argc, char *argv[]) {
  QuickFind();
  return 0;
}
