#ifndef _Hopfield_Result
#define _Hopfield_Result

class HopfieldResult{
      public:
             HopfieldResult(double * out,int iteration): out(out),iteration(iteration){}
      //private:
      double * out;
      int iteration;
      };
class HopfieldNetwork{
      public:
            HopfieldNetwork(int size,int activationFunction);
            void teach(double ** patterns,int number);
            HopfieldResult * recognize(double * in);
            void print();
            void setWeights(double * weights);
      static const int MAX_EPOCHS=100;
      static const int ACTIVATION_SIGNUM=0;
      static const int ACTIVATION_SIGNUM_HOPFIELD=1;
      static const int ACTIVATION_SATURATED_LINEAR=2;
      private:
      int activationF;
      double * W; 
      double * weights;//weights //set as 0's
      int size;
      void activationFunction(double *IN,double *OUT){
           switch(activationF){
                                      case 0://signum.
                                          for(int j=0;j<size;j++)OUT[j]=(OUT[j]-weights[j]>0?1:-1); 
                                          break;
                                      case 1://sign Hopfield
                                           for(int j=0;j<size;j++){if(OUT[j]-weights[j]==0)OUT[j]=IN[j];
                                                   else OUT[j]=(OUT[j]-weights[j]>0?1:-1);}
                                           break;
                                      case 2://saturated liear
                                           for(int j=0;j<size;j++){if(OUT[j]-weights[j]<1&&OUT[j]-weights[j]>-1);//out=out
                                                   else OUT[j]=(OUT[j]-weights[j]>0?1:-1);}
                                           break;
                                      }
           }
            };
#endif
