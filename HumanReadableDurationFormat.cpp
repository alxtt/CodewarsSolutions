/*The function must accept a non-negative integer. If it is zero, it just returns "now". 
Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.
A year is 365 days and a day is 24 hours.
*/

#include <string>
#include <queue>
#include <cstdio>
#include <iostream>
#include <cstring>

std::string format_duration(int seconds) {
    if (!seconds) { return "now"; }
    char buf[256];
    std::string ans;
    std::queue<std::string> s;
    if (seconds > 365*24*60*60) {
        snprintf(buf, sizeof(buf), (seconds/(365*24*60*60) == 1 ? "%d year" : "%d years"), (seconds/(365*24*60*60)));
        s.push(buf);
        seconds %= 365*24*60*60;
    }
    if (seconds > 24*60*60) {
        snprintf(buf, sizeof(buf), (seconds/(24*60*60) == 1 ? "%d day" : "%d days"), (seconds/(24*60*60)));
        s.push(buf);
        seconds %= 24*60*60;
    }
    if (seconds > 60*60) {
        snprintf(buf, sizeof(buf), (seconds/(60*60) == 1 ? "%d hour" : "%d hours"), (seconds/(60*60)));
        s.push(buf);
        seconds %= 60*60;
    }
    if (seconds > 60) {
        snprintf(buf, sizeof(buf), ((seconds/60) == 1 ? "%d minute" : "%d minutes"), (seconds/60));
        s.push(buf);
        seconds %= 60;
    }
    if (seconds) {
        snprintf(buf, sizeof(buf), (seconds == 1 ? "%d second" : "%d seconds"), seconds);
        s.push(buf);
    }
    if (s.size() == 1) { return s.front(); }
    while (s.size() > 2) {
        ans += s.front();
        ans += ", ";
        s.pop();
    }
    ans += s.front() + " " + "and " + s.back();
    return ans;
}
