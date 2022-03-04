#include <iostream>

using namespace std;



int cmmdc(int a, int b)
{
    int r;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;

    }
    return b;
}

int cmmmc(int a, int b){
    return a*b/cmmdc(a,b);

}

struct fractie{
    int numitor;
    int numarator;

};

double value(fractie fr){
    return 1.0*fr.numarator/fr.numitor;
}

fractie simpl(fractie fr){
    fractie simple;
    int div = cmmdc(fr.numarator,fr.numitor);
    simple.numarator = fr.numarator/div;
    simple.numitor = fr.numitor/div;
    return simple;

}


int frcmp(fractie fr1, fractie fr2){
    fractie sr1 = simpl(fr1);
    fractie sr2 = simpl(fr2);


    if(sr1.numarator==sr2.numarator && sr1.numitor== sr1.numitor)
        return 0;
    return 1;

}


void afisare(fractie fr){
    cout<<fr.numarator<<"/"<<fr.numitor<<" ";
}

bool inVector(fractie vr[1000], int c, fractie fr){
    bool ok = true;
    for (int i =1;i<=c;i++){
        if(frcmp(vr[i], fr) == 0){
            ok = false;
            return ok;
        }
    }
    return ok;

}
int main()
{


   int n;
   cin>>n;
   int v[101];
   for(int i=1;i<=n;i++)
        cin>>v[i];

    fractie vr[1000];
    fractie fr;
    int c=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            fr.numarator=v[i];
            fr.numitor=v[j];
            if(inVector(vr, c, fr)){
                vr[++c]=fr;
            }

            fr.numarator=v[j];
            fr.numitor=v[i];
            if(inVector(vr, c, fr)){
                vr[++c]=fr;
            }
        }
    }

    for(int i=1;i<=c;i++)
        afisare(vr[i]);

}
