import time
start_time = time.time()

# M01

rounds = 0
sum = 0
start_time = time.time()
n = int(input("Number: "))
while rounds < n:
    sum = sum + 1
    rounds = rounds + 1
print("M01")
print(sum)
print("Run Time")
print("--- %s seconds ---" % (time.time() - start_time))

# M02
rounds = 0
sum = 0
start_time = time.time()
while rounds < n:
    sum = sum + 1
    rounds = rounds  + 2

print("M02")
print(sum)
print("Run Time")
print("--- %s seconds ---" % (time.time() - start_time))

# M03
round1s = 0
sum = 0
start_time = time.time()
while round1s < 1:
    round2s = 0
    while round2s < n:
        sum = sum + 1
        round2s = round2s + 1
    round1s = round1s + 1

print("M03")
print(sum)
print("Run Time")
print("--- %s seconds ---" % (time.time() - start_time))

# M04
round1s = 0
sum = 0
start_time = time.time()
while round1s < n:
    round2s = 0
    while round2s < n:
        sum = sum + 1
        round2s = round2s + 10
    
    round1s = 20

print("M04")
print(sum)
print("Run Time")
print("--- %s seconds ---" % (time.time() - start_time))

# M05
round1s = 0
sum = 0
start_time = time.time()
while round1s < n:
    sum = sum + 1
    round1s = round1s + 1
round2s = 0
while round2s < n:
    sum = sum + 1
    round2s = round2s + 1

print("M05")
print(sum)
print("Run Time")
print("--- %s seconds ---" % (time.time() - start_time))

# M06
round1s = 0
sum = 0
start_time = time.time()

while round1s < n:
    round2s = 0
    while round2s < n:
        sum = sum + 1
        round2s = round2s + 1
    round1s = round1s + 1

print("M06")
print(sum)
print("Run Time")
print("--- %s seconds ---" % (time.time() - start_time))



    