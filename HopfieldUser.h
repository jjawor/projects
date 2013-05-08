#include "HopfieldNetwork.h"
class HopfieldUser{
      private :
      int historySize;
      double margin;
      HopfieldNetwork * hpGood;
      HopfieldNetwork * hpBad;
      double * toBinnaryPattern(int * source,int where,int size){
             double * pattern= new double [8*sizeof(int)*size];
             for(int i=0;i<size;i++){
                     for(int j=0;j<8*sizeof(int);j++){
                             pattern[i*8*sizeof(int)+j]=((source[where-4+i]<<j>>(8*sizeof(int)-1))*(-1)-0.5)*2;
                             //cout<<pattern[i*8*sizeof(int)+j]<<endl;
                             }     
                             
                             //cout<<source[where-4+i]<<endl;
                     }
             
              return pattern;  
             }
      int * toSource(double * pattern,int size){
      int *source=new int[size];
      for(int i=0;i<size;i++){
              source[i]=0;
              for(int j=0;j<8*sizeof(int);j++){
                      source[i]=source[i]*2;
                      source[i]+=(int)(pattern[i*8*sizeof(int)+j]/2+0.5);
                      }
                      }
              return source;
      }
      
      public:
      HopfieldUser(): margin(0.0625),historySize(5){
            hpGood=new HopfieldNetwork(historySize*8*sizeof(int),HopfieldNetwork::ACTIVATION_SIGNUM_HOPFIELD);
             hpBad=new HopfieldNetwork(historySize*8*sizeof(int),HopfieldNetwork::ACTIVATION_SIGNUM_HOPFIELD);
            
           //margin=0.0625;
           //historySize=5;
                     }       
      void teach(double * vect, int count){
           int maxPatterns=100;
           int goodCount=0;
           int badCount=0;
           double * (goodPatterns [maxPatterns]);
           double * (badPatterns [maxPatterns]);
           //points2 -> difrence beetwen two next points
              double  points2 [count-1];
              for(int i=1;i<count;i++)
              points2[i-1]=vect[i]-vect[i-1];
          //points2W -> relative diffrence beetwen who next points
    double point2W[count-1];
    for(int i=0;i<count-1;i++)point2W[i]=points2[i]/vect[i];
          //inPoint -> relative diffrence in int scale
    int inPoint[count -1];
    double max=vect[0];
    double min=vect[0];
    for(int i=1;i<count;i++){
            if(vect[i]>max)max=vect[i];
            else if(vect[i]<min)min=vect[i];
            }
    for(int i=0;i<count -1;i++)inPoint[i]=(int)((vect[i]-min)/(max-min)*(INT_MAX));
           //create teching patterns
           //cout<<min<<" "<<max<<endl;
           //for(int i=0;i<count-1;i++)cout<<vect[i]<<" "<<inPoint[i]<<endl;
    for(int i=4;i<count -1;i++)if(point2W[i]>margin){//cout<<"positive:"<<" point:"<<vect[i]<<"future point:"<<vect[i+1]<<"point diffrence]"<<points2[i]<<"point relative diffrence"<<point2W[i]<<" "<<i<<endl;
                        for(int k=i;k<i+5;k++)cout<<inPoint[k]<<" ";cout<<endl;
                        for(int k=i;k<i+5;k++)cout<<(inPoint[k]^INT_MAX)<<" ";cout<<endl;
                           goodPatterns[goodCount++]=toBinnaryPattern(inPoint,i,historySize);
                           }
                           else if(point2W[i]<-margin){//cout<<"negative:"<<" point:"<<vect[i]<<"future point:"<<vect[i+1]<<"point diffrence]"<<points2[i]<<"point relative diffrence"<<point2W[i]<<" "<<i<<endl;
                           badPatterns[badCount++]=toBinnaryPattern(inPoint,i,historySize);
                             }
    //teach networks
    cout<<goodCount<<" "<<badCount<<endl;
    hpGood->teach(goodPatterns,goodCount);
    hpBad->teach(badPatterns,badCount);
    //create database->crate map i c
             //int * pattern:double effecity
    
}
      int * test(double * vect,int count){
           //inPoint -> relative diffrence in int scale
    int inPoint[count -1];
    double max=vect[0];
    double min=vect[0];
    for(int i=1;i<count -1;i++){
            if(vect[i]>max)max=vect[i];
            else if(vect[i]<min)min=vect[i];
            }
    for(int i=0;i<count -1;i++)inPoint[i]=(int)((vect[i]-min)/(max-min)*(INT_MAX));
    //cout<<max<<" "<<min<<endl;
           //for(int i=0;i<count-1;i++)cout<<inPoint[i]<<endl;
          double *pat;
          double effent=100;
          int status=-1;
          for(int i=4;i<count-1;i++)
          {
             pat=toBinnaryPattern(inPoint,i,historySize);
             HopfieldResult* hr=hpGood->recognize(pat);
             HopfieldResult* hr2=hpBad->recognize(pat);
             /*if(i<12){
                      int * sss=toSource(hr->out,5);
             for(int k=0;k<5;k++)cout<<sss[k]<<" ";
             cout<<endl;}*/
             cout<<hr->iteration<<" "<<hr2->iteration<<" "<<((vect[i+1]-vect[i])/vect[i])<<endl; 
             if((hr2->iteration)<100)status=-1;
             else if((hr->iteration)<100)status=1;
             effent=(status==1?effent=effent*(vect[i+1]/vect[i]):effent);
             cout<<effent<<" "<<100*vect[i+1]/vect[4]<<endl;
             
             //if(i%20==0)system("pause");   
             //you can print out vector
          }
              //MatrixUtils::printVector(pat,32*5);
      }
};

