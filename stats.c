#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {

    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

    int stub_Val = 0;
    int p,q,r;
    int count = 0;

    float add = 0.0;
    float usenum[setlength-1];
/*-------------To calculate Average-------------------*/
    for(count; count<setlength;count++)
    {
        usenum[count] = numberset[count];  // Inputs from Testcase count.
    }

    for(r=0;r<setlength;r++)
    {
        add = add + usenum[r]; // TC: 01 : Value calculation for average
    }

    s.average = (float) add/ setlength;
/* fucntion to swap the contents of a varaible*/
    void swap(float *xp, float *yp)
    {
        float temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

/*-------------To calculate Min and Max-------------------*/

    for (p=0;p<setlength-1;p++)
        {
        stub_Val=p;
            for (q=p+1;q<setlength;q++)
            {
                if (usenum[q]<usenum[stub_Val])
                {
                    stub_Val=q;
                }
            }
        }
    swap(&usenum[stub_Val], &usenum[p]);   // Pass by address.
s.max = usenum[setlength-1];
s.min = usenum[0];

    return s;   /* added Missing return Value*/
}


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void check_and_alert(const float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max>maxThreshold)
    {
      alerters();
    }
}



