import sys;
import operator;

letters = {}

for x in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
	letters[x] = 0
	
num = int(input())

for i in range (0, num):
	for c in sys.stdin.readline().upper():
		if(c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"):
			letters[c]+=1;
			
lastAmount = -1
lastLetters = []

for x in sorted(letters.items(), key=operator.itemgetter(1), reverse=True):
	if(x[1] == 0):
		break
	if(x[1] < lastAmount):
		for y in sorted(lastLetters):
			print(y + " " + str(lastAmount));
		lastLetters = [];
		lastAmount = x[1]
	elif lastAmount < 0:
		lastAmount = x[1]
	
	lastLetters.append(x[0])
	
	
for y in sorted(lastLetters):
	print(y + " " + str(lastAmount));