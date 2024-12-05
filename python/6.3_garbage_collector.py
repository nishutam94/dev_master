import gc

# Manually trigger garbage collection
gc.collect()

# Get garbage collector statistics
stats = gc.get_stats()
print(stats)

# Disable automatic garbage collection
gc.disable()

# Enable automatic garbage collection
gc.enable()

# Check if automatic garbage collection is enabled
print(gc.isenabled())  # Output: True