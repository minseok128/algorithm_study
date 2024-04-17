import random

SIZE = 100000
R_RANGE = (0, 10000)

with open("input.txt", "w") as file:
    file.write(f'{SIZE}\n')
    
    for _ in range(SIZE):
        number = random.randint(R_RANGE[0], R_RANGE[1])
        file.write(str(number) + " ")
        # file.write(str(_) + " ")
