#ifndef MATRICE_H
#define MATRICE_H


class Matrice
{
    public:
        Matrice(int a, int b);
        virtual ~Matrice();
        double GetValue(int a,int b) { return matrix[a][b]; }
        void GetSize(int& a, int& b) { a=nl;b=nc; }
        void Set(double** val) { matrix = val; }
        void SetValue(int a, int b, double x) { matrix[a][b]=x; }


    protected:
    private:
        double** matrix;
        int nl;
        int nc;
};

Matrice operator*(Matrice A, Matrice B);
Matrice operator+(Matrice A, Matrice B);
Matrice operator-(Matrice A, Matrice B);

#endif // MATRICE_H
