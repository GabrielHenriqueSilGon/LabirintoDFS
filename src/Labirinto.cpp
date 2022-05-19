#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <stack>
#include <bits/stdc++.h>
#include "Labirinto.hpp"
using namespace std;

void
Labirinto::setN (int n)
{
  int l, c;
  grade = new int *[n];
  for (int i = 0; i < n; ++i)
    grade[i] = new int[n];

}


void
Labirinto::create (int n)
{
  int l, c, b, auxb, numerobloqueios;
  numerobloqueios = 6;		//mudar esse numero conforme o numero de bloqueios
  pair <int,int> bloqueios[numerobloqueios];

  bloqueios[0] = {0, 1};
  bloqueios[1] = {1, 1};
  bloqueios[2] = {2, 1};
  bloqueios[3] = {4, 0};
  bloqueios[4] = {5,4};
  bloqueios[5] = {4,3};
  //bloqueios[6] = {,};
  //bloqueios[7] = {,};
  //bloqueios[8] = {,};
  //bloqueios[9] = {,};
  //bloqueios[10] = {,};

  for (l = 0; l < n; l++)
    {
      for (c = 0; c < n; c++)
	{
	  this->grade[l][c] = 0;
	  for (b = 0; b < numerobloqueios; b++)
	    {
	      if (l == bloqueios[b].first && c == bloqueios[b].second)
		this->grade[l][c] = 1;
	    }
	}
    }
  this->grade[0][0] = 0;
}



void
Labirinto::setGrade (int l, int c)
{

  this->grade[l][c] = -1;

}


void
Labirinto::mostra (int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (grade[i][j] == 1)
	    cout << "x | \t";
	  else if (grade[i][j] == -1)
	    cout << "o | \t";
	  else
	    cout << "  | \t";
	}
      cout << endl << "-----------------------------------------------" <<
	endl;
    }

}

pair < int, int >
Labirinto::Proximo (pair < int, int >local, int n)
{
 
  if (local.first + 1 < n && grade[local.first + 1][local.second] == 0)
    {
    return {local.first + 1,local.second};
    }

  else if (local.second + 1 < n && grade[local.first][local.second + 1] == 0)
     {
      return {local.first,local.second + 1};
    }
  else if (local.first != 0 && grade[local.first - 1][local.second] == 0)
     {
      return {local.first - 1,local.second};
    }
  else if (local.second != 0 && grade[local.first][local.second - 1] == 0)
     {
      return {local.first,local.second - 1};
    }
  else
    {
      return{-1,-1};
    }

}


void
Labirinto::CaminhoDFS (int n)
{
  int iteracoes = 0;
  pair <int,int> local = {0, 0};
  pair <int,int> teste = {-1,-1};
  stack<pair<int, int> > caminho;
  caminho.push (local);
  this->grade[0][0] = -1;
  while (((local.first) != (n - 1)) || ((local.second) != (n - 1)))
    {
        
        if (Proximo(local, n) == teste)
        {
            caminho.pop();
            this->grade[local.first][local.second] = -1;
            local = caminho.top();
            //iteracoes++;
        }
        
        else
        {
        caminho.push (Proximo(local,n));
        this->grade[local.first][local.second] = -1;
        local = caminho.top();
        iteracoes++;
        }
        
    }
    
    
    grade[n - 1][n - 1] = -1;
    cout << "===============================================\n" ;
    cout << "Caminho encontrado em " << iteracoes << " iteracoes.\n";
    
}
