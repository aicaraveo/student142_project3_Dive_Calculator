Dive calculator

Inputs for calculator:
 - No D limits calc:
	- depth (ft of salt water (fsw))
	- time @ depth (min)

 - Residual Nitrogen calculator for repetitive dives:
	- output from no/D limit calc 
	- surface interval 
	- depth (old or new)

 - Decompression stops calc:
	- time 


	
Calculations:
 - No/D limit calc:
	Take depth and time (min) and find repet group according to the chart. if the time is greater than the value on the chart it skips to the next square (see Repet Group chart).
	if the square contains a star (first 3 rows for depth), then that repet group will apply to any time longer than the previous square. if its beyond the 3 columns and rows then a decompression dive
	is necessary.
	
Outputs for calculator:
 - No D limits calc:
	- repetitive dive group (letter)
 - Residual Nitrogen calculator for repetitive dives:
	- additional compensation time
 - Decompression stops calculator:
	- what depth
	- how long for stop
