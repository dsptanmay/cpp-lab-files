#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ResistancePair{
    protected:
        float r1, r2;
    public:
        virtual float compute()=0;
};

class SeriesResistancePair: public ResistancePair{
    public:
        SeriesResistancePair(){
            cout << "Enter the value of first and second resistances: " << endl;
            cin >> r1 >> r2;
        }

        float compute(){
            return r1+r2;
        }
};

class ParallelResistancePair: public ResistancePair{
    public:
        ParallelResistancePair(){
            cout << "Enter the value of the first and second resistances: " << endl;
            cin >> r1 >> r2;
        }
        float compute(){
            float res = 1.0/r1 + 1.0/r2;
            return res;
        }
};


int main(){
    SeriesResistancePair sp;
    float spr = sp.compute();
    cout << "Combined Resistance of Series Resistances = " << spr << endl;

    ParallelResistancePair pr[4];

    float psum = 0;
    for(int i=0;i<4;i++){
        psum += 1.0/pr[i].compute();
    }
    cout << "Combined Resistance of 8 Parallel Resistances = " << psum << endl;
    return 0;
}
