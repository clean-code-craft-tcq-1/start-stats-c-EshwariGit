#ifndef STATS_H_
#define STATS_H_    /*Header Protection : code added by EshwariGit*/

struct Stats compute_statistics(const float* numberset, int setlength);

struct Stats
{
    float average,min,max;
};              /*Missing Declaration of public struct added*/

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;

/*code added by EshwariGit*/
extern void emailAlerter(void);
extern void ledAlerter(void);

#endif
