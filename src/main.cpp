
#include <cstdlib>
#include <utility>
#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
#include "Labirinto.hpp"
using namespace std;
int
main ()
{
  Labirinto j;
  int l, c, n;
  l = 0;
  c = 0;
  cout << "De o tamanho da matriz Labirinto: " << endl;
  cin >> n;
  j.setN (n);
  j.create (n);
  cout << "Original:" << endl;
  j.mostra (n);

  j.CaminhoDFS(n);

  cout << "Matriz caminhada:" << endl;
  j.mostra (n);

  return 0;
}
