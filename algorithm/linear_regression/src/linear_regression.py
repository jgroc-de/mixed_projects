import matplotlib.pyplot as plt
import os
from src.data_formater import format_data, format_theta, normalize_data
from src.stats import get_average, get_range, get_extremum
from src.ft_gradient_descent import compute_theta


def first_element(data):
    return data[0]


def read_data(filename: str):
    data_file = open('./data/' + filename + '.csv', 'r')
    lines = data_file.readlines()
    legend = lines[0].split(',')
    del (lines[0])
    if len(lines) == 0:
        raise ValueError('No Value in file {}'.format(filename + '.csv'))
    split_lines = [items.split(',') for items in lines]
    data = [[int(item[0]), int((item[1]).rstrip())] for item in split_lines]
    data.sort(key=first_element)

    return [data, legend]


def write_theta(theta: list, filename: str):
    filename = './data/' + filename + '_prophecy.csv'
    try:
        thetas = open(filename, 'x')
    except FileExistsError:
        os.unlink(filename)
        thetas = open(filename, 'x')
    thetas.write('{},{}'.format(theta[0], theta[1] - theta[0]))


def plot_data(data: list, points_for_line: list, legend: list):
    if (legend != []):
        plt.xlabel(legend[0])
        plt.ylabel(legend[1])
    for item in data:
        plt.plot(item[0], item[1], '+k')
    plt.plot(points_for_line[0], points_for_line[1], 'o-r')
    plt.show()


def run(filename: str, verbose_mode: bool) -> list:
    if (filename == ''):
        data = [[0, 2], [1, 1], [2, -1]]
        legend = []
    else:
        out = read_data(filename)
        data = out[0]
        legend = out[1]
    data_extremum = get_extremum(data)
    average = get_average(data)
    data_range = get_range(data_extremum['max'], data_extremum['min'])
    if (data_range[0] == 0):
        print('data_range is 0 for file ' + filename)
        return []
    theta = compute_theta(normalize_data(data, data_range, average))
    real_theta = format_theta(theta, {'min': [0], 'max': [1]}, data_range, average)
    write_theta(real_theta[1], filename)
    points_for_line = format_theta(theta, data_extremum, data_range, average)
    if verbose_mode:
        plt.show()
        plot_data(data, points_for_line, legend)

    return [real_theta[1][0], real_theta[1][1] - real_theta[1][0]]
