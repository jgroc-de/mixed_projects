import os
import random
from src.ft_math import linear, ft_pow, ft_abs


def write_file(data: list, filename: str):
    file_path = './data/' + filename + '.csv'
    try:
        os.unlink(file_path)
    except FileNotFoundError:
        print('creating {}'.format(file_path))
    fd = open(file_path, 'x')
    fd.write('x,y\n')
    for item in data:
        fd.write('{},{}\n'.format(item[0], item[1]))


def write_answer_file(data: list, filename: str):
    file_path = './data/' + filename + '_answer.csv'
    try:
        os.unlink(file_path)
    except FileNotFoundError:
        print('creating {}'.format(file_path))
    fd = open(file_path, 'x')
    fd.write('a,b\n')
    fd.write('{},{}\n'.format(data[0], data[1]))


def generate_random_int(power: int):
    extremum = ft_pow(10, power)

    return random.randint(-extremum, extremum)


def generate_random_theta() -> list:
    a = generate_random_int(random.randint(1, 4))
    b = generate_random_int(random.randint(1, 4))

    return [a, b]


def generate_random_data(number_of_files: int) -> list:
    data_files = []

    for i in range(0, number_of_files):
        theta = generate_random_theta()
        data = []
        points = random.randint(2, 100)
        power = random.randint(1, 5)
        for _ in range(2, points):
            error = ft_abs(
                int(linear(ft_pow(random.randint(1, 10), power), theta)))
            x = generate_random_int(power)
            y = linear(x, theta) + random.randint(-error, error)
            data.append([x, int(y)])
        filename = 'test_' + str(i)
        write_file(data, filename)
        write_answer_file(theta, filename)
        # il faut normalizer theta
        data_files.append({'file': filename, 'result': theta})

    return data_files
