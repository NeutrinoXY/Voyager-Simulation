#include <iostream>
#include "Matrice.h"

using namespace std;


Matrice::Matrice(int a, int b)
{
    double** m = new double*[a];
    for(int i=0; i<a ; i++)
    {
        m[i] = new double[b];

        for(int j=0; j<b ; j++)
            m[i][j]=0;

    }
    matrix = m;
    nl = a;
    nc = b;
}

Matrice::~Matrice()
{

}

Matrice operator*(Matrice A, Matrice B)
{
    int nlA, ncA, nlB, ncB;
    A.GetSize(nlA, ncA);
    B.GetSize(nlB, ncB);
    Matrice result(nlA, ncB);

    if(ncA!=nlB)
    {
        cout << "* Impossible" << endl;
        return result;
    }
    else
    {
        double** m = new double*[nlA];

        for(int i=0; i<nlA ; i++)
        {
            m[i] = new double[ncB];
            for (int j=0; j<ncB; j++)
                m[i][j] = 0;
        }

        for(int i=0; i<nlA ; i++)
            for(int j=0; j<ncB ; j++)
                for(int k=0; k<ncA ; k++){
                    m[i][j]+=(A.GetValue(i,k))*(B.GetValue(k,j));}

        result.Set(m);

        return result;
    }
}


Matrice operator+(Matrice A, Matrice B)
{
    int nlA, ncA, nlB, ncB;
    A.GetSize(nlA, ncA);
    B.GetSize(nlB, ncB);
    Matrice result(nlA, ncB);

    if(ncA!=ncB || nlA!=nlB)
    {
        cout << "+ Impossible" << endl;
        return result;
    }
    else
    {
        double** m = new double*[nlA];

        for(int i=0; i<nlA ; i++)
        {
            m[i] = new double[ncB];
            for (int j=0; j<ncB; j++)
                m[i][j] = 0;
        }


        for(int i=0; i<nlA ; i++)
            for(int j=0; j<ncB ; j++)
                m[i][j]=(A.GetValue(i,j))+(B.GetValue(i,j));

        result.Set(m);
        return result;
    }
}

Matrice operator-(Matrice A, Matrice B)
{
    int nlA, ncA, nlB, ncB;
    A.GetSize(nlA, ncA);
    B.GetSize(nlB, ncB);
    Matrice result(nlA, ncB);

    if(ncA!=ncB || nlA!=nlB)
    {
        cout << "- Impossible" << endl;
        return result;
    }
    else
    {
        double** m = new double*[nlA];

        for(int i=0; i<nlA ; i++)
        {
            m[i] = new double[ncB];
            for (int j=0; j<ncB; j++)
                m[i][j] = 0;
        }

        for(int i=0; i<nlA ; i++)
            for(int j=0; j<ncB ; j++)
                m[i][j]=(A.GetValue(i,j))-(B.GetValue(i,j));

        result.Set(m);
        return result;
    }
}
