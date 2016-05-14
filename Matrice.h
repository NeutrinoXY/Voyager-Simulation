#ifndef MATRICE_H
#define MATRICE_H


class Matrice
{
    public:
        Matrice(int a, int b);
        Matrice();
        Matrice(const Matrice &M);
        Matrice& operator=(const Matrice &B);
        virtual ~Matrice();
        double GetValue(int a,int b) const {return matrix[a][b];}
        void GetSize(int& a, int& b) const {a=nl;b=nc;}
        void Set(double** val) {matrix = val;}
        void SetValue(int a, int b, double x) {matrix[a][b]=x;}



    protected:
    private:
        double** matrix;
        int nl;
        int nc;
};

Matrice operator*(const Matrice &A, const Matrice &B);
Matrice operator+(const Matrice &A, const Matrice &B);
Matrice operator-(const Matrice &A, const Matrice &B);

#endif // MATRICE_H
