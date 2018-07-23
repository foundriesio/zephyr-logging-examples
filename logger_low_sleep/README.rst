Logger Process Sleep Shortening
###############################

This example logs the same messages as logger_basics, but reduces the
processing thread sleep time to show how to force messages to print
more quickly.

This increases logging responsiveness at the cost of potentially
wasted cycles and extra scheduling overhead due to waking up the
processing thread more often.
