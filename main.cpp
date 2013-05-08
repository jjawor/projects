#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "HopfieldNetwork.h"
#include "MatrixUtils.h"
#include "HopfieldUser.h"
using namespace std;

double getDouble(char * c){
       int it=0;
       int tt=0;
       while(c[it]!=0){
                       if(c[it++]==',')tt++;
                       if(tt==5)break;
                       }
       double result=0.0;
       while(c[it]<='9'&&c[it]>='0'){
                       result=result*10;
                       
                       result+=c[it++]-'0';
                       }
       it++;//
       double result_rest=0.0;
       int rest=0;
       while(c[it]<='9'&&c[it]>='0'){
           result_rest=result_rest*10;
           result_rest+=c[it++]-'0';
           rest++;
                                   }
       return result+result_rest/pow(10.0,rest);
       }

class Stocks{
      public:
      double test(vector <double> test,int * decision){
             }
};       

int main(int argc, char *argv[])
{
    
    HopfieldNetwork h(5,HopfieldNetwork::ACTIVATION_SIGNUM_HOPFIELD);
    double * (patterns [5]);
    double pattern []={1,1,1,1,1};
    double pattern2 []={-1,-1,-1,-1,-1};
    patterns[0]=pattern;
    patterns[1]=pattern2;
    h.print();
    h.teach(patterns,1);
    cout<<endl;
    h.print();
    //double weights []={-50,-50,-50,-50,-50};h.setWeights(weights);
    double probe []={-1,1,-1,-1,1};
    HopfieldResult * result=h.recognize(probe);
    cout<<"iteration:"<<result->iteration<<endl;
    MatrixUtils::printVector(result->out,5);
    
    ifstream ifs ( "mstall/ASSECOPOL.mst" , ifstream::in );
    char buff[256];
    //for(int i=0;i<30;i++)
    int inputSize=3722;
    int tPortion=2500;
    double v [inputSize];
    int ccx=0;
    while (ifs.good())
    {
          ifs.getline(buff,256);
          v[ccx++]=getDouble(buff);
           }
    HopfieldUser hu;
    //cout<<(7<<27>>31);
    hu.teach(v+1,tPortion);
    hu.test(v+tPortion+1,inputSize-tPortion-1);
    /*int ccc=0;
    double points[3722];
    double points2[3721];
    ccc++;
    if(ifs.good()){ifs.getline(buff,256);
                points[ccc]=getDouble(buff);}
    while (ifs.good())
    {
          ccc++;
          ifs.getline(buff,256);
          points[ccc]=getDouble(buff);
          points2[ccc-1]=points[ccc]-points[ccc-1];
          //cout<<buff<<" "<<getDouble(buff)<<endl;
          }
    double point2W[3721];
    for(int i=0;i<3721;i++)point2W[i]=points2[i]/points[i];
    int inPoint[3721];
    double max=points[0];
    double min=points[0];
    for(int i=1;i<3721;i++){
            if(points[1]>max)max=points[i];
            else if(points[i]<min)min=points[i];
            }
    for(int i=0;i<3721;i++)inPoint[i]=(int)((points[i]-min)/(max-min)*INT_MAX);
              cout<<ccc;
    double margin=0.0625;
    for(int i=0;i<3721;i++)if(point2W[i]>margin)cout<<"positive:"<<" point:"<<points[i]<<"future point:"<<points[i+1]<<"point diffrence]"<<points2[i]<<"point relative diffrence"<<point2W[i]<<" "<<i<<endl;
                           else if(point2W[i]<-margin)cout<<"negative:"<<" point:"<<points[i]<<"future point:"<<points[i+1]<<"point diffrence]"<<points2[i]<<"point relative diffrence"<<point2W[i]<<" "<<i<<endl;
     */
     
     //czego szukamy?
     //wzrocow spwadku || wzorcow wzrostu
     //przyjmijmy: history=5
     //wzorzec wzrostu=>nastapi wzrost
     //wzorzec spadku=>nastapi spadek
     //get 1'st derivateive =>wzrost | dla kazdego punktu
   //  punkt+h  - punkt
     //get diffrence between 2h step |dla kazdego punktu
   //  punkt+2h - punkt
     //wzorzec: 5 punktow, nastepnie 6-5, oraz 7-5
     
     //wysukojemy roznice powyzej %
     //===>mzoemu wyszukac rozniece 7-5 powyzej %
    
    //interface:
    //->podaj dane uczace!
    //->podaj dane testowe
    //->wez wyniki jak sie prawdz dla danych testowych
    
    //dane uczace: vector<double>
    //dane testowe: vector<double>
    
    //wzorce zpamietujemy w bazie danych 
    //:wzorzec:wzrost
    //wzorcami karmimy siec hamiltona
    //mozemy stworzyc dwie cieci: dobra i zla
    ifs.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
