import random
import string

TARGET = input("Enter the string to evolve to: ")
GENES = string.ascii_letters + import random
import string

TARGET = input("Enter the target for evolution: ")
GENES = string.ascii_letters + string.digits + string.punctuation + " "
POPULATION_SIZE = 100
MUTATION_RATE = 0.05

def random_chars():
    return random.choice(GENES)

def create_individual():
    return [random_chars() for _ in range(len(TARGET))]

def calculate_fitness(individual):
    return sum(1 for expected, actual in zip(TARGET, individual) if expected == actual)

def mutate(individual):
    for i in range(len(individual)):
        if random.random() < MUTATION_RATE:
            individual[i] = random_chars()

    return individual

def crossover(p1, p2):
    if len(TARGET) <= 1:
            return p1[:]
    midpoint = random.randint(0, len(TARGET) - 1)
    return p1[:midpoint] + p2[midpoint:]

population = [create_individual() for _ in range(POPULATION_SIZE)]
generation = 1

while True:
    population = sorted(population, key=calculate_fitness, reverse=True)
    best_match = "".join(population[0])
    best_score = calculate_fitness(population[0])

    print(f" Gen {generation:03d} | Fitness: {best_score:02d}/{len(TARGET)}| Output: {best_match}")

    if best_match == TARGET:
        break

    next_gen = population[:20]

    while len(next_gen) < POPULATION_SIZE:
        parent1 = random.choice(population[:50])
        parent2 = random.choice(population[:50])

        child = mutate(crossover(parent1, parent2))

        next_gen.append(child)

    population = next_gen
    generation += 1