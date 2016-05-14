#include <iostream>
#include "Matrice.h"

using namespace std;

Matrice::Matrice(int a, int b)
{
    //Mise a jour des variables internes à la matrice
    nl = a;
    nc = b;
	//Allocation dynamique de la matrice
	matrix = new double*[nl];
    matrix[0] = new double[nl*nc];
    for(int i=1; i<nl ; i++){
        matrix[i] = matrix[i-1] + nc;
    }
    for(int i=0; i<nl ; i++){
        for(int j=0; j<nc ; j++){
            matrix[i][j]=0;
        }
    }
}

Matrice::Matrice(const Matrice &M)
{
    //Mise a jour des variables internes à la matrice
    M.GetSize(nl,nc);

    if(this != &M){
        for(int i=0; i<nl; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
        //Allocation dynamique de la matrice
        matrix = new double*[nl];
        matrix[0] = new double[nl*nc];
        for(int i=1; i<nl ; i++){
            matrix[i] = matrix[i-1] + nc;
        }
        for(int i=0; i<nl ; i++){
            for(int j=0; j<nc ; j++){
                matrix[i][j]=M.GetValue(i,j);
            }
        }
    }
}

Matrice::Matrice()
{
    nl = 0;
    nc = 0;
}

Matrice& Matrice::operator=(const Matrice &B)
{
    if(this != &B){
        for(int i=0; i<nl; i++){
            delete[] matrix[i];
        }
    delete[] matrix;
    }


    B.GetSize(nl,nc);
    for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            matrix[i][j] = B.GetValue(i,j);
        }
    }

    return *this;
}

Matrice::~Matrice()
{
    /*/
    for(int i=0; i<nl; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    /*/
    //dtor
}

//Déclaration de l'opération * entre les matrices
Matrice operator*(const Matrice &A, const Matrice &B)
{
    int nlA, ncA, nlB, ncB;
    A.GetSize(nlA, ncA);
    B.GetSize(nlB, ncB);
    Matrice result(nlA, ncB);

    if(ncA!=nlB) // On ne peut pas multiplier n'importe quelles matrices
    {
        cout << "* Impossible" << endl;
        return result;
    }
    else
    {
        for(int i=0; i<nlA ; i++)
            for(int j=0; j<ncB ; j++)
                for(int k=0; k<ncA ; k++){
                    result.SetValue(i,j,A.GetValue(i,k)*B.GetValue(k,j));
                    }
        return result;
    }
}



Matrice operator+(const Matrice &A, const Matrice &B)
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


Matrice operator-(const Matrice &A, const Matrice &B)
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
