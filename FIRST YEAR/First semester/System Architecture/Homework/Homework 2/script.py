from pwn import *
context.log_level = 'error'
context.timeout = 20
inputArray = [
	  ["15 2 6 0 0 10 0 3 0 0 12 0 0 0 0 3 0 0 1 0 5 0 0 0 0 13 0 0 0 8 0 0 11 0 0 2 0 0 10 0 0 0 9 0 0 0 7", 
	   "20 1 3 0 0 0 5 0 0 0 0 9 0 0 0 0 4 0 0 0 0 8 0 0 0 8 0 0 0 13 0 0 0 0 0 0 10 0 0 0 0 19 0 0 0 0 20 0 0 0 0 0 0 12 0 0 0 3 0 0 0 17", 
	   "30 1 3 0 0 0 2 0 0 0 0 4 0 0 5 0 0 0 0 0 0 14 0 0 0 8 0 0 0 0 0 0 9 0 0 29 0 0 17 0 0 0 0 0 17 0 0 0 0 0 28 0 0 0 0 19 0 0 0 4 0 0 26 0 0 0 0 0 0 14 0 0 0 0 18 0 0 0 0 15 0 0 0 0 0 8 0 0 30 0 0 2", 
	   "30 5 8 0 0 30 0 0 0 7 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 10 0 0 0 0 0 16 0 0 0 0 0 0 0 0 20 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 29 0 0 0 0 0 0 0 13 0 0 0 18 0 0 0 0 0 24 0 0 0 0 0 0 0 28 0 0 0 9"]
	]
outputArray = [
	  ["6 1 2 10 1 3 2 4 12 3 4 5 6 3 4 5 1 6 5 7 8 9 7 13 8 9 10 8 12 13 11 12 13 2 14 15 10 11 14 15 9 11 14 15 7", 
	   "3 1 2 1 5 1 2 3 2 9 4 5 4 5 4 6 7 6 7 8 6 7 9 8 9 8 10 13 10 11 12 11 12 11 10 13 14 13 14 19 14 15 16 15 20 15 16 17 16 17 18 12 18 19 18 3 20 19 20 17", 
	   "3 1 2 1 2 1 3 4 3 4 5 6 5 6 5 6 7 8 7 14 7 9 10 8 9 10 11 10 11 12 9 11 12 29 12 13 17 13 14 13 15 16 17 15 16 17 16 18 28 18 19 20 21 19 20 19 20 4 21 22 26 21 22 23 22 23 24 14 23 24 25 24 18 25 26 25 26 15 27 28 27 28 27 8 30 29 30 29 30 2", 
	   "8 1 2 30 3 4 5 7 1 2 6 4 5 7 3 1 2 4 5 6 3 7 8 9 11 6 12 13 10 8 9 11 12 13 16 10 14 11 12 15 16 10 14 20 17 15 16 18 14 19 17 15 20 18 21 19 17 22 20 29 21 19 23 22 24 25 21 13 23 22 24 18 25 28 23 26 27 24 29 28 30 26 27 25 29 28 30 26 27 9"]
	]
points = [
	  [30, 25, 20, 15]
]

executables = ["./cerinta1"]

estimatedGrade = 0

for taskIndex in range(len(executables)):
	findProcess = process(["find", executables[taskIndex]])
	findResult = findProcess.recv()
	findProcess.kill()
	
	if findResult.replace("\n", "").strip() != executables[taskIndex]:
		print "Executable %s not found!" % executables[taskIndex]
		continue 
		
	print "Task: %s" % executables[taskIndex]
		
	taskInputArray = inputArray[taskIndex]
	taskOutputArray = outputArray[taskIndex]
	taskPoints = points[taskIndex]
	
	for i in range(0, len(taskInputArray)):
		try:
			sh = process(executables[taskIndex])
			sh.sendline(taskInputArray[i])
			line = sh.recvline().replace("\n", "").strip()
			sh.kill()
			
			if line == taskOutputArray[i]:
				estimatedGrade += taskPoints[i]
				
				if taskIndex < 3:
					print "\tTest %d: OK (%dp)" % (i, taskPoints[i]) 
				
				if taskIndex == 3 and i % 2 == 0:
					print "\tTest %d: OK (%dp)" % (i, taskPoints[i]) 
					taskPoints[i + 1] = 0 # already scored
					
				if taskIndex == 3 and i % 2 == 1:
					if taskPoints[i] == 0:
						print "\tTest %d: already scored" % i
					else:
						print "\tTest %d: OK (%dp)" % (i, taskPoints[i])
			else:
				print "\tTest %d failed (0p)" % i 
				print "\t   Input: %s" % taskInputArray[i]
				print "\t   Your output: %s" % line 
				print "\t   Expected output: %s" % taskOutputArray[i]
			
			if taskIndex == 3 and i % 2 == 1:
				print "\t------------------"
		except:
			print "\tTest %d: exception! (0p)" % i
	print "\n"

print "Estimated grade %dp / 100" % (estimatedGrade + 10)
