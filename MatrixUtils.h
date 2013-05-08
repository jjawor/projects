#include <cstdlib>
#include <iostream>
using namespace std;
class MatrixUtils{
      public:
      static double * substractVectors(double * vector,double * vector2,int size){
             double * result=new double[size];
             for(int i=0;i<size;i++)
             result[i]=vector[i]-vector2[i];
             return result;
      }
      static double * matrixTimesVector(double * matrix,double * vector,int size){
             double * result=new double[size];
             for(int i=0;i<size;i++){
             result[i]=0;
             for(int j=0;j<size;j++)
             result[i]+=matrix[i*size+j]*vector[j];
             }
             return result;
      }
      static double * matrixTimesVector(double * matrix,double * vector,double * result,int size){
             for(int i=0;i<size;i++){
             result[i]=0;
             for(int j=0;j<size;j++)
             result[i]+=matrix[i*size+j]*vector[j];
             }
             
           //  cout<<"times"<<result[0]<<" "<<result[1]<<endl;
             return result;
      }
      //nx1 X 1xn -> nxn
      static double * vectorTimesTVector(double *vector,double * vector2,int size){
             double * result=new double[size*size];
             for(int i=0;i<size;i++){
             for(int j=0;j<size;j++)
             result[i*size+j]=vector[i]*vector2[j];
             }
             return result;
      }
      //1xn X nx1 -> 1x1
      static double tVectorTimesVector(double *vector,double * vector2,int size){
             double result=0;
             for(int i=0;i<size;i++){
             result+=vector[i]*vector2[i];
             }
             return result;
      }
      static double * addMatrixes(double *matrix,double * matrix2,int size){
             double * result=new double[size*size];
             for(int i=0;i<size;i++){
             for(int j=0;j<size;j++)
             result[i*size+j]=matrix[i*size+j]+matrix2[i*size+j];
             }
             return result;
      }
      static double * matrixTimesConstant(double * matrix,double constant,int size){
             double * result=new double[size*size];
             for(int i=0;i<size;i++){
             for(int j=0;j<size;j++)
             result[i*size+j]=matrix[i*size+j]*constant;
             }
             return result;
      }
      static double * lazyAddMatrixes(double *matrix,double * matrix2,int size){
             for(int i=0;i<size;i++){
             for(int j=0;j<size;j++)
             matrix[i*size+j]=matrix[i*size+j]+matrix2[i*size+j];
             }
             return matrix;
      }
      static double * lazyMatrixTimesConstant(double * matrix,double constant,int size){
             for(int i=0;i<size;i++){
             for(int j=0;j<size;j++)
             matrix[i*size+j]=matrix[i*size+j]*constant;
             }
             return matrix;
      }  
      static double * clearDiagonal(double * matrix,int size){
             for(int i=0;i<size;i++){
             matrix[i*size+i]=0;
             }
             return matrix;
      }    
      static void printVector(double * W,int size){
                 for(int j=0;j<size;j++)
                         cout<<W[j]<<" ";
                         cout<<endl;
                 }    
      static void printMatrix(double * W,int size){
                 for(int i=0;i<size;i++){
                 for(int j=0;j<size;j++)
                         cout<<W[i+j*size]<<" ";
                         cout<<endl;
                         }
                 }  
      static int areEqual(double * vector,double * vector2,int size){
             for(int i=0;i<size;i++)
             if(vector[i]!=vector2[i])return 0;
             return 1;
             }
      };
