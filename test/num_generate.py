import random

min_range = 0
max_range = 100
size = 10
ran_num = str(random.sample(range(min_range, max_range), size)).replace(", ", " ")
with open("test_" + str(size) + ".txt", 'w') as f:
    f.write(ran_num[1:-1])
