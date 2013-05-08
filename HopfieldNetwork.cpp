#include <cstdlib>
#include <iostream>
#include "MatrixUtils.h"
#include "HopfieldNetwork.h"
using namespace std;

            HopfieldNetwork::HopfieldNetwork(int size,int activationFunction): size(size),activationF(activationFunction)
            {
            W=new double[size*size];
            memset(W,0,size*size*sizeof(double));
            weights=new double[size];
            memset(weights,0,size*sizeof(double));
            }
            void HopfieldNetwork::teach(double ** patterns,int number){
                 for(int i=0;i<number;i++){
                         double * vector=MatrixUtils::matrixTimesVector(W,patterns[i],size);
                         double * vector2=MatrixUtils::substractVectors(vector,patterns[i],size);
                         double * matrix=MatrixUtils::vectorTimesTVector(vector2,vector2,size);
                         double dry=MatrixUtils::tVectorTimesVector(patterns[i],patterns[i],size)-MatrixUtils::tVectorTimesVector(patterns[i],vector,size);
                         MatrixUtils::lazyMatrixTimesConstant(matrix,1/dry,size);//matrix=
                         MatrixUtils::lazyAddMatrixes(W,matrix,size);//W=
                         MatrixUtils::clearDiagonal(W,size);//W=
                         delete[](vector);
                         delete[](vector2);
                         delete[](matrix);
                          //for(int w=0;w<14;w++)cout<<W[w]<<" ";cout<<endl;
                           //system("pause");
                          
                         }
                         //cout<<"end teach"<<endl;
                 }
            HopfieldResult * HopfieldNetwork::recognize(double * in){
                           double * dIN=new double[size];
                           double * dOUT=new double[size];
                           memcpy (dIN, in, size*sizeof(double)) ;
                           int i=0;
                           for(;i<MAX_EPOCHS;i++){
                                                   //cout<<i<<endl;
                           MatrixUtils::matrixTimesVector(W,dIN,dOUT,size);//oblicznie sumy 
                           //MatrixUtils::printVector(dOUT,32);
                           //MatrixUtils::printVector(dIN,32);
                           //for(int w=0;w<14;w++)cout<<W[w]<<" ";cout<<endl;
                           //cout<<size<<endl;
                           //system("pause");
                           activationFunction(dIN,dOUT);//funkcja aktyacji
                           if(MatrixUtils::areEqual(dIN,dOUT,size))break;
                           memcpy (dIN, dOUT, size*sizeof(double)) ;
                           }
                           delete [](dIN);
                           return new HopfieldResult(dOUT,i);
                 }
            void HopfieldNetwork::print(){
                 for(int i=0;i<size;i++){
                 for(int j=0;j<size;j++)
                         cout<<W[i+j*size]<<" ";
                         cout<<endl;
                         }
                 }
            void HopfieldNetwork::setWeights(double * weights){
                 delete [](this->weights);
                 this->weights=weights;
                 }
