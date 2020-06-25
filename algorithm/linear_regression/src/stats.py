from src.ft_math import linear


def get_average(data: list):
    average = [0, 0]
    for line in data:
        average[0] += line[0]
        average[1] += line[1]
    average[0] /= len(data)
    average[1] /= len(data)

    return average


def get_range(data_max: list, data_min: list) -> list:
    return [abs(data_max[0] - data_min[0]), abs(data_max[1] - data_min[1])]


def get_extremum(data: list):
    data_max = [data[0][0], data[0][1]]
    data_min = [data[0][0], data[0][1]]
    for item in data:
        for i in range(0, 2):
            if (item[i] > data_max[i]):
                data_max[i] = item[i]
            if (item[i] < data_min[i]):
                data_min[i] = item[i]

    return {'max': data_max, 'min': data_min}


def normalize(item: float, data_range: float, avg: float) -> float:
    return (item - avg) / data_range


def denormalize(x: float, theta_normalized: list, data_range: list, average: list) -> float:
    x_normalized = normalize(x, data_range[0], average[0])
    result = linear(x_normalized, theta_normalized)

    return result * data_range[1] + average[1]
