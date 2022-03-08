import random

min_range = 0
max_range = 100
size = 10
ran_num = random.sample(range(min_range, max_range), size)
ran_num_str = str(ran_num).replace(", ", " ")
sort_num = sorted(ran_num)
sort_num_str = str(sort_num).replace(", ", " ")
with open("test_" + str(size) + ".txt", 'w') as f:
    f.write(ran_num_str[1:-1])
with open("test_" + str(size) + "_sort.txt", 'w') as f:
    f.write(sort_num_str[1:-1])
