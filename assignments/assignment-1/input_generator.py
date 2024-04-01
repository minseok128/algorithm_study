import random

SIZE = 10000
R_RANGE = (0, 500)

with open("input.txt", "w") as file:
    file.write(f'{SIZE}\n')
    
    for _ in range(SIZE):
        number = random.randint(R_RANGE[0], R_RANGE[1])
        file.write(str(number) + " ")
