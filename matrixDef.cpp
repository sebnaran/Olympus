#ifndef GENMAT_H
#define GENMAT_H
#include <set>
#include <iostream>
#include <map>
#include <tuple>

namespace linAlg
{

//This is the more general class of matrices. Meant to be used as a virtual class at least initially
class Matrix
{
    public:

    /*! This constructor turns a hash-map to a matrix
    \param row number of rows in the matrix
    \param col number of columns in the matrix*/
    Matrix(const int a, const int b,std::map<std::tuple<int,int>,float> entriesIn): row(a),col(b),entries(entriesIn)
    {};

    Matrix(){};
    /*! 
    \param row number of rows in the matrix
    \param col number of columns in the matrix*/
    void makeMatrix(const int & a, const int & b,std::map<std::tuple<int,int>,float> & entriesIn)
    {
        row = a; col = b; entries = entriesIn;
    }

    /*! accessor to one of the entries
    \param i first entry of the index
    \param j second entry of the index*/
    float getEntry(const int i, const int j)
    {
        std::tuple<int,int> ij = std::make_tuple(i,j);
        float ans = entries[ij];
        return(ans);
    }
    
    //Method to print matrix
    virtual void printMatrix()
    {
        std::cout<<"The printed method has not been implemented for this type of matrix"<<std::endl;
    }
    private:
    // bool isAcceptableMap() // This function would check if the entries map is a possible matrix
    
    int row,col; //number of rows and columns
    std::map<std::tuple<int,int>,float> entries; //a map to the entries of the matrix
};

//This is a specialized class for 2x2 matrices
class Matrix2x2: public Matrix
{
    public:
    Matrix2x2(const float a,const float b,const float c, const float d){
        std::tuple<int,int> i00,i10,i01,i11;
        i00 = std::make_tuple(0,0);
        i10 = std::make_tuple(1,0);
        i01 = std::make_tuple(0,1);
        i11 = std::make_tuple(1,1);

        std::map<std::tuple<int,int>, float> entries {{i00, a},{i10,b},{i01,c},{i11,d} };
        makeMatrix(2,2,entries);
    };

    //method to print matrix
    void printMatrix()
    {
        float a = getEntry(0,0);
        float b = getEntry(1,0);
        float c = getEntry(0,1);
        float d = getEntry(1,1);
        std::cout<<"|"<<a<<","<<b<<"|"<<std::endl;
        std::cout<<"|"<<c<<","<<d<<"|"<<std::endl;
    };

    private:
};
}

int main()
{   
    linAlg::Matrix2x2 A(1.,2.,3.,4.);
    //float a = A.getEntry(0,0);
    //float b = A.getEntry(1,0);
    //float c = A.getEntry(0,1);
    //std::cout<<b<<c<<std::endl;
    
    A.printMatrix();

}

#endif