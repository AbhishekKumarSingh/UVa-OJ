#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

string prd(const double x, const int decdigit) {
    stringstream ss;
    ss << fixed;
    ss.precision(decdigit);
    ss << x;
    return ss.str();
}

int main()
{
    int nstudent, tstudent, i;
    double avg, sum, psum, nsum, exchange;
    while((cin>>nstudent) && nstudent != 0) {
        vector<double> s_exp(nstudent);
        tstudent = nstudent;
        i = 0; sum = 0; psum = 0; nsum = 0;
        while(tstudent) {
            cin >> s_exp[i];
            sum = sum + s_exp[i++];
            //sum = get_2prec_float(sum);
            tstudent--;
        }

        avg = sum/nstudent;

        for (int i = 0; i < s_exp.size(); i++) {
            if (avg-s_exp[i] > 0) {
                nsum = nsum+(floor((avg-s_exp[i])*100)/100);
            }

            if (avg-s_exp[i] < 0) {
                psum = psum + (floor((s_exp[i]-avg)*100)/100);
            }
        }

        exchange = (nsum > psum)? nsum:psum;
        //printf("%f %f\n",nsum, psum);
        cout << "$" << prd(exchange, 2)<<"\n";
    }

    return 0;
}
