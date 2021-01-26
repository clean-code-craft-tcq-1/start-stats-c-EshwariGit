#include "stats.h"

/* fucntion to swap the contents of a varaible*/
void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

//    int stub_Val = 0;
    int p;
//    int count = 0;
    float minimum = numberset[0], maximum[0], add=0;
    float avg = 0 ;

    for(p=0; p< setlength; p++)
    {
        if(numberset[p] > maximum)
        {
            maximum = numberset[p];
        }
        if(numberset[p] < minimum)
        {
           minimum =  numberset[p];
        }
        add = add + numberset[p];
        avg = add/setlength;
    }

    s.average = avg;
    s.min = minimum;
    s.max = maximum;
    return s;

/*For, TEST_CASE("raises alerts when max is greater than threshold")*/

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void)
{
    emailAlertCallCount++;
}

void ledAlerter(void)
{
    ledAlertCallCount++;
}

void check_and_alert(const float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max>maxThreshold)
    {
        alerters[0]();
        alerters[1]();

    }
}
