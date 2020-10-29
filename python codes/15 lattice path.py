def lattice_path(x, y):
	total_path= 1
	right = 1
	down = 1
	
	#factorial of total path
	for u in range(1, x+y+1):
		total_path *= u
	
	#factorial of path to right
	for _ in range(1,x+1):
		right *= _


	#factorial down
	for x in range(1, y+1):
		down *=x
		
	
	#total path
	print(f"The lattice path to be taken for a {x} by {y} grids is {int(total_path/(right*down))}")

lattice_path(20,20)
	