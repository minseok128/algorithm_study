import random

SIZE = 300
R_RANGE = (0, 200)

with open("input.txt", "w") as file:
    file.write(f'{SIZE}\n')
    
    for _ in range(SIZE):
        number = random.randint(R_RANGE[0], R_RANGE[1])
        file.write(str(number) + " ")
