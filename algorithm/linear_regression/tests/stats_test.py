from src.stats import get_average, get_range, get_extremum, normalize, denormalize


def test():
    get_average_test = [
        [[[0, 0]], [0, 0]],
        [[[0, 0], [0, 0]], [0, 0]],
        [[[1, 1], [0, 0]], [0.5, 0.5]],
        [[[1, 1], [-1, -1]], [0, 0]],
        [[[200, 200], [-200, -200]], [0, 0]],
        [[[0, 0], [0, 0], [0, 0]], [0, 0]],
        [[[0, 0], [1, 1], [2, 2]], [1, 1]],
        [[[0, 0], [-1, -1], [1, 1]], [0, 0]],
        [[[0, 0], [4, 4], [1, 1]], [5 / 3, 5 / 3]],
    ]

    for item in get_average_test:
        result = get_average(item[0])
        if (result != item[1]):
            print(item, result)
            break

    get_range_test = [
        [[0, 0], [0, 0], [0, 0]],
        [[2, 2], [2, 2], [0, 0]],
        [[2, 2], [0, 0], [2, 2]],
        [[1000, 1000], [0, 0], [1000, 1000]],
        [[100, 100], [49, 49], [51, 51]],
        [[99.5, 99.5], [-1.5, -1.5], [101, 101]],
        [[-10, -10], [32, 32], [42, 42]],
        [[-10, -10], [-8, -8], [2, 2]],
        [[-11, -11], [-42, -42], [31, 31]],
    ]

    for item in get_range_test:
        result = get_range(item[0], item[1])
        if (result != item[2]):
            print(item, result)
            break

    get_extremum_test = [
        [[[1, 1]], [[1, 1], [1, 1]]],
        [[[0, 0], [1, 1]], [[1, 1], [0, 0]]],
        [[[0, 0], [0, 0]], [[0, 0], [0, 0]]],
        [[[1, 1], [2000, 2000], [-100, -100]], [[2000, 2000], [-100, -100]]],
        [[[2000.5, 2000.5], [2000, 2000], [-100, -100]],
            [[2000.5, 2000.5], [-100, -100]]],
    ]

    for item in get_extremum_test:
        result = get_extremum(item[0])
        if (result != {'max': item[1][0], 'min': item[1][1]}):
            print(item, result)
            break

    normalize_test = [
        [1, 0, 1, 0],
        [1, 1, 1, 0],
        [2, 1, 1, 1],
        [0, 1, 1, -1],
        [0, 2, 1, -0.5],
        [3, 2, 1, 1],
        [1.5, 1, 1, 0.5],
        [1000.2, 1, 0.2, 1000],

    ]

    for item in normalize_test:
        try:
            result = normalize(item[0], item[1], item[2])
            if (result != item[3]):
                print(item, result)
                break
        except ZeroDivisionError as error:
            print(error)

    # x: float, theta_normalized: list, data_range: list, average: list
    denormalize_test = [
        [1, [1, 1], [1, 2], [1, 1], 3],
    ]

    for item in denormalize_test:
        result = denormalize(item[0], item[1], item[2], item[3])
        if (result != item[4]):
            print(item, result)
            break


test()
