#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nextpowerof2 (int k) {
  return pow (2, int (ceil (log2 (k))));
}

void display (vector < vector < int >>&matrix, int m, int n) {
  for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (j != 0)
	    {
	      cout << "\t";
	    }
	  cout << matrix[i][j];
	}
      cout << endl;
    }
}

void add (vector < vector < int >>&A, vector < vector < int >>&B, vector < vector < int >>&C, int size) {
  int i, j;
  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++){
	    C[i][j] = A[i][j] + B[i][j];
	    }
    }
}

void sub (vector < vector < int >>&A, vector < vector < int >>&B, vector < vector < int >>&C, int size) {
  int i, j;
  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++) {
	    C[i][j] = A[i][j] - B[i][j];
	    }
    }
}

void Strassen_algorithmA (vector < vector < int >>&A, vector < vector < int >>&B, vector < vector < int >>&C, int size)
{
  if (size == 1)
    {
      C[0][0] = A[0][0] * B[0][0];
      return;
    }
  else
    {
        int new_size = size / 2;
        vector < int >z (new_size);
        vector < vector < int >>a11 (new_size, z), a12 (new_size, z),
    	a21 (new_size, z), a22 (new_size, z), b11 (new_size, z),
    	b12 (new_size, z), b21 (new_size, z), b22 (new_size, z),
    	c11 (new_size, z), c12 (new_size, z), c21 (new_size, z),
    	c22 (new_size, z), p1 (new_size, z), p2 (new_size, z), p3 (new_size,z),
    	p4 (new_size, z), p5 (new_size, z), p6 (new_size, z), p7 (new_size,z),
    	aResult (new_size, z), bResult (new_size, z);

    int i, j;

//dividing the matrices into sub-matrices:
    for (i = 0; i < new_size; i++)
	{
	  for (j = 0; j < new_size; j++)
	    {
	      a11[i][j] = A[i][j];
	      a12[i][j] = A[i][j + new_size];
	      a21[i][j] = A[i + new_size][j];
	      a22[i][j] = A[i + new_size][j + new_size];

	      b11[i][j] = B[i][j];
	      b12[i][j] = B[i][j + new_size];
	      b21[i][j] = B[i + new_size][j];
	      b22[i][j] = B[i + new_size][j + new_size];
	    }
	}

// Calculating p1 to p7:

      add (a11, a22, aResult, new_size);
      add (b11, b22, bResult, new_size);
      Strassen_algorithmA (aResult, bResult, p1, new_size);

      add (a21, a22, aResult, new_size);
      Strassen_algorithmA (aResult, b11, p2, new_size);

      sub (b12, b22, bResult, new_size);
      Strassen_algorithmA (a11, bResult, p3, new_size);

      sub (b21, b11, bResult, new_size);
      Strassen_algorithmA (a22, bResult, p4, new_size);

      add (a11, a12, aResult, new_size);
      Strassen_algorithmA (aResult, b22, p5, new_size);

      sub (a21, a11, aResult, new_size);
      add (b11, b12, bResult, new_size);

      Strassen_algorithmA (aResult, bResult, p6, new_size);

      sub (a12, a22, aResult, new_size);
      add (b21, b22, bResult, new_size);

      Strassen_algorithmA (aResult, bResult, p7, new_size);


      add (p3, p5, c12, new_size);
      add (p2, p4, c21, new_size);

      add (p1, p4, aResult, new_size);
      add (aResult, p7, bResult, new_size);
      sub (bResult, p5, c11, new_size);

      add (p1, p3, aResult, new_size);
      add (aResult, p6, bResult, new_size);
      sub (bResult, p2, c22, new_size);


        for (i = 0; i < new_size; i++)
	    {
	        for (j = 0; j < new_size; j++)
	        {
	      C[i][j] = c11[i][j];
	      C[i][j + new_size] = c12[i][j];
	      C[i + new_size][j] = c21[i][j];
	      C[i + new_size][j + new_size] = c22[i][j];
	        }
	    }
    }
}

void Strassen_algorithm (vector < vector < int >>&A, vector < vector < int >>&B, int m, int n, int a, int b) {

  int k = max ({ m, n, a, b });

  int s = nextpowerof2 (k);

  vector < int >z (s);
  vector < vector < int >>Aa (s, z), Bb (s, z), Cc (s, z);

  for (unsigned int i = 0; i < m; i++)
    {
      for (unsigned int j = 0; j < n; j++)
	    {
	         Aa[i][j] = A[i][j];
	    }
    }
    for (unsigned int i = 0; i < a; i++)
    {
      for (unsigned int j = 0; j < b; j++)
	    {
	        Bb[i][j] = B[i][j];
	    }
    }
      Strassen_algorithmA (Aa, Bb, Cc, s);
      vector < int >temp1 (b);
      vector < vector < int >>C (m, temp1);
      for (unsigned int i = 0; i < m; i++)
        {
          for (unsigned int j = 0; j < b; j++)
    	    {
    	        C[i][j] = Cc[i][j];
    	    }
        }
    display (C, m, b);
}



int main ()
{

      clock_t start = clock ();
    
      int m1, n1;
      cout << "Enter number of rows n columns of first matrix: ";
      cin >> m1 >> n1;
      vector < vector < int >>matrix1 (m1, vector < int >(n1));
    
      for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
    	    cin >> matrix1[i][j];
    	  }
        cout << endl;
        }
    
      int m2, n2;
      cout << "Enter number of rows n columns of second matrix: ";
      cin >> m2 >> n2;
      vector < vector < int >>matrix2 (m2, vector < int >(n2));
    
      for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
    	         cin >> matrix2[i][j];
    	    }
        cout << endl;
        }
        
      Strassen_algorithm (matrix1, matrix2, m1, m2, n1, n2);
    
      clock_t stop = clock ();
      double elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
      printf ("Time taken by program for the input entered in ms: %f", elapsed);
    
      return 0;
}