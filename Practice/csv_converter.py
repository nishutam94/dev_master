import pandas as pd
import os
files = [f for f in os.listdir('.') if os.path.isfile(f)]
for f in files:
	if f.endswith(".csv"):
           df = pd.read_csv(f,delimiter=';')
           df.to_csv(f)
           
	
	