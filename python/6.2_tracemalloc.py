import tracemalloc

# Start tracing memory allocations
tracemalloc.start()

# Code to profile
my_list = [i for i in range(100000)]

# Take a snapshot of memory usage
snapshot = tracemalloc.take_snapshot()

# Display top memory usage statistics
top_stats = snapshot.statistics('lineno')
for stat in top_stats[:100]:
    print(stat)