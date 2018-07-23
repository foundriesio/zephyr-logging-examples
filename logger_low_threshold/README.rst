Logger Process Threshold Lowering
#################################

This example logs the same messages as logger_basics, but reduces the
processing threshold to 2 to show how to force messages to print more
quickly.

This increases responsiveness, at the likely cost of extra scheduling
overhead due to waking up the processing thread more often.
