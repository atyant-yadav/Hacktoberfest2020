def strToList(str1):
	list1 = str1.split(" ")
	list1 = [int(x) for x in list1]
	return list1

def compareList(list1, list2):
	for x, y in zip(list1, list2):
		if(x > y):
			return -1
	return 1 
	
def listSum(list1, list2):
	list3 = [x + y for x, y in zip(list1, list2)]
	return list3

def listDiff(list1, list2):
	list3 = [x - y for x, y in zip(list1, list2)]
	return list3			

def addProcess(all):
	available = all[1]
	tot_res = all[0]
	available_temp = available
	
	proc_name = input("enter name of the process:")
	
	proc_alloc = input("enter the res allocated for this new process:")
	proc_alloc = strToList(proc_alloc)
	if(compareList(proc_alloc, available_temp) == -1):
		print("cannot allocate space more than the available resources")
		return all
		
	proc_req = input("enter res further req by proc:")
	proc_req = strToList(proc_req)
	if(compareList(listSum(proc_req, proc_alloc), tot_res) == -1):
		print("cannot allocate space more than the tot resources")
		return all
	tot_proc = listSum(proc_alloc, proc_req)
	cur_proc = [proc_name, proc_alloc, proc_req, tot_proc]
	process.append(cur_proc)
	available = listDiff(available, proc_alloc)
	
	all = (all[0], available, all[2], all[3])
	return all
	
def checkSafeState(all):
	available_temp = all[1][:]
	process_temp = all[2][:]
	safe_state_order = []	
	count = 1
	while(count):
		count = 0
		for i in process_temp:
			if(compareList(i[2], available_temp) == 1):
				count = 1	
				safe_state_order.append(i[0])
				available_temp = listSum(i[1], available_temp)
				process_temp.remove(i)

				
	if(process_temp != []):
		print("there is no safe state")
		return (all[0], all[1], all[2], [])
	else:
		print("Safe state exists")
		all = (all[0], all[1], all[2], safe_state_order)
		return all
	 
def display(order):
	for i in order:
		print(i + " => " , end = '')
	print()


no_of_res = int(input("enter the no of res:"))
tot_res = input("enter the tot no of instance of each resource:")
tot_res = strToList(tot_res)
available = input("enter the instance memory available")
available = strToList(available)
process = []
safe_state_order = []

all = (tot_res, available, process, safe_state_order)

while(1):
	print("1: add a process\n2: display safe state\n3:check if safe state exists\n4:exit")
	choice = int(input("enter your choice:"))

	if(choice == 1):
		all = addProcess(all)
	elif(choice == 2):
		display(all[3])
	elif(choice == 3):
		all = checkSafeState(all)
	elif(choice == 4):
		break
	else:
		print("invalid choice")
	#print(all)	
