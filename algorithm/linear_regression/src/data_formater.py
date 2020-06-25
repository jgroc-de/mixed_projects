from src.stats import normalize, denormalize


def format_data(coord):
    x = [int(item[0]) for item in coord]
    y = [int(item[1]) for item in coord]

    return [x, y, 'x']


def format_theta(theta, extremum, data_range, average):
    return [
        [extremum['min'][0], extremum['max'][0]],
        [
            denormalize(extremum['min'][0], theta, data_range, average),
            denormalize(extremum['max'][0], theta, data_range, average)
        ],
        '-'
    ]


def normalize_data(data, data_range, average):
    return [
        [
            normalize(line[0], data_range[0], average[0]),
            normalize(line[1], data_range[1], average[1])
        ] for line in data
    ]
